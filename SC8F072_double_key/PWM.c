#include "PWM.h"


void PWM_Init(void)
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
	unsigned short pulse_width = (unsigned short)(duty * 255) / 100;  // ռ�ձ�ת��Ϊ����ֵ��256Ϊ���ֵ��
	switch (channel) 
	{
		case 0:
			PWMD0L = pulse_width & 0xFF;
			break;
		case 1:
			PWMD1L = pulse_width & 0xFF;
			break;
		case 2:
			PWMD2L = pulse_width & 0xFF;
			break;
		case 3:
			PWMD3L = pulse_width & 0xFF;
			break;
		case 4:
			PWMD4L = pulse_width & 0xFF;
			break;
		default:
		    break;
    }
}