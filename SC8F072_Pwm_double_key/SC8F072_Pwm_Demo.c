#include <sc.h>
#include <stdbool.h>
#include "LED_188.h"
#include "PWM.h"
#include "KEY.h"

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
/*#define power_iir_a0 0.000155
#define power_iir_a1 0.000310
#define power_iir_a2 0.000155
#define power_iir_b0 1
#define power_iir_b1 -1.96446
#define power_iir_b2 0.965081*/
volatile unsigned int adresult;
volatile unsigned char test_adc;
volatile unsigned int power_ad;
volatile unsigned char power_percent;
bool ADC_Flag=0;
unsigned int ADC_delay=0;
/*//保存滤波结果
unsigned char power_percent_iir = 0;
//2阶 电源滤波
unsigned char y37v[3] = {0, 0, 0};
unsigned char x37v[3] = {0, 0, 0};*/

//按键和PWM
//unsigned char debounce_counter = 0;  // 按键消抖计数器
unsigned int long_press_counter = 0; // 长按计数器
unsigned int Time_delay = 0; //显示延时
bool button_sflag = 0; // 按键状态标志
bool button_lflag = 0; // 按键状态标志

//188数码管  
bool T_flag = 0; // LED刷新标志
unsigned char hundreds = 4;	//百位，0不显示，1仅百分比，2百分比+供电，3-百分比+百位，4全部显示
unsigned char tens = 4; 		//十位，10-F，11-不显示
unsigned char unit = 2;		//个位，10-F，11-不显示      		
//LED按键
//unsigned int LED_delay=0;
unsigned int LED_Key_counter = 0; // LED计数器
bool LED_lflag = 0; // LED按键长状态标志
bool LED_sflag = 0; // LED按键短状态标志
//bool breath_TFlag = 0; 

//函数声明
void Init_System();
unsigned char ADC_Sample(unsigned char adch, unsigned char adldo);
unsigned char ADC_read(void);

/*void ADC_filter(void)
{
	if(ADC_Flag)
	{	
		for (unsigned char i=0;i<4;i++)
		{
			x37v[0] = x37v[1];
			x37v[1] = x37v[2];
			x37v[2] = ADC_read();
			y37v[0] = y37v[1];
			y37v[1] = y37v[2];
			y37v[2] = power_iir_a0 * x37v[2] + power_iir_a1 * x37v[1] + power_iir_a2 * x37v[0] - (power_iir_b1)*y37v[1] - (power_iir_b2)*y37v[0];
			power_percent_iir = y37v[2];
		}
	}
}*/
	
