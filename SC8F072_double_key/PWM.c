#include "PWM.h"


void PWM_Init(void)
{
   	PWMCON1 = 0B11000000;	//PWM选择A组，死区2禁止，死区1禁止，死区时钟源为Fosc/1
	TRISA = 0B00111111;	    //选择的PA0~PA5口设为输入
	PWMTL = 0XFF;			//PWM0123的周期低8位
	PWMT4L = 0XFF;          //PWM4的周期低8位
	PWMTH = 0X00;			//00（未用）00（PWM4占空比高位）
	                        //11（PWM4周期高位） 11（PWM0123周期高位） 
							//PWM0123周期选择为3FF，则周期为（1023+1）*1/8M，
							//周期=[PWMT+1]*Tosc*(CLKDIV 分频值)=256/8M*1 周期的时钟分频在PWMCON0选择
							//PWM4周期选择为11 1111 1111(1023)  则周期为（1023+1）*1/8M，	
	PWMD0L = 0X00;			//脉冲宽度 = (PWMDx[9:0]+1)*TOSC*(CLKDIV 分频值)
							//必须注意根据公式，即使占空比设为0仍有脉冲输出，如要输出低电平
							//需要关闭PWMEN，然后设为输出低
	PWMD1L = 0X00;			//互补模式，PWM1的占空比与PWM0互补，和设置值无关
	PWMD01H = 0X00;			//xxPWM1 xxPWM2配置PWM1,PWM2的占空比，该值不能超过周期，否者为100%输出                      
	//PWM01DT = 0X03;	    //死区设为2uS，计算为（3+1）*1/8M*4
							//死区1的占空比以PWM0设置的占空比为基准
	PWMD2L = 0X00;        	//PWM2 占空比低位寄存器   该值不能超过周期，否者为100%输出
	//PWMD3L = 0X7F;			//PWM3 占空比低位寄存器 ，互补以PWM0占空比为准
	PWMD23H = 0X00;			//PWM2 和 PWM3 占空比高位寄存器 PWMD01H，该值不能超过周期，否者为100%输出
	
	PWMD4L = 0X00;			// PWM4 占空比低位寄存器,PWM4占空比高位在PWMTH的Bit4~5 
				            //11 0001 1111(779)  78%占空比
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
	PWMCON0 = 0X17;			//000 1 0111使能PWM0~PWM2 ,PWM4  分频比为1
	PWMCON2 =0X00;			//xxx0 0000 PWM4输出正常
//	TRISA = 0B00101000;	//对应的口线012，4设为输出  3,5输入
}	


/***********************************************
函数名称：Set_PWM
函数功能：设置 PWM 占空比
入口参数：channel（通道号），duty（占空比 0~100）
出口参数：无
备注：
************************************************/
void Set_PWM(unsigned char channel, unsigned char duty)
{
	unsigned short pulse_width = (unsigned short)(duty * 255) / 100;  // 占空比转换为脉宽值（256为最大值）
	switch (channel) 
	{
		case 0:
			PWMD0L = pulse_width & 0xFF;
			break;
		case 1:
			PWMD1L = pulse_width & 0xFF;
			break;
		case 2:
			PWMD2L = pulse_width & 0xFF;
			break;
		case 3:
			PWMD3L = pulse_width & 0xFF;
			break;
		case 4:
			PWMD4L = pulse_width & 0xFF;
			break;
		default:
		    break;
    }
}