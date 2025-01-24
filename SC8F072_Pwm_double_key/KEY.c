#include "KEY.h"
#include "PWM.h"
#include "LED_188.h"
//bool breath_flag=0;
/*void delay(unsigned int ms)
{
	unsigned char i,j;
	for(i=ms;i>0;i--)
	{
		for(j=57;j>0;j--);
	}
}
void breath_LED()
{
	static unsigned char t,k;
	static unsigned char i=0;
	t=0;
	k=95;
	if(!breath_flag)
	{
		Set_PWM(i,t);

		t++;
		if(t==95)
		{
			breath_flag=1;
			t=0;
		}
	}
	else
	{
		
		Set_PWM(i,k);

		k--;
		if(k==0)
		{
			breath_flag=0;
			i++;
			k=95;
		}
	}
	if(i==3)
	{
		i=0;
	}
}*/


void Button_response(void) 
{
    if (button_sflag)   //短按唤醒
	{        
		button_sflag = 0;  // 清标志
		TRISA4 = 0;	//对应的口线4输出
		//__delay_us(100);				//延时100us(编译器内置函数)
		switch (pwm_duty)
		{
			case 0:
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 1:
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 2:
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 3:
				Set_PWM(4, duty_steps[pwm_duty]);
				break;
			case 4:
				Set_PWM(4, duty_steps[pwm_duty]);
				//TRISA4 = 1;	//对应的口线输入
				break;
			default:
				break;
		}
		Time_delay=2500;
		Motor_num();
		pwm_duty = (unsigned char)((pwm_duty + 1) % 5);  // 循环切换 5 档占空比
		T_flag=1;
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
		asm("sleep");
		//asm("stop");
		asm("nop");
		asm("nop");
		asm("clrwdt");
    }
	if(LED_sflag)
	{
		LED_sflag=0;
		TRISA0 = 0;	  //对应的口线012输出
		TRISA1 = 0;	
		TRISA2 = 0;	
		switch (LED_num)
		{
			case 0:
		    	//breath_TFlag=0;
				//TRISA2 = 1;	//对应的口线输入
				Set_PWM(0,95);
				Set_PWM(1,95);
				Set_PWM(2,0);
				break;
			case 1:
		     	//breath_TFlag=0;
				//TRISA0 = 1;	//对应的口线输入
				Set_PWM(0,0);
				Set_PWM(1,95);
				Set_PWM(2,95);
				break;
			case 2:
			    //breath_TFlag=0;
				Set_PWM(0,95);
				Set_PWM(1,0);
				Set_PWM(2,95);
				break;
			case 3:
				Set_PWM(0,95);
				Set_PWM(1,95);
				Set_PWM(2,95);
				//breath_TFlag=1;
				break;
			case 4:
			    //breath_TFlag=0;
				Set_PWM(0, 0);
				Set_PWM(1, 0);
				Set_PWM(2, 0);
				TRISA0 = 1;	//对应的口线输入
				TRISA1 = 1;	//对应的口线输入
				TRISA2 = 1;	//对应的口线输入
				break;
			default:
				break;
		}
		LED_num=(unsigned char)((LED_num+1)%5);
	}
	if (LED_lflag) //长按睡眠低功耗
	{
        LED_lflag = 0;  // 清标志
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
		asm("sleep");
		//asm("stop");
		asm("nop");
		asm("nop");
		asm("clrwdt");
    }
}


