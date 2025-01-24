#include <sc.h>
#include "Touch_Kscan_Library.h"




volatile unsigned char MainTime;
volatile bit	B_MainLoop,B_OnOff;

//系统初始化
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;				//禁止中断
	OSCCON = 0X70;			//配置振荡为8M
	OPTION_REG = 0;
	
	
	//延时等待电源电压稳定
	//DelayXms(200);
	TRISA = 0;
	PORTA = 0;
	TRISB = 0;
	PORTB = 0;

	PIE1 = 2;
	PR2 = 250;				//8M下将TMR2设置为125us中断
	T2CON = 4;				//使能定时器2，预分频1:1
	
	INTCON = 0XC0;			//使能总中断，外设中断
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
				PORTB ^=0X02;
				B_OnOff = !B_OnOff;
			}
			if((KeyOldFlag&0x2) && (KeyFlag[0]&0x2))
			{
				//KEY2被按下
				PORTB ^=0X02;
				B_OnOff = 1;
			}
			if((KeyOldFlag&0x4) && (KeyFlag[0]&0x4))
			{
				//KEY3被按下
				PORTB ^=0X02;
				B_OnOff = 1;
			}
			if((KeyOldFlag&0x8) && (KeyFlag[0]&0x8))
			{
				//KEY4被按下
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
		if(++MainTime >= 32)	//设为4MS扫描一次按键
		{
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		PIR1 = 0;
		INTCON &= 0XF8;
	}
	
}

void WorkSleep()
{
#if (0 != C_KEY_WAKEUP)
	static unsigned char time;
	
	if(B_OnOff)time = 0;
	
	if(++time >= 125)
	{
		time = 0;
		INTCON = 0;			//;关断ADC模块及中断使能；
		PIE1 = 0;
		PIR1 = 0;
		T2CON = 0;
		ADCON1 = 0;

		//进入休眠前关掉所有功能模块,以降低休眠电流
		ADCON0 = 0;
		KEYCON0 = 0;
		PWMCON = 0;
	
		//进入休眠前,必须固定口线电平,这儿全部输出低电平,并关闭所有上拉电阻
		TRISA = 0;
		PORTA = 0;
		TRISB = 0;
		PORTB = 0;
				
		WPUA = 0;
		WPDA = 0;
		WPUB = 0;
		WPDB = 0;

/****如需要PB口中断唤醒，使能下列程序并按需修改****/
			//TRISB1 =1;//输入
			//WPUB1 = 1;//上拉			
			//RBIF = 0;//清标志
			//IOCB1 = 1;//允许PB1电平变化中断
			//RBIE = 1;
			//PORTB;//读一次PB口			
/************************************/	

		//进入休眠模式,触摸允许唤醒的按键后恢复正常工作
		SystemEnterSleep();
		if(RBIF)
			RBIF = 0;
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
			
			CheckTouchKey();
			
			Refurbish_Sfr();
			KeyServer();

			WorkSleep();
		}
	}
}