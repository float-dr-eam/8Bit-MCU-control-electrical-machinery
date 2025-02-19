/*-------------------------------------------
功能：INT外部中断演示
版本：V1.0
日期：2023.09.05 

*本程序由 中微半导体 &应用支持部& 编写整理
*公司网址 www.mcu.com.cn

-------------------------------------------*/

#include <sc.h>


void main()
{
	asm("nop");
	asm("clrwdt");
	
	OSCCON = 0x70;			//内部振荡器用作系统时钟
	OPTION_REG = 0;			//预分频寄存器设置，bit6为触发中断的边沿选择位		
	
	PR2 = 249;				//设定Timer初始值,500uS中断
	TMR2IF = 0;
	TMR2IE = 1;				//使能Timer2溢出中断
	
	T2CON = 0B00000101;		//开启Timer2，预分频为1：4，后分频为1：1，则定时时间为（249+1）*4*（4/8M）=500us
	
//---------------------------------------	
	WPUA = 0B00100001;		//使能上拉，使RA0为高
	TRISA = 0B00100001;		//设置RA0的IO口为输入
	INTEDG = 0;				//INT引脚下降沿触发,该设置位在OPTION，注意修改OPTION不要改变这个设置位
							//INTEDG = 1为INT引脚上升沿触发
	INTCON = 0xD0;			//允许所有未被屏蔽的中断，允许外设中断，使能INT外部中断
//---------------------------------------		

	while(1)			
	{
		asm("clrwdt");
		
	}
}


/***********************************************
函数名称：INT_Isr
函数功能：INT中断服务
入口参数：无
出口参数：无
备注：
************************************************/
void interrupt INT_Isr()
{
	if(INTF)
	{
		INTF = 0;			//清中断标志
		RA2 = !RA2;
	}
	if(TMR2IF)
	{
		TMR2IF = 0;
		
		PORTA ^= 0X02;
	}
}