#include <sc.h>
#include "Touch_Kscan_Library.h"

volatile unsigned char MainTime;
volatile bit	B_MainLoop;

//注意事项：
//1、SC8P8022 的 PIN2 是由 RE0、RB7 合封在一起，在触摸方案应用过程中 TRISB,7 必须设置为1，即RB7为输入状态。
//2、SC8P8022 的 PIN7 是由 RA1、RA2、RC2 合封在一起，应用过程中将未使用的2个管脚固定设置为输入状态。

//系统初始化
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;				//禁止中断
	OSCCON = 0X71;			//配置振荡为8M
	OPTION_REG = 0;
	
	//延时等待电源电压稳定
	//DelayXms(200);
	
	
	//PIE2 = 0;
	PIE1 = 2;
	PR2 = 250;				//8M下将TMR2设置为125us中断
	T2CON = 4;				//使能定时器2
	
	INTCON = 0XC0;			//使能中断
}


/**********************************************************
刷新特殊功能寄存器
**********************************************************/
void Refurbish_Sfr()
{
/*	//均为数字口
	ANSEL = 0;
	ANSELH = 0;
	
	TRISA = 0;
	TRISB = 0;
	TRISC = 0;
	TRISE = 9;
	
	LEDCON0 = 0;
	LEDCON1 = 0;
	SEGEN0 = 0;
	SEGEN1 = 0;
	SEGEN2 = 0;
	COMEN = 0;
	
	SSPCON = 0;
//	SSPCON2 = 0;
	CCP1CON = 0;
	CCP2CON = 0;
//	RCSTA = 0;
//	RCREG = 0;
//	TXSTA = 0;
	IOCB = 0;
	PSTRCON = 0;
	CM1CON0 = 0;
	CM2CON0 = 0;
	CM2CON1 = 0;
	SRCON = 0;
//	BAUDCTL = 0;
//	PWMCON0 = 0;
//	PWMCON1 = 0;
	T1CON = 0;
	EECON1 = 0;
	PIE2 = 0;
*/	
	OPTION_REG = 0;
	
	
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
	static unsigned int KeyOldFlag = 0;
	unsigned int i = (unsigned int)((KeyFlag[1]<<8) | KeyFlag[0]);
	if(i)
	{
		if(i != KeyOldFlag)
		{
			KeyOldFlag = i;
			switch(i)
			{
				case 1:
				case 2:
				case 4:
				case 8:
				default:break;
			}
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
		if(++MainTime >= 32)
		{
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		PIR1 = 0;
	//	PIR2 = 0;
	}
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
		}
	}
}