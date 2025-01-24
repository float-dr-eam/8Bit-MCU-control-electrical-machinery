#include <sc.h>
#include "CheckTouchKey.h"		

volatile unsigned char MainTime;
volatile bit	B_MainLoop;

//ϵͳ��ʼ��
void Init_System()
{
	asm("nop");
	asm("clrwdt");
	INTCON = 0;				//��ֹ�ж�
	OSCCON = 0x72;
	OPTION_REG = 0;		//����Ƶ������TMR0
	
	INTCON = 0;
	TRISB = 0;
	PORTB = 0;
	
	PIR1 = 0;
	PIE1 = 0;
	PIR2 = 0;
	PIE2 = 0;
	
	/*��ʼ����ʱ��2, 125us�ж�*/
	PR2 = 250;
	T2CON = 4;
	TMR2IE = 1;
	
	INTCON = 0XC0;
}


/**********************************************************
ˢ�����⹦�ܼĴ���
**********************************************************/
void Refurbish_Sfr()
{
	//ˢ���ж���ؿ��ƼĴ���
	PIE1 = 2;
	PR2 = 250;
	INTCON = 0XC0;
	if(4 != T2CON)
		T2CON = 4;
}




/***********************************************************
�жϷ�����
***********************************************************/
void interrupt Isr_Timer()
{
	if(TMR2IF)				//��ֻʹ����һ���ж�Դ,������ȥ�ж�
	{
		TMR2IF = 0;
		if(++MainTime >= 32)
		{
			MainTime = 0;
			B_MainLoop = 1;
		}
	}
	else
	{
		PIR1 = 0;
	//	PIR2 = 0;
	}
}

/***********************************************************
��ѭ��
***********************************************************/
void main()
{
	Init_System();
	while(1)
	{
		
			CLRWDT();
		Refurbish_Sfr();	//���Ѻ�ˢ��ר�üĴ���
		CheckTouchKey();	//�������	
		
	}
}