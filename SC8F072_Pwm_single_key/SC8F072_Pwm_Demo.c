#include <sc.h>
#include <stdbool.h>
#include "LED_188.h"

#pragma warning disable 752
#pragma warning disable 373			//屏蔽掉编译的1个警告


#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000			//16MHz,使用内置延时函数必须定义主频，
									//如用FCPU_DIV选择2T，则定时赋值减半
#endif

#define  POWER_RATIO  	(4096UL*1.2*1000)
#define  POWER_MIN  	(1000UL*2.8)
#define  POWER_SCOPE  	(10UL*1.4)  //4.2-2.8

// 全局变量
//ADC
volatile unsigned int adresult;
volatile unsigned char test_adc;
volatile unsigned int power_ad;
volatile unsigned char power_percent;
volatile bool ADC_Flag=0;
volatile unsigned int ADC_delay=0;
static unsigned int adc_last = 0;
//按键和PWM
volatile unsigned char pwm_duty = 0;       // 当前 PWM 占空比索引（5 档）
//volatile unsigned int Key_delay=0;
volatile unsigned char debounce_counter = 0;  // 按键消抖计数器
volatile unsigned int long_press_counter = 0; // 长按计数器
volatile unsigned int Time_delay = 0; //显示延时
volatile bool button_sflag = 0; // 按键状态标志
volatile bool button_lflag = 0; // 按键状态标志
const unsigned char duty_steps[6] = {66, 73, 85, 91, 95,0};
//188数码管  
volatile bool T_flag = 0; // LED刷新标志
volatile unsigned char hundreds = 4;	//百位，0不显示，1仅百分比，2百分比+供电，3-百分比+百位，4全部显示
volatile unsigned char tens = 4; 		//十位，10-F，11-不显示
volatile unsigned char unit = 2;		//个位，10-F，11-不显示      		


//函数声明
void Init_System();
void PWM_Init();
void Set_PWM(unsigned char channel, unsigned char duty);
void Button_response() ;
unsigned char ADC_Sample(unsigned char adch, unsigned char adldo);
void ADC_read();

	
void main(void)            		//主函数,单片机开机后就是从这个函数开始运行
{

    
	Init_System();
	Led_Gpio_Init();
    PWM_Init();
    while(1)					//死循环,单片机初始化后,将一直运行这个死循环
    {
		asm("clrwdt");
        Button_response();
		if(ADC_Flag)
		{
			ADC_read();
		}
        asm("clrwdt");
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
	OSCCON = 0X72;		//0111	0010	//配置振荡为16MHZ,内部振荡器用作系统时钟,CONFIG关闭WDT时必需软件打开WDT
	OPTION_REG = 0B00000100;    //预分频给TMR0 ，Timer0使用内部时钟Focs/4，预分频比为1:32
	asm("clrwdt");
//IO口初始化	
    WPUA  = 0B00000000;		   //配置上拉，1为使能上拉
	WPUB  = 0B00000000;
	WPDA =  0B00000000;
	WPDB =  0B00000000;
	TRISA = 0B00000000;		   //初始化输出
	TRISB = 0B00000000;
	PORTA = 0B00000000;        //初始化IO状态
	PORTB = 0B00000000;	
//定时器0
	TMR0 = 6;					//设定Timer0初始值，计时时间为（256-6）*4*32/16M=2ms
	T0IF = 0;                   //Timer0标志位
	T0IE = 1;					//使能Timer0溢出中断
	GIE = 1;					//开启总中断

//定时器2
    PR2 = 249;					//设定Timer2周期,1000uS中断
	TMR2IF = 0;                 //Timer2标志位
	TMR2IE = 1;					//使能Timer2溢出中断
	T2CON = 0B00000111;			//开启Timer2，预分频为1：16，后分频为1：1，则定时时间为（249+1）*16*（4/16M）=1000us
	
//PB5的按键中断	
//---------------------------------------	
	WPUB = 0B00100000;		//使能上拉，使RB5为高
	TRISB= 0B00100000;		//设置RB5的IO口为输入
	IOCB = 0B00100000;		//允许RB5的IO口电平变化中断
	RBIE = 1;				//使能PORTB电平变化中断
	
	PORTB;					//读取PORTB并锁存
//---------------------------------------		
//PA5充电状态中断
	WPUA = 0B00100000;		//使能上拉，使RA5为高
	TRISA= 0B00100000;		//设置RA1的IO口为输入
	IOCA = 0B00100000;		//允许RA1的IO口电平变化中断
	RAIE = 1;				//使能PORTA电平变化中断
//	INTCON = 0xC0;			//1100允许所有未被屏蔽的中断、允许外设中断，禁止INT外部中断
	RAIF = 0;				//清中断标志
	PORTA;					//读取PORTA并锁存
    INTCON = 0xE8;			//1110 1000允许未被屏蔽的中断，允许外设中断
	                        //允许Timer0溢出,PORTB中断，清除所有中断标志位，屏蔽INT外部中断
}

void PWM_Init()
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
	unsigned char pulse_width = (unsigned char)((duty * 255) / 100);  // 占空比转换为脉宽值（256为最大值）
	switch (channel) 
	{
		case 0:
			PWMD0L = pulse_width & 0xFF;
			//PWMD01H = (PWMD01H & 0xF0) | ((pulse_width >> 8) & 0x03);
			break;
		case 1:
			PWMD1L = pulse_width & 0xFF;
			//PWMD01H = (PWMD01H & 0x0F) | ((pulse_width >> 4) & 0x30);
			break;
		case 2:
			PWMD2L = pulse_width & 0xFF;
			//PWMD23H = (PWMD01H & 0xF0) | ((pulse_width >> 8) & 0x03);
			break;
		case 3:
			PWMD3L = pulse_width & 0xFF;
			//PWMD23H = (PWMD23H & 0x0F) | ((pulse_width >> 4) & 0x30);
			break;
		case 4:
			PWMD4L = pulse_width & 0xFF;
			//PWMTH = (PWMTH & 0x0F) | ((pulse_width >> 4) & 0x30);
			break;
		default:
		    break;
    }
}

