#include <sc.h>
#include "Touch_Kscan_Library.h"




volatile unsigned char MainTime;
volatile unsigned int PwmData;
volatile bit	B_MainLoop,B_OnOff;

//系统初始化
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	OPTION_REG |= 0x07;
			
	OPTION_REG |= 0x08;
	asm("clrwdt");
			
	OPTION_REG = C_OPTION_REG_;		//预分频给看门狗，18ms*2*3=108ms
	asm("clrwdt");
	
	INTCON = 0;				//禁止中断
	OSCCON = 0X70;			//配置振荡为8M
	
	PORTA = 0;
	TRISA = 0;
	PORTA = 0X00;	
	WPUA = 0X00;
	
	PORTB = 0;
	TRISB = 0;
	PORTB = 0X00;	
	WPUB = 0X00;		//
						//
						
	PORTC = 0;
	TRISC = 0;
	PORTC = 0X00;	
	WPUC = 0X00;
	
	WPDA = 0;
	WPDB = 0;
	WPDC = 0;
	//延时等待电源电压稳定
	//DelayXms(200);
	
	TMR0 = 6;				//预分频给WDT，此时TMR0的分频比为1:1，8M下将TMR0设置为125us中断，
	INTCON = 0XC0;			//使能总中断，外设中断
	
	T2CON = 0B00000000; 	// 1分频
	PR2 = 250;				//定时125uS
	TMR2 = 0;
	TMR2ON =1;
	TMR2IE =1;				// T2 中断使能
}


/**********************************************************
函数名称：Refurbish_Sfr
函数功能：刷新一些特殊功能寄存器
入口参数：无
出口参数：无 
备    注：每隔一定时间刷新一次SFR可增强抗干扰能力
**********************************************************/
void Refurbish_Sfr()
{	
	//刷新中断相关控制寄存器
	INTCON = 0XC0;
	PIE1 = 2;
	PR2 = 250;
	INTCON = 0XC0;
	if(4 != T2CON)
		T2CON = 4;
}


/***********************************************************
键处理函数
***********************************************************/
void KeyServer()
{
	static unsigned char KeyOldFlag = 0;
	if(KeyFlag[0])
	{
		if(KeyFlag[0] != KeyOldFlag)
		{
			//确定状态改变的按键
			KeyOldFlag ^= KeyFlag[0];
			if((KeyOldFlag&0x1) && (KeyFlag[0]&0x1))
			{
				//KEY1被按下
				B_OnOff = !B_OnOff;
				PORTB ^= 0X10;
			}
			if((KeyOldFlag&0x2) && (KeyFlag[0]&0x2))
			{
				//KEY2被按下
				PORTB ^= 0X08;
				B_OnOff = 1;
			}
			if((KeyOldFlag&0x4) && (KeyFlag[0]&0x4))
			{
				//KEY3被按下
				PORTB ^= 0X04;
				B_OnOff = 1;
				
			}
			if((KeyOldFlag&0x8) && (KeyFlag[0]&0x8))
			{
				//KEY4被按下
				PORTB ^= 0X20;
				B_OnOff = 1;
			}
			
			KeyOldFlag = KeyFlag[0];
		}
	}
	else
	{
		KeyOldFlag = 0;
	}
}

/***********************************************************
中断服务函数
***********************************************************/
void interrupt Isr_Timer()
{
	if(TMR2IF)				//若只使能了一个中断源,可以略去判断
	{
		TMR2IF = 0;
		if(++MainTime >= 32)		//4ms进一次主循环
		{
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		INTCON = 0XC0;
		PIR1 = 0;
	}
	
}

/***********************************************************
休眠函数
***********************************************************/
void WorkSleep()
{
#if (0 != C_KEY_WAKEUP)
	static unsigned char time;
	
	if(B_OnOff)	
		time = 0;
	
	if(++time >= 250)
	{
		time = 0;
		INTCON = 0;			//;关断ADC模块及中断使能；
		PIE1 = 0;
		PIE2 = 0;
		PIR1 = 0;
		PIR2 = 0;
		T2CON = 0;
		PWMCON0 = 0;
	//	KEYCON0 = 0;
		//进入休眠前,必须固定口线电平,这儿全部输出低电平,并关闭所有上拉电阻
		TRISA = 0;
		PORTA = 0;
		TRISB = 0;
		PORTB = 0;
		TRISC = 0;
		PORTC = 0;
		WPUA = 0;
		WPUB = 0;

/****如需要PB口中断唤醒，使能下列程序并按需修改****/
		//	RBIE = 1;//使能PB上拉
		//	TRISB2 =1;//输入
		//	WPUB2 = 1;//上拉			
		//	IOCB2 = 1;//允许PB1电平变化中断
		//	RBIF = 0;//清标志
		//	PORTB;//读一次PB口			
/************************************/	

		//进入休眠模式,触摸允许唤醒的按键后恢复正常工作
		SystemEnterSleep();
		if(RBIF) RBIF = 0;
		//休眠被唤醒,重新配置中断等SFR,使系统进入正常工作
		Refurbish_Sfr();
	}
#endif
}

/***********************************************************
主循环
***********************************************************/
void main()
{
	Init_System();
	while(1)
	{
		if(B_MainLoop)
		{
			B_MainLoop = 0;
			CLRWDT();
							
			Refurbish_Sfr();
			
			CheckTouchKey();
			KeyServer();
			WorkSleep();
		}
	}
}