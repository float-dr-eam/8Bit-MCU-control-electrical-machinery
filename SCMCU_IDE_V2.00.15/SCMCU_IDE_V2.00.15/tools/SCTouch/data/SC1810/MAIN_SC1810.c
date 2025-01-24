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
	
	PORTB = 0;
	TRISB = 0;
	PORTB = 0X10;	
	WPUB = 0X10;		//PORTB.4如果要输出高电平必须打开上拉电阻
						//输出低的时候记得关闭上拉，否则会增加休眠电流
	WPDB = 0;
	//延时等待电源电压稳定
	//DelayXms(200);
	
	TMR0 = 6;				//预分频给WDT，此时TMR0的分频比为1:1，8M下将TMR0设置为125us中断，
	INTCON = 0XA0;			//使能中断
	
	PwmData = 0xF0;			//占空比（CCPRXL:PWMXB(1,0))/（PR2+1)*4
	PR2 =0XFF;				//pwm周期T=（PR2+1)*4*(TMR2预分频）/Fosc,此处T=128uS;
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
	INTCON = 0XA0;
	TRISB = 0;
	WPUB = 0X10;
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
				PORTB ^= 0X10;
				B_OnOff = 1;
			}
			if((KeyOldFlag&0x4) && (KeyFlag[0]&0x4))
			{
				//KEY3被按下
				B_OnOff = 1;
				PwmData = PwmData+0X10; 
				PwmData &= 0x03ff;
				unsigned char Temp=0x40;	//打开PWM2
	
				if(PwmData&0x01)
				Temp |=0x10;
				if(PwmData&0x02)
				Temp |=0x20;
				CCPCON = Temp;		//占空比的低2Bit在 <.1.0>
				Temp = (PwmData>>2);	//高8位
				CCPR2L = Temp;		//
				TMR2IF = 0;              	//清零PIR1寄存器中的TMR2IF中断标志位
				T2CON &= 0X04;             	//定时器TMR2设置1:1预分频比
				TMR2ON = 1;              	//T2CON寄存器中的TMR2ON位置1使能Timer2
				TRISB4 = 0;					//清零TRISC2位，使能CCP1引脚输出驱动器
				
			}
			if((KeyOldFlag&0x8) && (KeyFlag[0]&0x8))
			{
				//KEY4被按下
				PORTB ^= 0X10;
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
	if(T0IF)				//若只使能了一个中断源,可以略去判断
	{
		TMR0 += 6;
		T0IF = 0;
		if(++MainTime >= 32)		//4ms进一次主循环
		{
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		INTCON = 0XA0;
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
		PIR1 = 0;
		T2CON = 0;
		CCPCON = 0;
		KEYCON0 = 0;
		//进入休眠前,必须固定口线电平,这儿全部输出低电平,并关闭所有上拉电阻
		TRISB = 0;
		PORTB = 0;
		WPUB = 0;

/****如需要PB口中断唤醒，使能下列程序并按需修改****/
			//RBPU = 0;//使能PB上拉
			//TRISB1 =1;//输入
			//WPUB1 = 1;//上拉			
			//RBIF = 0;//清标志
			//IOCB1 = 1;//允许PB1电平变化中断
			//PORTB;//读一次PB口			
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