/**********************************************************
函数名称：AD_Sample
函数功能：AD检测
入口参数：adch - 检测通道
出口参数：无
备    注：采样通道需自行设置为输入口
	      采样10次,取中间八次的平均值为采样结果存于adresult中

	      adch 为输入AD通道 0-15，31
             31  检测内部1.2V
	
 		  adldo =5,开启内部LDO 2V 作为ADC 参考
 		  adldo =6,开启内部LDO 2.4V 作为ADC 参考
		  adldo =7,开启内部LDO 3V 作为ADC 参考
 		  adldo =0,VDD 作为ADC 参考
 		  AD转换结果左对齐
 		  ADC参考电压从VDD切换到LDO时需要延时100us以上，才能进行AD转换
**********************************************************/
unsigned char ADC_Sample(unsigned char adch, unsigned char adldo) 
{
	
	volatile unsigned long adsum = 0;
	volatile unsigned int admin = 0, admax = 0;
	volatile unsigned int ad_temp = 0;

	if ((!LDO_EN) && (adldo & 0x04) ) 
	{
								//如果AD参考从VDD换到内部LDO，需要延时100US以上
		ADCON1 = adldo;			//左对齐,AD值取12位
		__delay_us(100);		//IDE内置延时函数，延时100us
	} 
	else
		ADCON1 = adldo;			//如果ADCON1.7(ADFM)=1为右对齐，,AD值取10位
	if(adch & 0x10) //如果为31检测内部1.2V
	{
		CHS4 = 1;
		adch &= 0x0f;
	}
	unsigned char i = 0;
	for (i = 0; i < 10; i++) 
	{
		ADCON0 = (unsigned char)(0X41 | (adch << 2));	//16分频，如果主频为16M，则必须选16分频或以上
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");				//选择通道后需延时1uS以上
		GODONE = 1;				//开始转换
		unsigned char j = 0;
		while (GODONE) 
		{
			__delay_us(2);		//延时2us(编译器内置函数)
			if (0 == (--j))		//延时0.5ms仍没有AD转换结束，跳出程序
			return 0;
		}

		ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));	//计算12位AD值

		if (0 == admax) 
		{
			admax = ad_temp;
			admin = ad_temp;
		} 
		else if (ad_temp > admax)admax = ad_temp;	//AD采样最大值
						
		else if (ad_temp < admin)admin = ad_temp;   //AD采样最小值
		adsum += ad_temp;
	}
	adsum -= admax;
	if (adsum >= admin)
		adsum -= admin;
	else
		adsum = 0;
	/*adresult = adsum >> 3;		//8次平均值作为最终结果*/
	if (adc_last)
	{
		adresult = adsum>>3;
		adresult = (int)(0.3*adresult + 0.7*adc_last);
		adc_last = adresult;
	} else
	{
		adresult = adsum>>3;
		adc_last = adresult;
	}
	adsum = 0;
	admin = 0;
	admax = 0;
	return 0xA5;
}

