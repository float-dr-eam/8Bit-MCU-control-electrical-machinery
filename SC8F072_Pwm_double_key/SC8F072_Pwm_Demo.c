#include <sc.h>
#include <stdbool.h>
#include "LED_188.h"
#include "PWM.h"
#include "KEY.h"

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
/*//�����˲����
unsigned char power_percent_iir = 0;
//2�� ��Դ�˲�
unsigned char y37v[3] = {0, 0, 0};
unsigned char x37v[3] = {0, 0, 0};*/

//������PWM
//unsigned char debounce_counter = 0;  // ��������������
unsigned int long_press_counter = 0; // ����������
unsigned int Time_delay = 0; //��ʾ��ʱ
bool button_sflag = 0; // ����״̬��־
bool button_lflag = 0; // ����״̬��־

//188�����  
bool T_flag = 0; // LEDˢ�±�־
unsigned char hundreds = 4;	//��λ��0����ʾ��1���ٷֱȣ�2�ٷֱ�+���磬3-�ٷֱ�+��λ��4ȫ����ʾ
unsigned char tens = 4; 		//ʮλ��10-F��11-����ʾ
unsigned char unit = 2;		//��λ��10-F��11-����ʾ      		
//LED����
//unsigned int LED_delay=0;
unsigned int LED_Key_counter = 0; // LED������
bool LED_lflag = 0; // LED������״̬��־
bool LED_sflag = 0; // LED������״̬��־
//bool breath_TFlag = 0; 

//��������
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
	
void main(void)            		//������,��Ƭ����������Ǵ����������ʼ����
{
	Init_System();
	Led_Gpio_Init();
    PWM_Init();
    while(1)					//��ѭ��,��Ƭ����ʼ����,��һֱ���������ѭ��
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
			TRISA0 = 0;	  //��Ӧ�Ŀ���012���
			TRISA1 = 0;	
			TRISA2 = 0;	
			Set_PWM(0,95);
			Set_PWM(1,95);
			Set_PWM(2,0);
		}
		if(LED_sflag)
		{
			TRISA0 = 0;	  //��Ӧ�Ŀ���012���
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
	OPTION_REG = 0B00000101;    //Ԥ��Ƶ��TMR0 ��Timer0ʹ���ڲ�ʱ��Focs/4��Ԥ��Ƶ��Ϊ1:64
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
	TMR0 = 6;					//�趨Timer0��ʼֵ����ʱʱ��Ϊ��256-6��*4*64/16M=4ms
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
	WPUA = 0B00101000;		//ʹ��������ʹRA5Ϊ��
	TRISA= 0B00101000;		//����RA1��IO��Ϊ����
	IOCA = 0B00101000;		//����RA1��IO�ڵ�ƽ�仯�ж�
	RAIE = 1;				//ʹ��PORTA��ƽ�仯�ж�
//	INTCON = 0xC0;			//1100��������δ�����ε��жϡ����������жϣ���ֹINT�ⲿ�ж�
	RAIF = 0;				//���жϱ�־
	PORTA;					//��ȡPORTA������
    INTCON = 0xE8;			//1110 1000����δ�����ε��жϣ����������ж�
	                        //����Timer0���,PORTB�жϣ���������жϱ�־λ������INT�ⲿ�ж�
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
	adresult = adsum >> 3;		//8��ƽ��ֵ��Ϊ���ս��
	adsum = 0;
	admin = 0;
	admax = 0;
	return 0xA5;
}

unsigned char ADC_read(void)
{
	test_adc = ADC_Sample(31, 0);		//�����ڲ���׼1.2V��Ե�Դ��ADֵ
	if (0xA5 == test_adc)
	{
		volatile unsigned long power_temp;
		power_temp = (unsigned long)((POWER_RATIO)/adresult);//1.2*4096/AD=VDD�������Ŵ�1000�� 
		power_ad = (unsigned int)(power_temp);//ͨ���ڲ���׼��ѹ�Ƴ�оƬVDD��ѹ
		power_percent = (unsigned char)((power_ad-POWER_MIN)/POWER_SCOPE);
		if(power_percent>100)
		{
			power_percent=100;
		}
	}
	else
	{
		ADCON0 = 0;						//���ת��û����ɣ����ʼ��ADCON0,1
		ADCON1 = 0;				
		__delay_us(100);				//��ʱ100us(���������ú���)
	}
	ADC_Flag=0;	
	return power_percent;
}

void interrupt Isr_Timer() 
{
    if(RAIF)
	{	
		RAIF = 0;			//���жϱ�־	
		if (!(PORTA & 0x04))  // RA3 �����أ������ɿ���0000 1000
		{  
			if(LED_Key_counter > 1015 )
			{
                LED_lflag = 1;  // ���LED����
            }
			else if(LED_Key_counter<=1015 && LED_Key_counter>=150)
			{
				LED_sflag = 1;  // ���LED�̰�
			}
            LED_Key_counter = 0;
        }
	/*	else
		{
			if(LED_Key_counter > 1015 )
			{
                LED_lflag = 1;  // ���LED����
            }
			else if(LED_Key_counter<=1015 && LED_Key_counter>=65)
			{
				LED_sflag = 1;  // ���LED�̰�
			}
            LED_Key_counter = 0;
		}*/
		/*if(!(PORTA & 0x04))//PA3�͵�ƽ
		{
			LED_delay=100;//��ʱ��2��ʱ521ms
		}*/
				
		if (!(PORTA & 0x20)) //PA5�͵�ƽ
		{
			T_flag = 1;
			Charge_num();  //�����
		}
		else
		{
			T_flag = 1;
			Uncharge_num();	//�ǳ��״̬
		}
	}

	if(RBIF)
	{
		RBIF = 0;			//���жϱ�־
		if (PORTB & 0x20)  // RB5 �����أ������ɿ���
		{  
            if (long_press_counter > 1015) 
			{  // �������� 1 ��
                button_lflag = 1;  // ��ǳ���
            } 
			else if(long_press_counter<=1015 && long_press_counter>=65)
			{
                button_sflag = 1;  // ��Ƕ̰�
            }
            long_press_counter = 0;
        }
	}
	if(T0IF)//4ms
	{		
		TMR0 += 6;	//TMR0�����Զ���ֵ������TMR0��ʱ��,TIME�ǲ�������
		T0IF = 0;  //���жϱ�־
		if(T_flag)
		{
			Display();//ÿ4msִ��һ�Σ�һ������20ms��ˢ����50
		}

		
		if(ADC_delay > 0)//ÿ4s����һ��ADC����
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
		
		/*if(LED_delay>1)//520ms����ʱ
		{
			LED_delay--;
		}
		else if(LED_delay==1)//520msʱ���
		{
			LED_delay=0;//�ر�520ms��ʱ��
			if (!(PORTA & 0x04))  // RA3 �͵�ƽ�����£�
			{
				LED_sflag = 1;  // ���LED��������
			}
			else if(PORTA & 0x04)
			{
				LED_lflag = 1;  // ���LED��������
			}
			
		}*/
	    // ��������Ͱ������
        if (!(PORTA & 0x04))  // RA3 �͵�ƽ�����£�0000 1000
		{ 
			LED_Key_counter++;  // ��������
        } 
		
	    // ��������ͳ������
        if (!(PORTB & 0x20))  // RB5 �͵�ƽ�����£�
		{ 
			long_press_counter++;  // ��������
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


