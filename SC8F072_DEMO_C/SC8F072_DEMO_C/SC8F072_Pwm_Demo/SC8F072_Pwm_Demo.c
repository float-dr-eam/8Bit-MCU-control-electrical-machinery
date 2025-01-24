
//CCP1 PWM模式参考程序
#include <SC8f072.h>           		
//调用单片机的头文件
void Init_System();

	
void main(void)            		//主函数,单片机开机后就是从这个函数开始运行
{
	unsigned int delaycnt = 0;
	unsigned char pwmbuf = 0X1F;

	Init_System();
	
								//以下是对PWM功能初始化
		/************PWMCON1定义**************************
		Bit7~6 PWMIO_SEL[1:0]: PWM IO选择。
			11= PWM分配在A组，PWM0-RA0,PWM1-RA1,PWM2-RA2,PWM3-RA3,PWM4-RA4
			10= PWM分配在B组，PWM0-RA0,PWM1-RA1,PWM2-RA2,PWM3-RB2,PWM4-RB1
			01= PWM分配在C组，PWM0-RA5,PWM1-RB7,PWM2-RB6,PWM3-RB5,PWM4-RB4
			00= PWM分配在D组，PWM0-RB0,PWM1-RB1,PWM2-RB3,PWM3-RB4,PWM4-RB2
		Bit5 PWM2DTEN: PWM2死区使能位。
			1= 使能PWM2死区功能，PWM2和PWM3组成一对互补输出。
			0= 禁止PWM2死区功能。
		Bit4 PWM0DTEN: PWM0死区使能位。
			1= 使能PWM0死区功能，PWM0和PWM1组成一对互补输出。
			0= 禁止PWM0死区功能。
		Bit3~Bit2 未用。
		Bit1~Bit0 DT_DIV[1:0] 死区时钟源分频。
			11= FOSC/8
			10= FOSC/4
			01= FOSC/2
			00= FOSC/1
	**********************************************************************/
		PWMCON1 = 0B11010010;	//PWM选择A组，死区2禁止，死区1使能，死区时钟源为Fosc/4
		
		TRISA	= 0B00011111;	//选择的PA0~PA4口设为输入
		PWMTL = 0XFF;			//PWM 周期=[PWMT+1]*Tosc*(CLKDIV 分频值)
		PWMT4L = 0XFF;
		PWMTH = 0X0C;			//周期选择为0FF，则周期为（255+1）*1/8M，周期的时钟分频在PWMCON0选择
								//PWM4周期选择为03FF
		
		PWMD0L = 0X1F;			//脉冲宽度 = (PWMDx[9:0]+1)*TOSC*(CLKDIV 分频值)
								//必须注意根据公式，即使占空比设为0仍有脉冲输出，如要输出低电平
								//需要关闭PWMEN，然后设为输出低
		PWMD1L = 0X7F;			//互补模式，PWM1的占空比与PWM0互补，和设置值无关
		PWMD01H = 0;			//配置PWM1,PWM2的占空比，该值不能超过周期，否者为100%输出
		
		PWM01DT = 0X03;			//死区设为2uS，计算为（3+1）*1/8M*4
								//死区1的占空比以PWM0设置的占空比为基准
		
		PWMD2L = 0X3F;        	//PWM2 占空比低位寄存器   该值不能超过周期，否者为100%输出
		PWMD3L = 0X7F;			//PWM3 占空比低位寄存器 ，互补以PWM0占空比为准
		PWMD23H = 0;			//PWM2 和 PWM3 占空比高位寄存器 PWMD01H，该值不能超过周期，否者为100%输出
		
		PWMD4L = 0X1F;			//PWM4 占空比低位寄存器,PWM4占空比高位在PWMTH的Bit4~5 
				
	/***************PWMCON0*************************************
		Bit7~Bit5 CLKDIV[2:0]: PWM时钟分频。
			111= FOSC/128
			110= FOSC/64
			101= FOSC/32
			100= FOSC/16
			011= FOSC/8
			010= FOSC/4
			001= FOSC/2
			000= FOSC/1
		Bit4~Bit0 PWMxEN: PWMx使能位。
			1= 使能PWMx。
			0= 禁止PWMx。
	******************************************************************/
		PWMCON0 = 0X1F;			//打开PWM0~PWM4,分频比为1
		PWMCON2 =0X10;			//PWM4输出反向
		TRISA = 0;				//对应的口线设为输出
		
    while(1)					//死循环,单片机初始化后,将一直运行这个死循环
    {
		asm("clrwdt");
		if(++delaycnt > 5000)	//延时20000个软件周期，非精确定时
   		{
   			delaycnt = 0;       //清零以备下次重新计数
   			if(++pwmbuf > 0xfe)	//占空比加一
   			{
   				pwmbuf = 0x01f;
   			}
			PWMD0L = pwmbuf;	//写入占空比
   		}
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
	OSCCON = 0X72;				//配置振荡为8M
	OPTION_REG = 0;
	asm("clrwdt");
	
	TRISA = 0B00011111;			//初始化IO状态
	TRISB = 0B00000000;

	PORTA = 0B00000000;
	PORTB = 0B00000000;			//初始化输出

}