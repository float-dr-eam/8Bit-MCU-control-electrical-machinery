/*-------------------------------------------

程序名称：Timer2定时中断程序
日期版本：2023/06/14 <V1.0>

备注：   

*本程序由 &应用支持部& 编写整理
-------------------------------------------*/


#include <sc.h>				//芯片头文件，会根据工程选项自动寻找对应型号头文件

void Init_System();

void main()
{
	Init_System();
	while(1)			
	{
		asm("clrwdt");
	}
}


/***********************************************
函数名称：Timer_Isr
函数功能：中断服务
入口参数：无
出口参数：无
备注：
************************************************/
void interrupt Timer_Isr()
{
	if(TMR2IF)
	{
		TMR2IF = 0;	//清中断标志位
		PORTB ^= 0X01;
	}
}

/***********************************************
函数名称：Init_System
函数功能：系统初始化
入口参数：无
出口参数：无
备注：
************************************************/
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;					//系统初始化
	OSCCON = 0x72;				//16MHZ,内部振荡器用作系统时钟,CONFIG关闭WDT时必需软件打开WDT
	OPTION_REG = 0x00;			//配置TIMER0时间，00为2分频
	asm("clrwdt");
	
    WPUB = 0B00111000;			//初始化上拉
 	WPDB = 0B00000000;			//初始化下拉
	TRISB = 0B00111000;			//初始化IO状态
	PORTB = 0B00000000;			//初始化输出
	
	
	/**********  T2CON  *****************************************
		Bit7      CLK_SEL:  时钟源选择
			1=  选择外部 FLSE /4 作为 TMR2 时钟源（休眠态可继续计数）
			0=  选择内部 FSYS /4 作为 TMR2 时钟源
		Bit6~Bit3 TOUTPS<3:0>: TIMER2输出后分频比选择位。 
			0000= 1:1后分频比； 
			0001= 1:2后分频比； 
			0010= 1:3后分频比； 
			0011= 1:4后分频比； 
			0100= 1:5后分频比； 
			0101= 1:6后分频比； 
			0110= 1:7后分频比； 
			0111= 1:8后分频比； 
			1000= 1:9后分频比； 
			1001= 1:10后分频比； 
			1010= 1:11后分频比； 
			1011= 1:12后分频比； 
			1100= 1:13后分频比； 
			1101= 1:14后分频比； 
			1110= 1:15后分频比； 
			1111= 1:16后分频比。 
		Bit2 TMR2ON: TIMER2使能位； 
			1= 使能TIMER2； 
			0= 禁止TIMER2。
		Bit1~Bit0 T2CKPS<1:0>: TIMER2时钟预分频比选择位； 
			00= 预分频值为1； 
			01= 预分频值为4； 
			1x= 预分频值为16。  
	****************************************************************/
	PR2 = 249;					//设定Timer初始值，定时周期是250*4/16M=62.5uS
	TMR2IF = 0;
	TMR2IE = 1;					//使能Timer2溢出中断

	T2CON = 0B00000101;			//开启Timer2，预分频为1：4，后分频为1：1，则定时时间为（249+1）*4*（4/16M）=250us
								//timer2的时钟源为OSCCON配置的系统时钟/4
	INTCON = 0XC0;				//开启总中断及外设中断

}
