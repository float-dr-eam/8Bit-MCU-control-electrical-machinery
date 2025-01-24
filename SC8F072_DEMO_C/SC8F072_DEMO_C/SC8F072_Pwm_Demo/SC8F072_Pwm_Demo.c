
//CCP1 PWMģʽ�ο�����
#include <SC8f072.h>           		
//���õ�Ƭ����ͷ�ļ�
void Init_System();

	
void main(void)            		//������,��Ƭ����������Ǵ����������ʼ����
{
	unsigned int delaycnt = 0;
	unsigned char pwmbuf = 0X1F;

	Init_System();
	
								//�����Ƕ�PWM���ܳ�ʼ��
		/************PWMCON1����**************************
		Bit7~6 PWMIO_SEL[1:0]: PWM IOѡ��
			11= PWM������A�飬PWM0-RA0,PWM1-RA1,PWM2-RA2,PWM3-RA3,PWM4-RA4
			10= PWM������B�飬PWM0-RA0,PWM1-RA1,PWM2-RA2,PWM3-RB2,PWM4-RB1
			01= PWM������C�飬PWM0-RA5,PWM1-RB7,PWM2-RB6,PWM3-RB5,PWM4-RB4
			00= PWM������D�飬PWM0-RB0,PWM1-RB1,PWM2-RB3,PWM3-RB4,PWM4-RB2
		Bit5 PWM2DTEN: PWM2����ʹ��λ��
			1= ʹ��PWM2�������ܣ�PWM2��PWM3���һ�Ի��������
			0= ��ֹPWM2�������ܡ�
		Bit4 PWM0DTEN: PWM0����ʹ��λ��
			1= ʹ��PWM0�������ܣ�PWM0��PWM1���һ�Ի��������
			0= ��ֹPWM0�������ܡ�
		Bit3~Bit2 δ�á�
		Bit1~Bit0 DT_DIV[1:0] ����ʱ��Դ��Ƶ��
			11= FOSC/8
			10= FOSC/4
			01= FOSC/2
			00= FOSC/1
	**********************************************************************/
		PWMCON1 = 0B11010010;	//PWMѡ��A�飬����2��ֹ������1ʹ�ܣ�����ʱ��ԴΪFosc/4
		
		TRISA	= 0B00011111;	//ѡ���PA0~PA4����Ϊ����
		PWMTL = 0XFF;			//PWM ����=[PWMT+1]*Tosc*(CLKDIV ��Ƶֵ)
		PWMT4L = 0XFF;
		PWMTH = 0X0C;			//����ѡ��Ϊ0FF��������Ϊ��255+1��*1/8M�����ڵ�ʱ�ӷ�Ƶ��PWMCON0ѡ��
								//PWM4����ѡ��Ϊ03FF
		
		PWMD0L = 0X1F;			//������ = (PWMDx[9:0]+1)*TOSC*(CLKDIV ��Ƶֵ)
								//����ע����ݹ�ʽ����ʹռ�ձ���Ϊ0���������������Ҫ����͵�ƽ
								//��Ҫ�ر�PWMEN��Ȼ����Ϊ�����
		PWMD1L = 0X7F;			//����ģʽ��PWM1��ռ�ձ���PWM0������������ֵ�޹�
		PWMD01H = 0;			//����PWM1,PWM2��ռ�ձȣ���ֵ���ܳ������ڣ�����Ϊ100%���
		
		PWM01DT = 0X03;			//������Ϊ2uS������Ϊ��3+1��*1/8M*4
								//����1��ռ�ձ���PWM0���õ�ռ�ձ�Ϊ��׼
		
		PWMD2L = 0X3F;        	//PWM2 ռ�ձȵ�λ�Ĵ���   ��ֵ���ܳ������ڣ�����Ϊ100%���
		PWMD3L = 0X7F;			//PWM3 ռ�ձȵ�λ�Ĵ��� ��������PWM0ռ�ձ�Ϊ׼
		PWMD23H = 0;			//PWM2 �� PWM3 ռ�ձȸ�λ�Ĵ��� PWMD01H����ֵ���ܳ������ڣ�����Ϊ100%���
		
		PWMD4L = 0X1F;			//PWM4 ռ�ձȵ�λ�Ĵ���,PWM4ռ�ձȸ�λ��PWMTH��Bit4~5 
				
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
		PWMCON0 = 0X1F;			//��PWM0~PWM4,��Ƶ��Ϊ1
		PWMCON2 =0X10;			//PWM4�������
		TRISA = 0;				//��Ӧ�Ŀ�����Ϊ���
		
    while(1)					//��ѭ��,��Ƭ����ʼ����,��һֱ���������ѭ��
    {
		asm("clrwdt");
		if(++delaycnt > 5000)	//��ʱ20000��������ڣ��Ǿ�ȷ��ʱ
   		{
   			delaycnt = 0;       //�����Ա��´����¼���
   			if(++pwmbuf > 0xfe)	//ռ�ձȼ�һ
   			{
   				pwmbuf = 0x01f;
   			}
			PWMD0L = pwmbuf;	//д��ռ�ձ�
   		}
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
	OSCCON = 0X72;				//������Ϊ8M
	OPTION_REG = 0;
	asm("clrwdt");
	
	TRISA = 0B00011111;			//��ʼ��IO״̬
	TRISB = 0B00000000;

	PORTA = 0B00000000;
	PORTB = 0B00000000;			//��ʼ�����

}