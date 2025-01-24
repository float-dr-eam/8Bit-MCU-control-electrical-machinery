#include "LED_188.h"
#include <stdbool.h>

volatile u8 hundreds = 4;	//��λ��0����ʾ��1���ٷֱȣ�2�ٷֱ�+���磬3-�ٷֱ�+��λ��4ȫ����ʾ
volatile u8 tens = 4; 		//ʮλ��10-F��11-����ʾ
volatile u8 unit = 2;		//��λ��10-F��11-����ʾ 
   
volatile u8 power_percent;
volatile u8 pwm_duty ;       // ��ǰ PWM ռ�ձ�������5 ����

void Charge_num(void)
{
	bool hundred = (bool)(power_percent / 100);  // ��λ
	tens = (u8)((power_percent % 100) / 10); 		//ʮλ��10-F��11-����ʾ
	unit = (u8)(power_percent % 10);		//��λ��10-F��11-����ʾ
	if(hundred)
	{
	   hundreds = 4;
	}
	else
	{
	   hundreds = 2;
	}
}
void Uncharge_num(void)
{
	bool hundred = (bool)(power_percent / 100);  // ��λ
	tens = (u8)((power_percent % 100) / 10); 		//ʮλ��10-F��11-����ʾ
	unit = (u8)(power_percent % 10);		//��λ��10-F��11-����ʾ
	if(hundred)
	{
	   hundreds = 3;
	}
	else
	{
	   hundreds = 1;
	}
}
void Motor_num(void)
{
	hundreds =0;  // ��λ
	tens = 0; 		//ʮλ��10-F��11-����ʾ
	unit = (u8)(pwm_duty+1) ;		//��λ��10-F��11-����ʾ
}
/*
*	��λ���ٷֱȣ����ָʾ��ʾ
*					BIT3	BIT2	BIT1	BIT0
*					B1		C1		I		J
*	0-����ʾ		    0		0		0		0		0x00
*	1-���ٷֱ�		0		0		0		1		0x01
*	2-�ٷֱ�+���	0		0		1		1		0x03							
*	3-�ٷֱ�+��λ	1		1		0		1		0x0D
*	4-ȫ����ʾ		1		1		1		1		0x0F
*/
u8 num_hund[5] = {0x00, 0x01, 0x03,	0x0D, 0x0F};
/*
*	ʮλ��ʾ�͸�λ��ʾ
*			BIT7	BIT6	BIT5	BIT4 	BIT3	BIT2	BIT1	BIT0
*			xx		A2/3	B2/3	C2/3	D2/3	E2/3	F2/3	G2/3
*	0				1		1		1		1		1		1		0		0x7E
*	1				0		1		1		0		0		0		0		0x60
*	2				1		1		0		1		1		0		1		0x6D						
*	3				1		1		1		1		0		0		1		0x79
*	4				0		1		1		0		0		1		1		0x33
*	5				1		0		1		1		0		1		1		0x5B
*	6				1		0		1		1		1		1		1		0x5F
*	7				1		1		1		0		0		0		0		0x70							
*	8				1		1		1		1		1		1		1		0x7F
*	9				1		1		1		1		0		1		1		0x7B
*	F				1		0		0		0		1		1		1		0x47
*	����ʾ			0		0		0		0		0		0		0		0x00
*/
u8 nums[12] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0x47, 0x00};

//��������ų�ʼ��
void Led_Gpio_Init(void)
{
	PIN1_IN();
	PIN2_IN();
	PIN3_IN();
	PIN4_IN();
	PIN5_IN();
}
//Ϩ�����������
void Set_AllPin_INPUT(void)
{
    PIN1_IN();
    PIN2_IN();
    PIN3_IN();
    PIN4_IN();
    PIN5_IN();
}


/*
*	  | 1  | 2  | 3  | 4  | 5  ����
*	1 |    | B3 | D3 | F3 | G3
*	2 | A3 |    | B2 | D2 | E2
*	3 | C3 | A2 |    | C2 | F2
*	4 | E3 | C1 | B1 |    | G2
*	5 |    | I  | J  |    |  
*  ����
*/
//1�����ͣ�����ʾB3 D3 F3 G3
void Display_Scan1(void)
{
    PIN1_L();				//����Pin1
    if(nums[unit] & BIT5)	//B3
    	PIN2_H();
    if(nums[unit] & BIT3)	//D3
		PIN3_H();
	if(nums[unit] & BIT1)	//F3
		PIN4_H();
	if(nums[unit] &BIT0)	//G3
		PIN5_H();
}

//2�����ͣ�����ʾA3 B2 D2 E2
void Display_Scan2(void)
{
    PIN2_L();
    if(nums[unit] &BIT6)	//A3
    	PIN1_H();
	if(nums[tens] & BIT5)	//B2
		PIN3_H();
	if(nums[tens] & BIT3)	//D2
		PIN4_H();
	if(nums[tens] & BIT2)	//E2
		PIN5_H();
}

//3�����ͣ�����ʾC3 A2 C2 F2
void Display_Scan3(void)
{
    PIN3_L();
    if(nums[unit] & BIT4)	//C3
    	PIN1_H();
	if(nums[tens] & BIT6)	//A2
		PIN2_H();
	if(nums[tens] & BIT4)	//C2
		PIN4_H();
	if(nums[tens] & BIT1)	//F2
		PIN5_H();
}

//4�����ͣ�����ʾE3 C1 B1 G2
void Display_Scan4(void)
{
    PIN4_L();
    if(nums[unit] & BIT2)			//E3
    	PIN1_H();
	if(num_hund[hundreds] & BIT2)	//C1
		PIN2_H();
	if(num_hund[hundreds] & BIT3)	//B1
		PIN3_H();
	if(nums[tens] & BIT0)			//G2
		PIN5_H();
}

//5�����ͣ�����ʾ J(�ٷֱ�) I����磩
void Display_Scan5(void)
{
	PIN5_L();
	if(num_hund[hundreds] & BIT1)	//I
		PIN3_H();
	if(num_hund[hundreds] & BIT0)	//J
		PIN2_H();
}

void Display(void)
{
    static u8 scan_cnt;//����ɨ��
    Set_AllPin_INPUT();//��Ӱ����

    switch(scan_cnt)
    {
      case 0:Display_Scan1();scan_cnt++;break;
      case 1:Display_Scan2();scan_cnt++;break;
      case 2:Display_Scan3();scan_cnt++;break;
      case 3:Display_Scan4();scan_cnt++;break;
      case 4:Display_Scan5();scan_cnt=0;break;
      default:scan_cnt=0;break;
    }
}
