#include <sc.h>
#include "Touch_Kscan_Library.h"


volatile unsigned char MainTime;
volatile bit	B_MainLoop,B_OnOff;

//ϵͳ��ʼ��
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;				//��ֹ�ж�
	OSCCON = 0X72;			//������Ϊ8M
	OPTION_REG = 0;
	
	
	//��ʱ�ȴ���Դ��ѹ�ȶ�
	//DelayXms(200);
	TRISA = 0;
	PORTA = 0;
	TRISB = 0;
	PORTB = 0;	
	TRISC = 0;
	PORTC = 0;

	PIE1 = 2;
	PR2 = 250;				//8M�½�TMR2����Ϊ125us�ж�
	T2CON = 4;				//ʹ�ܶ�ʱ��2

	INTCON = 0XC0;			//ʹ���ж�
}


/**********************************************************
�������ƣ�Refurbish_Sfr
�������ܣ�ˢ��һЩ���⹦�ܼĴ���
��ڲ�������
���ڲ�������
��    ע��ÿ��һ��ʱ��ˢ��һ��SFR����ǿ����������
**********************************************************/
void Refurbish_Sfr() 
{
	//ˢ���ж���ؿ��ƼĴ���
	PIE1 = 2;
	PR2 = 250;
	INTCON = 0XC0;
	if (4 != T2CON)
		T2CON = 4;
}


/***********************************************************
��������
***********************************************************/
void KeyServer() 
{
	static unsigned char KeyOldFlag = 0;
	if (KeyFlag[0]) 
	{
		if (KeyFlag[0] != KeyOldFlag) 
		{
			//ȷ��״̬�ı�İ���
			KeyOldFlag ^= KeyFlag[0];
			if ((KeyOldFlag & 0x1) && (KeyFlag[0] & 0x1)) 
			{
				//KEY1������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x2) && (KeyFlag[0] & 0x2)) 
			{
				//KEY2������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x4) && (KeyFlag[0] & 0x4)) 
			{
				//KEY3������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x8) && (KeyFlag[0] & 0x8)) 
			{
				//KEY4������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}

			if ((KeyOldFlag & 0x10) && (KeyFlag[0] & 0x10)) 
			{
				//KEY5������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x20) && (KeyFlag[0] & 0x10))
			{
				//KEY6������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x40) && (KeyFlag[0] & 0x10)) 
			{
				//KEY7������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}
			if ((KeyOldFlag & 0x80) && (KeyFlag[0] & 0x10)) 
			{
				//KEY8������
				PORTB ^= 0x20;
				B_OnOff = !B_OnOff;
			}

			KeyOldFlag = KeyFlag[0];
		}
	} 
	else 
	{
		KeyOldFlag = 0;
	}
}


/***********************************************************
�жϷ�����
***********************************************************/
void interrupt Isr_Timer()
{
	if(TMR2IF)				//��ֻʹ����һ���ж�Դ,������ȥ�ж�
	{
		TMR2IF = 0;
		if(++MainTime >= 32)	//�������ѡ��Ĵ���·���ʹ�������ѡ��ɨ��һ�ΰ�����ʱ��
		{						//һ��103���ݣ�8·������8M��Ƶ���ʱ��Լ4ms����ɨ��һ�ε�ʱ���ѡ5ms
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		PIR1 = 0;
	}
	
}

void WorkSleep()
{
#if (0 != C_KEY_WAKEUP)
	static unsigned char time;
	
	if(B_OnOff)time = 0;
	
	if(++time >= 125)
	{
		time = 0;
		INTCON = 0;			//;�ض�ADCģ�鼰�ж�ʹ�ܣ�
		PIE1 = 0;
		PIE2 = 0;
		PIR1 = 0;
		PIR2 = 0;
		T2CON = 0;
		ADCON1 = 0;

		//��������ǰ�ص����й���ģ��,�Խ������ߵ���
		ADCON0 = 0;
	
		//��������ǰ,����̶����ߵ�ƽ,���ȫ������͵�ƽ,���ر�������������
		TRISA = 0;
		PORTA = 0;
		TRISB = 0;
		PORTB = 0;
		TRISC = 0;
		PORTC = 0;

/****����ҪPA���жϻ��ѣ�ʹ�����г��򲢰����޸�****
			TRISA0 =1;	//����
			WPUA0 = 1;	//����			
			RAIF = 0;	//���־
			RAIE = 1;	//����PA�ڵ�ƽ�仯�ж�
			IOCA0 = 1;	//����PA0��ƽ�仯�ж�
			PEIE = 1;	//���������ж�
			PORTA;		//��һ��PA��			
************************************/	

		//��������ģʽ,���������ѵİ�����ָ���������
		SystemEnterSleep();
		if(RAIF) 
		{
			RAIF = 0;
			PORTA;
		}
		//���߱�����,���������жϵ�SFR,ʹϵͳ������������
		Refurbish_Sfr();
	}
#endif
}

/***********************************************************
��ѭ��
***********************************************************/
void main()
{
	Init_System();
	while(1)
	{
		if(B_MainLoop)
		{
			B_MainLoop = 0;
			CLRWDT();
			
			CheckTouchKey();
			
			Refurbish_Sfr();
			KeyServer();

			WorkSleep();
		}
	}
}