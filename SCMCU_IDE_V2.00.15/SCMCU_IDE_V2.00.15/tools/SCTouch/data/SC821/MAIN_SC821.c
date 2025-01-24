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
	OSCCON = 0X72;			//配置振荡为16M
	OPTION_REG = 0;
	
	
	//延时等待电源电压稳定
	//DelayXms(200);
	TRISB = 0;
	PORTB = 0;	

	PIE1 = 2;
	PR2 = 250;				//16M下将TMR2设置为125us中断
	T2CON = 4;				//使能定时器2

	INTCON = 0XC0;			//使能中断
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
	if (4 != T2CON)
		T2CON = 4;
}


/***********************************************************
键处理函数
***********************************************************/
void KeyServer() 
{
	static unsigned char KeyOldFlag = 0;
	if (KeyFlag[0]) 
	{
		if (KeyFlag[0] != KeyOldFlag) 
		{
			//确定状态改变的按键
			KeyOldFlag ^= KeyFlag[0];
			if ((KeyOldFlag & 0x1) && (KeyFlag[0] & 0x1)) 
			{
				//KEY1被按下
				PORTB ^= 0x08;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x2) && (KeyFlag[0] & 0x2)) 
			{
				//KEY2被按下
				PORTB ^= 0x08;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x4) && (KeyFlag[0] & 0x4)) 
			{
				//KEY3被按下
				PORTB ^= 0x08;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x8) && (KeyFlag[0] & 0x8)) 
			{
				//KEY4被按下
				PORTB ^= 0x08;
				B_OnOff = !B_OnOff;
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
		if(++MainTime >= 32)	//需根据你选择的触摸路数和触摸电容选择扫描一次按键的时间
		{						//可根据测量CAP口的电容充电时间判断扫描一次需要的时间
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		PIR1 = 0;
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
		INTCON = 0;			//;关断中断使能；
		PIE1 = 0;
		PIE2 = 0;
		PIR1 = 0;
		PIR2 = 0;
		T2CON = 0;
	
		//进入休眠前,必须固定口线电平,这儿全部输出低电平,并关闭所有上拉电阻

		TRISB = 0;
		PORTB = 0;


/****如需要PB口中断唤醒，使能下列程序并按需修改****
			TRISB0 =1;	//输入
			WPUB0 = 1;	//上拉			
			RBIF = 0;	//清标志
			RBIE = 1;	//允许PB口电平变化中断
			
			PORTB;		//读一次PB口			
************************************/	

		//进入休眠模式,触摸允许唤醒的按键后恢复正常工作
		SystemEnterSleep();
		if(RBIF) 
		{
			RBIF = 0;
			PORTB;
		}
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

			WorkSleep();		//如不需省电模式，可屏蔽这个子函数
		}
	}
}