void ADC_read()
{
	test_adc = ADC_Sample(31, 0);		//测试内部基准1.2V相对电源的AD值
	if (0xA5 == test_adc)
	{
		volatile unsigned long power_temp;
		power_temp = (unsigned long)((POWER_RATIO)/adresult);//1.2*4096/AD=VDD，参数放大1000倍 
		power_ad = (unsigned int)(power_temp);//通过内部基准电压推出芯片VDD电压
		power_percent = (unsigned char)((power_ad-POWER_MIN)/POWER_SCOPE);
	}
	else
	{
		ADCON0 = 0;						//如果转换没有完成，需初始化ADCON0,1
		ADCON1 = 0;				
		__delay_us(100);				//延时100us(编译器内置函数)
	}
	ADC_Flag=0;	
}
void Button_response() 
{
    if (button_sflag)   //短按唤醒
	{
		TRISA = 0B00101000;	//对应的口线012，4输出
		__delay_us(100);				//延时100us(编译器内置函数)
        button_sflag = 0;  // 清标志
		switch (pwm_duty)
		{
			case 0:
				Set_PWM(0, duty_steps[pwm_duty]);
				Set_PWM(1, duty_steps[5]);
				Set_PWM(2, duty_steps[5]);
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 1:
				Set_PWM(0, duty_steps[pwm_duty]);
				Set_PWM(1, duty_steps[pwm_duty]);
				Set_PWM(2, duty_steps[5]);
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 2:
				Set_PWM(0, duty_steps[pwm_duty]);
				Set_PWM(1, duty_steps[5]);
				Set_PWM(2, duty_steps[pwm_duty]);
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 3:
				Set_PWM(0, duty_steps[5]);
				Set_PWM(1, duty_steps[pwm_duty]);
				Set_PWM(2, duty_steps[pwm_duty]);
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 4:
				Set_PWM(0, duty_steps[pwm_duty]);
				Set_PWM(1, duty_steps[pwm_duty]);
				Set_PWM(2, duty_steps[pwm_duty]);
				Set_PWM(4, duty_steps[pwm_duty]);
				/*Set_PWM(0, duty_steps[5]);
				Set_PWM(1, duty_steps[5]);
				Set_PWM(2, duty_steps[5]);
				Set_PWM(4, duty_steps[5]);
				TRISA = 0B00111111;	//对应的口线012，4输入*/
				break;
			default:
				break;
		}
		Time_delay=2500;
		Motor_num();
		pwm_duty = (pwm_duty + 1) % 5;  // 循环切换 5 档占空比
		T_flag=1;//数码管刷新标志位
		
    }
	if (button_lflag) //长按睡眠低功耗
	{
        button_lflag = 0;  // 清标志
		Set_PWM(0, duty_steps[5]);
		Set_PWM(1, duty_steps[5]);
		Set_PWM(2, duty_steps[5]);
		Set_PWM(4, duty_steps[5]);
		pwm_duty =0;
		TRISA = 0B00111111;	//对应的口线输入
		TRISB = 0B00111111;	//对应的口线输入
		T_flag=0;
		//Set_AllPin_INPUT();
		asm("clrwdt");
		asm("stop");
		asm("nop");
		asm("nop");
    }
}


void interrupt Isr_Timer() 
{
	if(RAIF)
	{
		T_flag=1;
		if (!(PORTA & 0x20)) 
		{
			Charge_num();  //充电中
		}
		else
		{
			Uncharge_num();	//非充电状态
		}
		RAIF = 0;			//清中断标志
	}
	if(RBIF)
	{
		/*if (!(PORTB & 0x20))  // RB5（按键按下）
		{  
            Key_delay=501;  //开始500ms定时器
        }*/
		if (PORTB & 0x20)  // RB5 上升沿（按键松开）
		{  
            if (long_press_counter >= 1000) 
			{  // 长按超过 1 秒
                button_lflag = 1;  // 标记长按
            } 
			else if(long_press_counter<=1000 && long_press_counter>=50)
			{
                button_sflag = 1;  // 标记短按
            }
            long_press_counter = 0;
        }
		RBIF = 0;			//清中断标志
	}
	if(T0IF)
	{
		if(T_flag)
		{
			Display();//每2ms执行一次，一个周期10ms，刷新率100
		}
		TMR0 += 6;	//TMR0不能自动赋值，操作TMR0的时候,TIME是不计数的
		T0IF = 0;  //清中断标志
		
		if(ADC_delay > 0)//每2s进行一次ADC采样
		{
             ADC_delay--; 
		}
		else
		{
			ADC_delay=1000;
			ADC_Flag=1;
		}
	}
	if(TMR2IF)//1ms
	{
		TMR2IF = 0;
		/*if(Key_delay>1)//500ms倒计时
		{
			Key_delay--;
		}
		else if(Key_delay==1)//500ms时检测
		{
			Key_delay=0;//关闭500ms定时器
			if (!(PORTB & 0x20))  // RB5 低电平（按下）
			{
				button_lflag = 1;  // 标记长按
			}
			else
			{
				button_sflag = 1;  // 标记短按
			}
		}*/
		
	    // 软件消抖和长按检测
       if (!(PORTB & 0x20))  // RB5 低电平（按下）
		{ 
			if (debounce_counter < 15) debounce_counter++;
            if (debounce_counter == 15) long_press_counter++;  // 长按计数
        } 
		else 
		{
            debounce_counter = 0;  // 按键松开，清消抖计数
        }
		 
		
		if(Time_delay > 0)//短按后延时更新ADC数值
		{
             Time_delay--;
		}
		else
		{
			if (!(PORTA & 0x20)) 
			{
				Charge_num();  //充电中
			}
			else
			{
				Uncharge_num();	//非充电状态
			}
		}
	}
}