void main(void)            		//主函数,单片机开机后就是从这个函数开始运行
{
	Init_System();
	Led_Gpio_Init();
    PWM_Init();
    while(1)					//死循环,单片机初始化后,将一直运行这个死循环
    {
		asm("clrwdt");
        Button_response();
        asm("clrwdt");
		if(ADC_Flag)
		{
			ADC_read();
		}
		/*if(LED_lflag)
		{
			TRISA0 = 0;	  //对应的口线012输出
			TRISA1 = 0;	
			TRISA2 = 0;	
			Set_PWM(0,95);
			Set_PWM(1,95);
			Set_PWM(2,0);
		}
		if(LED_sflag)
		{
			TRISA0 = 0;	  //对应的口线012输出
			TRISA1 = 0;	
			TRISA2 = 0;	
			Set_PWM(0,95);
			Set_PWM(1,95);
			Set_PWM(2,95);
		}*/

		/*if(breath_TFlag)
		{
			breath_LED();
			delay(200);
		}*/
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
	OPTION_REG = 0B00000101;    //预分频给TMR0 ，Timer0使用内部时钟Focs/4，预分频比为1:64
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
	TMR0 = 6;					//设定Timer0初始值，计时时间为（256-6）*4*64/16M=4ms
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
	WPUA = 0B00101000;		//使能上拉，使RA5为高
	TRISA= 0B00101000;		//设置RA1的IO口为输入
	IOCA = 0B00101000;		//允许RA1的IO口电平变化中断
	RAIE = 1;				//使能PORTA电平变化中断
//	INTCON = 0xC0;			//1100允许所有未被屏蔽的中断、允许外设中断，禁止INT外部中断
	RAIF = 0;				//清中断标志
	PORTA;					//读取PORTA并锁存
    INTCON = 0xE8;			//1110 1000允许未被屏蔽的中断，允许外设中断
	                        //允许Timer0溢出,PORTB中断，清除所有中断标志位，屏蔽INT外部中断
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
	adresult = adsum >> 3;		//8次平均值作为最终结果
	adsum = 0;
	admin = 0;
	admax = 0;
	return 0xA5;
}

unsigned char ADC_read(void)
{
	test_adc = ADC_Sample(31, 0);		//测试内部基准1.2V相对电源的AD值
	if (0xA5 == test_adc)
	{
		volatile unsigned long power_temp;
		power_temp = (unsigned long)((POWER_RATIO)/adresult);//1.2*4096/AD=VDD，参数放大1000倍 
		power_ad = (unsigned int)(power_temp);//通过内部基准电压推出芯片VDD电压
		power_percent = (unsigned char)((power_ad-POWER_MIN)/POWER_SCOPE);
		if(power_percent>100)
		{
			power_percent=100;
		}
	}
	else
	{
		ADCON0 = 0;						//如果转换没有完成，需初始化ADCON0,1
		ADCON1 = 0;				
		__delay_us(100);				//延时100us(编译器内置函数)
	}
	ADC_Flag=0;	
	return power_percent;
}

void interrupt Isr_Timer() 
{
    if(RAIF)
	{	
		RAIF = 0;			//清中断标志	
		if (!(PORTA & 0x04))  // RA3 上升沿（按键松开）0000 1000
		{  
			if(LED_Key_counter > 1015 )
			{
                LED_lflag = 1;  // 标记LED长按
            }
			else if(LED_Key_counter<=1015 && LED_Key_counter>=150)
			{
				LED_sflag = 1;  // 标记LED短按
			}
            LED_Key_counter = 0;
        }
	/*	else
		{
			if(LED_Key_counter > 1015 )
			{
                LED_lflag = 1;  // 标记LED长按
            }
			else if(LED_Key_counter<=1015 && LED_Key_counter>=65)
			{
				LED_sflag = 1;  // 标记LED短按
			}
            LED_Key_counter = 0;
		}*/
		/*if(!(PORTA & 0x04))//PA3低电平
		{
			LED_delay=100;//定时器2定时521ms
		}*/
				
		if (!(PORTA & 0x20)) //PA5低电平
		{
			T_flag = 1;
			Charge_num();  //充电中
		}
		else
		{
			T_flag = 1;
			Uncharge_num();	//非充电状态
		}
	}

	if(RBIF)
	{
		RBIF = 0;			//清中断标志
		if (PORTB & 0x20)  // RB5 上升沿（按键松开）
		{  
            if (long_press_counter > 1015) 
			{  // 长按超过 1 秒
                button_lflag = 1;  // 标记长按
            } 
			else if(long_press_counter<=1015 && long_press_counter>=65)
			{
                button_sflag = 1;  // 标记短按
            }
            long_press_counter = 0;
        }
	}
	if(T0IF)//4ms
	{		
		TMR0 += 6;	//TMR0不能自动赋值，操作TMR0的时候,TIME是不计数的
		T0IF = 0;  //清中断标志
		if(T_flag)
		{
			Display();//每4ms执行一次，一个周期20ms，刷新率50
		}

		
		if(ADC_delay > 0)//每4s进行一次ADC采样
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
		
		/*if(LED_delay>1)//520ms倒计时
		{
			LED_delay--;
		}
		else if(LED_delay==1)//520ms时检测
		{
			LED_delay=0;//关闭520ms定时器
			if (!(PORTA & 0x04))  // RA3 低电平（按下）
			{
				LED_sflag = 1;  // 标记LED按键按下
			}
			else if(PORTA & 0x04)
			{
				LED_lflag = 1;  // 标记LED按键按下
			}
			
		}*/
	    // 软件消抖和按键检测
        if (!(PORTA & 0x04))  // RA3 低电平（按下）0000 1000
		{ 
			LED_Key_counter++;  // 长按计数
        } 
		
	    // 软件消抖和长按检测
        if (!(PORTB & 0x20))  // RB5 低电平（按下）
		{ 
			long_press_counter++;  // 长按计数
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


