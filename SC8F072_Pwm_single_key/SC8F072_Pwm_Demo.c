#include <sc.h>
#include <stdbool.h>
#include "LED_188.h"

#pragma warning disable 752
#pragma warning disable 373			//���ε������1������


#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000			//16MHz,ʹ��������ʱ�������붨����Ƶ��
									//����FCPU_DIVѡ��2T����ʱ��ֵ����
#endif

#define  POWER_RATIO  	(4096UL*1.2*1000)
#define  POWER_MIN  	(1000UL*2.8)
#define  POWER_SCOPE  	(10UL*1.4)  //4.2-2.8

// ȫ�ֱ���
//ADC
volatile unsigned int adresult;
volatile unsigned char test_adc;
volatile unsigned int power_ad;
volatile unsigned char power_percent;
volatile bool ADC_Flag=0;
volatile unsigned int ADC_delay=0;
static unsigned int adc_last = 0;
//������PWM
volatile unsigned char pwm_duty = 0;       // ��ǰ PWM ռ�ձ�������5 ����
//volatile unsigned int Key_delay=0;
volatile unsigned char debounce_counter = 0;  // ��������������
volatile unsigned int long_press_counter = 0; // ����������
volatile unsigned int Time_delay = 0; //��ʾ��ʱ
volatile bool button_sflag = 0; // ����״̬��־
volatile bool button_lflag = 0; // ����״̬��־
const unsigned char duty_steps[6] = {66, 73, 85, 91, 95,0};
//188�����  
volatile bool T_flag = 0; // LEDˢ�±�־
volatile unsigned char hundreds = 4;	//��λ��0����ʾ��1���ٷֱȣ�2�ٷֱ�+���磬3-�ٷֱ�+��λ��4ȫ����ʾ
volatile unsigned char tens = 4; 		//ʮλ��10-F��11-����ʾ
volatile unsigned char unit = 2;		//��λ��10-F��11-����ʾ      		


//��������
void Init_System();
void PWM_Init();
void Set_PWM(unsigned char channel, unsigned char duty);
void Button_response() ;
unsigned char ADC_Sample(unsigned char adch, unsigned char adldo);
void ADC_read();

	
void main(void)            		//������,��Ƭ����������Ǵ����������ʼ����
{

    
	Init_System();
	Led_Gpio_Init();
    PWM_Init();
    while(1)					//��ѭ��,��Ƭ����ʼ����,��һֱ���������ѭ��
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
�������ƣ�Init_System
�������ܣ�ϵͳ��ʼ��
��ڲ�������
���ڲ�������
��ע��
************************************************/
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;					//ϵͳ��ʼ��
	OSCCON = 0X72;		//0111	0010	//������Ϊ16MHZ,�ڲ���������ϵͳʱ��,CONFIG�ر�WDTʱ���������WDT
	OPTION_REG = 0B00000100;    //Ԥ��Ƶ��TMR0 ��Timer0ʹ���ڲ�ʱ��Focs/4��Ԥ��Ƶ��Ϊ1:32
	asm("clrwdt");
//IO�ڳ�ʼ��	
    WPUA  = 0B00000000;		   //����������1Ϊʹ������
	WPUB  = 0B00000000;
	WPDA =  0B00000000;
	WPDB =  0B00000000;
	TRISA = 0B00000000;		   //��ʼ�����
	TRISB = 0B00000000;
	PORTA = 0B00000000;        //��ʼ��IO״̬
	PORTB = 0B00000000;	
//��ʱ��0
	TMR0 = 6;					//�趨Timer0��ʼֵ����ʱʱ��Ϊ��256-6��*4*32/16M=2ms
	T0IF = 0;                   //Timer0��־λ
	T0IE = 1;					//ʹ��Timer0����ж�
	GIE = 1;					//�������ж�

//��ʱ��2
    PR2 = 249;					//�趨Timer2����,1000uS�ж�
	TMR2IF = 0;                 //Timer2��־λ
	TMR2IE = 1;					//ʹ��Timer2����ж�
	T2CON = 0B00000111;			//����Timer2��Ԥ��ƵΪ1��16�����ƵΪ1��1����ʱʱ��Ϊ��249+1��*16*��4/16M��=1000us
	
//PB5�İ����ж�	
//---------------------------------------	
	WPUB = 0B00100000;		//ʹ��������ʹRB5Ϊ��
	TRISB= 0B00100000;		//����RB5��IO��Ϊ����
	IOCB = 0B00100000;		//����RB5��IO�ڵ�ƽ�仯�ж�
	RBIE = 1;				//ʹ��PORTB��ƽ�仯�ж�
	
	PORTB;					//��ȡPORTB������
//---------------------------------------		
//PA5���״̬�ж�
	WPUA = 0B00100000;		//ʹ��������ʹRA5Ϊ��
	TRISA= 0B00100000;		//����RA1��IO��Ϊ����
	IOCA = 0B00100000;		//����RA1��IO�ڵ�ƽ�仯�ж�
	RAIE = 1;				//ʹ��PORTA��ƽ�仯�ж�
//	INTCON = 0xC0;			//1100��������δ�����ε��жϡ����������жϣ���ֹINT�ⲿ�ж�
	RAIF = 0;				//���жϱ�־
	PORTA;					//��ȡPORTA������
    INTCON = 0xE8;			//1110 1000����δ�����ε��жϣ����������ж�
	                        //����Timer0���,PORTB�жϣ���������жϱ�־λ������INT�ⲿ�ж�
}

