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
    if (button_sflag)   //�̰�����
	{        
		button_sflag = 0;  // ���־
		TRISA4 = 0;	//��Ӧ�Ŀ���4���
		//__delay_us(100);				//��ʱ100us(���������ú���)
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
				//TRISA4 = 1;	//��Ӧ�Ŀ�������
				break;
			default:
				break;
		}
		Time_delay=2500;
		Motor_num();
		pwm_duty = (unsigned char)((pwm_duty + 1) % 5);  // ѭ���л� 5 ��ռ�ձ�
		T_flag=1;
    }
	if (button_lflag) //����˯�ߵ͹���
	{
        button_lflag = 0;  // ���־
		Set_PWM(0, duty_steps[5]);
		Set_PWM(1, duty_steps[5]);
		Set_PWM(2, duty_steps[5]);
		Set_PWM(4, duty_steps[5]);
		pwm_duty =0;
		TRISA = 0B00111111;	//��Ӧ�Ŀ�������
		TRISB = 0B00111111;	//��Ӧ�Ŀ�������
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
		TRISA0 = 0;	  //��Ӧ�Ŀ���012���
		TRISA1 = 0;	
		TRISA2 = 0;	
		switch (LED_num)
		{
			case 0:
		    	//breath_TFlag=0;
				//TRISA2 = 1;	//��Ӧ�Ŀ�������
				Set_PWM(0,95);
				Set_PWM(1,95);
				Set_PWM(2,0);
				break;
			case 1:
		     	//breath_TFlag=0;
				//TRISA0 = 1;	//��Ӧ�Ŀ�������
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
				TRISA0 = 1;	//��Ӧ�Ŀ�������
				TRISA1 = 1;	//��Ӧ�Ŀ�������
				TRISA2 = 1;	//��Ӧ�Ŀ�������
				break;
			default:
				break;
		}
		LED_num=(unsigned char)((LED_num+1)%5);
	}
	if (LED_lflag) //����˯�ߵ͹���
	{
        LED_lflag = 0;  // ���־
		Set_PWM(0, duty_steps[5]);
		Set_PWM(1, duty_steps[5]);
		Set_PWM(2, duty_steps[5]);
		Set_PWM(4, duty_steps[5]);
		pwm_duty =0;
		TRISA = 0B00111111;	//��Ӧ�Ŀ�������
		TRISB = 0B00111111;	//��Ӧ�Ŀ�������
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


