#include <sc.h>
#include "CheckTouchKey.h"		

volatile unsigned char MainTime;
volatile bit	B_MainLoop;

//系统初始化
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;				//禁止中断
	OSCCON = 0x72;
	OPTION_REG = 0;		//将分频器赋给TMR0
	
	INTCON = 0;
	TRISB = 0;
	PORTB = 0;
	
	PIR1 = 0;
	PIE1 = 0;
	PIR2 = 0;
	PIE2 = 0;
	
	/*初始化定时器2, 125us中断*/
	PR2 = 250;
	T2CON = 4;
	TMR2IE = 1;
	
	INTCON = 0XC0;
}


/**********************************************************
刷新特殊功能寄存器
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
		
			CLRWDT();
		Refurbish_Sfr();	//唤醒后刷新专用寄存器
		CheckTouchKey();	//触摸检测	
		
	}
}