void PWM_Init()
{
   	PWMCON1 = 0B11000000;	//PWMѡ��A�飬����2��ֹ������1��ֹ������ʱ��ԴΪFosc/1
	TRISA = 0B00111111;	    //ѡ���PA0~PA5����Ϊ����
	PWMTL = 0XFF;			//PWM0123�����ڵ�8λ
	PWMT4L = 0XFF;          //PWM4�����ڵ�8λ
	PWMTH = 0X00;			//00��δ�ã�00��PWM4ռ�ձȸ�λ��
	                        //11��PWM4���ڸ�λ�� 11��PWM0123���ڸ�λ�� 
							//PWM0123����ѡ��Ϊ3FF��������Ϊ��1023+1��*1/8M��
							//����=[PWMT+1]*Tosc*(CLKDIV ��Ƶֵ)=256/8M*1 ���ڵ�ʱ�ӷ�Ƶ��PWMCON0ѡ��
							//PWM4����ѡ��Ϊ11 1111 1111(1023)  ������Ϊ��1023+1��*1/8M��	
	PWMD0L = 0X00;			//������ = (PWMDx[9:0]+1)*TOSC*(CLKDIV ��Ƶֵ)
							//����ע����ݹ�ʽ����ʹռ�ձ���Ϊ0���������������Ҫ����͵�ƽ
							//��Ҫ�ر�PWMEN��Ȼ����Ϊ�����
	PWMD1L = 0X00;			//����ģʽ��PWM1��ռ�ձ���PWM0������������ֵ�޹�
	PWMD01H = 0X00;			//xxPWM1 xxPWM2����PWM1,PWM2��ռ�ձȣ���ֵ���ܳ������ڣ�����Ϊ100%���                      
	//PWM01DT = 0X03;	    //������Ϊ2uS������Ϊ��3+1��*1/8M*4
							//����1��ռ�ձ���PWM0���õ�ռ�ձ�Ϊ��׼
	PWMD2L = 0X00;        	//PWM2 ռ�ձȵ�λ�Ĵ���   ��ֵ���ܳ������ڣ�����Ϊ100%���
	//PWMD3L = 0X7F;			//PWM3 ռ�ձȵ�λ�Ĵ��� ��������PWM0ռ�ձ�Ϊ׼
	PWMD23H = 0X00;			//PWM2 �� PWM3 ռ�ձȸ�λ�Ĵ��� PWMD01H����ֵ���ܳ������ڣ�����Ϊ100%���
	
	PWMD4L = 0X00;			// PWM4 ռ�ձȵ�λ�Ĵ���,PWM4ռ�ձȸ�λ��PWMTH��Bit4~5 
				            //11 0001 1111(779)  78%ռ�ձ�
	/***************PWMCON0*************************************
		Bit7~Bit5 CLKDIV[2:0]: PWMʱ�ӷ�Ƶ��
			111= FOSC/128
			110= FOSC/64
			101= FOSC/32
			100= FOSC/16
			011= FOSC/8
			010= FOSC/4
			001= FOSC/2
			000= FOSC/1
		Bit4~Bit0 PWMxEN: PWMxʹ��λ��
			1= ʹ��PWMx��
			0= ��ֹPWMx��
	******************************************************************/
	PWMCON0 = 0X17;			//000 1 0111ʹ��PWM0~PWM2 ,PWM4  ��Ƶ��Ϊ1
	PWMCON2 =0X00;			//xxx0 0000 PWM4�������
//	TRISA = 0B00101000;	//��Ӧ�Ŀ���012��4��Ϊ���  3,5����
}	


