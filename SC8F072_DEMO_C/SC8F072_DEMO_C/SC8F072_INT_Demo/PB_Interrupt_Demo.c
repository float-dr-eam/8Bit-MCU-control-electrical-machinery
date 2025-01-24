/*-------------------------------------------
功能：PORB电平变化中断演示
版本：V1.0
日期：2021.01.05 

*本程序由 中微半导体 &应用支持部& 编写整理
*公司网址 www.mcu.com.cn
*
-------------------------------------------*/

#include <sc.h>


void main()
{
	asm("nop");
	asm("clrwdt");
	
	OSCCON = 0x70;			//内部振荡器用作系统时钟
	OPTION_REG = 0;			//预分频寄存器设置
	TRISA = 0;
	
	PR2 = 249;					//设定Timer初始值,250uS中断
	TMR2IF = 0;
	TMR2IE = 1;					//使能Timer2溢出中断
	
	T2CON = 0B00000101;			//开启Timer2，预分频为1：4，后分频为1：1，则定时时间为（249+1）*4*（4/16M）=250us
	
//---------------------------------------	
	WPUB = 0B00001000;		//使能上拉，使RB3为高
	TRISB = 0B00001000;		//设置RB3的IO口为输入
	IOCB = 0B00001000;		//允许RB3的IO口电平变化中断
	RBIE = 1;				//使能PORTB电平变化中断
	INTCON = 0xC8;			//允许PORTB中断，屏蔽其余中断、允许外设中断，清RB中断标志位
	PORTB;					//读取PORTA并锁存
//---------------------------------------		

	while(1)			
	{
		asm("clrwdt");
	}
}


/***********************************************
函数名称：PB_Isr
函数功能：PB电平变化中断服务
入口参数：无
出口参数：无
备注：
************************************************/
void interrupt PB_Isr()
{
	if(RBIF)
	{
		RBIF = 0;			//清中断标志
		RA2 = !RA2;
		PORTB;				//读取PORTB状态,出中断的时候必须读取IO状态，
							//否则会出现检测不到电平变化的现象
	}
	if(TMR2IF)
	{
		TMR2IF = 0;
		
		PORTA ^= 0X02;
	}
}