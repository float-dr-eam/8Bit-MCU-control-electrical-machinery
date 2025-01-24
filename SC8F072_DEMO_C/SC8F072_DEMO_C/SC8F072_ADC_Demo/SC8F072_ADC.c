/**********************************************************
AD��ⷶ������
**********************************************************/
#pragma warning disable 752
#pragma warning disable 373			//���ε������1������
#include <sc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000			//16MHz,ʹ��������ʱ�������붨����Ƶ��
									//����FCPU_DIVѡ��2T����ʱ��ֵ����
#endif

#define     POWER_RATIO  	(4096UL*1.2*1000)

volatile unsigned int adresult;
volatile unsigned int result;
volatile unsigned char test_adc;
volatile unsigned int power_ad;

unsigned char ADC_Sample(unsigned char adch, unsigned char adldo);
void DelayXms(unsigned char x);
unsigned char ADC_Result(unsigned char adch);
void Init_System();
void AD_Init();

#define _DEBUG			//���Գ�����

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

	if(adch & 0x10) 
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
		else if (ad_temp > admax)
			admax = ad_temp;				//AD�������ֵ
		else if (ad_temp < admin)
			admin = ad_temp;				//AD������Сֵ

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


/***********************************************************
main������
***********************************************************/
void main() 
{
	Init_System();
	AD_Init();

	while (1) 
	{
		asm("clrwdt");

#ifdef _DEBUG
		TRISB7 = 1;							//����AN15��Ӧ��IO��Ϊ����,
		ANSEL1 |= 0X80;						//����AN15��Ӧ��IO��Ϊģ������
		test_adc = ADC_Sample(15, 7);		//����AN15�ڵ�ADֵ���ο���ѹ3V
		if (0xA5 == test_adc)				//������ɣ���������ԭ����ADת��û����ɣ��򲻴���
		{
			
		}
		else
		{
			ADCON0 = 0;						//���ת��û����ɣ����ʼ��ADCON0,1
			ADCON1 = 0;				
			__delay_us(100);				//��ʱ100us(���������ú���)
		}

		test_adc = ADC_Sample(31, 0);		//�����ڲ���׼1.2V��Ե�Դ��ADֵ
		if (0xA5 == test_adc)
		{
			volatile unsigned long power_temp;
			
			power_temp = (unsigned long)((POWER_RATIO)/adresult);		//1.2*4096/AD=VDD�������Ŵ�1000�� 
			power_ad = (unsigned int)(power_temp);		//ͨ���ڲ���׼��ѹ�Ƴ�оƬVDD��ѹ
		}	

#endif
	}
}

/**********************************************************
�������ƣ�Init_System
�������ܣ�ϵͳ��ʼ��
��ڲ�������
���ڲ�������
��    ע��
**********************************************************/
void Init_System() 
{
	asm("nop");
	asm("clrwdt");
	OPTION_REG = 0;					//Ԥ��Ƶ��TMR0 ��Timer0ʹ���ڲ�ʱ��Focs/4��Ԥ��Ƶ��Ϊ1:2
	asm("clrwdt");
	OSCCON = 0X70;					//�ڲ�����8M

	WPUA = 0B00000000;				//����������1Ϊʹ������
	WPUB = 0B00000000;

	TRISA = 0B00000000;				//����IO״̬��0Ϊ�����1Ϊ����
	TRISB = 0B00000000;

	PORTA = 0X00;
	PORTB = 0X00;

//---------------------------------------
//125us�жϳ�ʼ��
	PR2 = 249;					//�趨Timer��ʼֵ����ʱ������250*4/8M=125uS
	TMR2IF = 0;
	TMR2IE = 1;					//ʹ��Timer2����ж�

	T2CON = 0B00000100;			//����Timer2,����TMR2�ķ�Ƶ��Ϊ1:1
	INTCON = 0XC0;				//�������ж�
}

/***********************************************************
�жϷ�����
�������ƣ�Isr_Timer()
�������ܣ��жϴ�����
��ڲ�����
���ڲ�����
��    ע��125US��ʱ2�ж�
			�����ж϶���������������洦��
***********************************************************/
void interrupt Isr_Timer() 
{
	if (TMR2IF) 
	{			//��ֻʹ����һ���ж�Դ,������ȥ�ж�
		TMR2IF = 0;

	}

}

/***********************************************************
�жϷ�����
�������ƣ�AD_Init()
�������ܣ�AD��ʼ��������
��ڲ�����
���ڲ�����
��    ע����һ�δ�AD����λADON������ʱ20uS���ϲ��ܽ���AD����
			���̳��򲻹ر�ADON������Ҫ��ʱ
***********************************************************/
void AD_Init() 
{
	/*********** ADCON0 ****************************
		Bit7~Bit6  ADCS<1:0>:  ADת��ʱ��ѡ��λ��
			00=  F HSI /16
			01=  F HSI /32
			10=  F HSI /64
			11=  F HSI /128
		Bit5~Bit2  CHS<3:0>:  ģ��ͨ��ѡ��λ����ADCON1�Ĵ���CHS4���CHS<3:0>
			CHS<4:0>: 
			00000=  AN0
			00001=  AN1
			00010=  AN2
			00011=  AN3
			00100=  AN4
			00101=  AN5
			00110=  ����
			00111=  ����
			01000=  AN8
			�� 
			01101=  AN13
			01110=  AN14
			01111=  AN15
			11111=  1.2V���̶��ο���ѹ��
			����=  ����
		Bit1  GO/DONE: ADת��״̬λ��
			1=  ADת�����ڽ��С�����λ��1����ADת������ADת������Ժ󣬸�λ��Ӳ���Զ����㡣
				��GO/DONEλ��1��0��ADIF��0��1ʱ�������ٵȴ�����TADʱ�䣬�����ٴ�����ADת����
			0=  ADת�����/���ڽ����С�
		Bit0  ADON:  ADCʹ��λ��
			1=  ʹ��ADC��
			0=  ��ֹADC�������Ĺ���������
	*********************************************/
	ADCON0 = 0X41;		//ADON������AD����ʱ��ѡΪFSYS/16
	
	/*********** ADCON1 ****************************
		Bit7  ADFM:  ADת�������ʽѡ��λ��
			1=  �Ҷ��룻
			0=  ����롣
		Bit6  CHS4:  ͨ��ѡ��λ
		Bit5~Bit3  δ�� 
		Bit2  LDO_EN:  �ڲ��ο���ѹʹ��λ��
			1=  ʹ��ADC�ڲ�LDO�ο���ѹ��
				��ѡ���ڲ�LDO���ο���ѹʱ��ADC�����Ч����Ϊ8λ��
			0=  VDD��ΪADC�ο���ѹ��
		Bit1~Bit0  LDO_SEL<1:0>:  �ο���ѹѡ��λ
			0X=  2.0V
			10=  2.4V
			11=  3.0V
	*********************************************/
	ADCON1 = 0;
}