/***********************************************
�������ƣ�Set_PWM
�������ܣ����� PWM ռ�ձ�
��ڲ�����channel��ͨ���ţ���duty��ռ�ձ� 0~100��
���ڲ�������
��ע��
************************************************/
void Set_PWM(unsigned char channel, unsigned char duty)
{
	unsigned char pulse_width = (unsigned char)((duty * 255) / 100);  // ռ�ձ�ת��Ϊ����ֵ��256Ϊ���ֵ��
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
�������ƣ�AD_Sample
�������ܣ�AD���
��ڲ�����adch - ���ͨ��
���ڲ�������
��    ע������ͨ������������Ϊ�����
	      ����10��,ȡ�м�˴ε�ƽ��ֵΪ�����������adresult��

	      adch Ϊ����ADͨ�� 0-15��31
             31  ����ڲ�1.2V
	
 		  adldo =5,�����ڲ�LDO 2V ��ΪADC �ο�
 		  adldo =6,�����ڲ�LDO 2.4V ��ΪADC �ο�
		  adldo =7,�����ڲ�LDO 3V ��ΪADC �ο�
 		  adldo =0,VDD ��ΪADC �ο�
 		  ADת����������
 		  ADC�ο���ѹ��VDD�л���LDOʱ��Ҫ��ʱ100us���ϣ����ܽ���ADת��
**********************************************************/
unsigned char ADC_Sample(unsigned char adch, unsigned char adldo) 
{
	
	volatile unsigned long adsum = 0;
	volatile unsigned int admin = 0, admax = 0;
	volatile unsigned int ad_temp = 0;

	if ((!LDO_EN) && (adldo & 0x04) ) 
	{
								//���AD�ο���VDD�����ڲ�LDO����Ҫ��ʱ100US����
		ADCON1 = adldo;			//�����,ADֵȡ12λ
		__delay_us(100);		//IDE������ʱ��������ʱ100us
	} 
	else
		ADCON1 = adldo;			//���ADCON1.7(ADFM)=1Ϊ�Ҷ��룬,ADֵȡ10λ
	if(adch & 0x10) //���Ϊ31����ڲ�1.2V
	{
		CHS4 = 1;
		adch &= 0x0f;
	}
	unsigned char i = 0;
	for (i = 0; i < 10; i++) 
	{
		ADCON0 = (unsigned char)(0X41 | (adch << 2));	//16��Ƶ�������ƵΪ16M�������ѡ16��Ƶ������
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");				//ѡ��ͨ��������ʱ1uS����
		GODONE = 1;				//��ʼת��
		unsigned char j = 0;
		while (GODONE) 
		{
			__delay_us(2);		//��ʱ2us(���������ú���)
			if (0 == (--j))		//��ʱ0.5ms��û��ADת����������������
			return 0;
		}

		ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));	//����12λADֵ

		if (0 == admax) 
		{
			admax = ad_temp;
			admin = ad_temp;
		} 
		else if (ad_temp > admax)admax = ad_temp;	//AD�������ֵ
						
		else if (ad_temp < admin)admin = ad_temp;   //AD������Сֵ
		adsum += ad_temp;
	}
	adsum -= admax;
	if (adsum >= admin)
		adsum -= admin;
	else
		adsum = 0;
	/*adresult = adsum >> 3;		//8��ƽ��ֵ��Ϊ���ս��*/
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
	test_adc = ADC_Sample(31, 0);		//�����ڲ���׼1.2V��Ե�Դ��ADֵ
	if (0xA5 == test_adc)
	{
		volatile unsigned long power_temp;
		power_temp = (unsigned long)((POWER_RATIO)/adresult);//1.2*4096/AD=VDD�������Ŵ�1000�� 
		power_ad = (unsigned int)(power_temp);//ͨ���ڲ���׼��ѹ�Ƴ�оƬVDD��ѹ
		power_percent = (unsigned char)((power_ad-POWER_MIN)/POWER_SCOPE);
	}
	else
	{
		ADCON0 = 0;						//���ת��û����ɣ����ʼ��ADCON0,1
		ADCON1 = 0;				
		__delay_us(100);				//��ʱ100us(���������ú���)
	}
	ADC_Flag=0;	
}
void Button_response() 
{
    if (button_sflag)   //�̰�����
	{
		TRISA = 0B00101000;	//��Ӧ�Ŀ���012��4���
		__delay_us(100);				//��ʱ100us(���������ú���)
        button_sflag = 0;  // ���־
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
				TRISA = 0B00111111;	//��Ӧ�Ŀ���012��4����*/
				break;
			default:
				break;
		}
		Time_delay=2500;
		Motor_num();
		pwm_duty = (pwm_duty + 1) % 5;  // ѭ���л� 5 ��ռ�ձ�
		T_flag=1;//�����ˢ�±�־λ
		
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
			Charge_num();  //�����
		}
		else
		{
			Uncharge_num();	//�ǳ��״̬
		}
		RAIF = 0;			//���жϱ�־
	}
	if(RBIF)
	{
		/*if (!(PORTB & 0x20))  // RB5���������£�
		{  
            Key_delay=501;  //��ʼ500ms��ʱ��
        }*/
		if (PORTB & 0x20)  // RB5 �����أ������ɿ���
		{  
            if (long_press_counter >= 1000) 
			{  // �������� 1 ��
                button_lflag = 1;  // ��ǳ���
            } 
			else if(long_press_counter<=1000 && long_press_counter>=50)
			{
                button_sflag = 1;  // ��Ƕ̰�
            }
            long_press_counter = 0;
        }
		RBIF = 0;			//���жϱ�־
	}
	if(T0IF)
	{
		if(T_flag)
		{
			Display();//ÿ2msִ��һ�Σ�һ������10ms��ˢ����100
		}
		TMR0 += 6;	//TMR0�����Զ���ֵ������TMR0��ʱ��,TIME�ǲ�������
		T0IF = 0;  //���жϱ�־
		
		if(ADC_delay > 0)//ÿ2s����һ��ADC����
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
		/*if(Key_delay>1)//500ms����ʱ
		{
			Key_delay--;
		}
		else if(Key_delay==1)//500msʱ���
		{
			Key_delay=0;//�ر�500ms��ʱ��
			if (!(PORTB & 0x20))  // RB5 �͵�ƽ�����£�
			{
				button_lflag = 1;  // ��ǳ���
			}
			else
			{
				button_sflag = 1;  // ��Ƕ̰�
			}
		}*/
		
	    // ��������ͳ������
       if (!(PORTB & 0x20))  // RB5 �͵�ƽ�����£�
		{ 
			if (debounce_counter < 15) debounce_counter++;
            if (debounce_counter == 15) long_press_counter++;  // ��������
        } 
		else 
		{
            debounce_counter = 0;  // �����ɿ�������������
        }
		 
		
		if(Time_delay > 0)//�̰�����ʱ����ADC��ֵ
		{
             Time_delay--;
		}
		else
		{
			if (!(PORTA & 0x20)) 
			{
				Charge_num();  //�����
			}
			else
			{
				Uncharge_num();	//�ǳ��״̬
			}
		}
	}
}



