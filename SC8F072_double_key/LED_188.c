#include "LED_188.h"
#include <stdbool.h>

volatile u8 hundreds = 4;	//百位，0不显示，1仅百分比，2百分比+供电，3-百分比+百位，4全部显示
volatile u8 tens = 4; 		//十位，10-F，11-不显示
volatile u8 unit = 2;		//个位，10-F，11-不显示 
   
volatile u8 power_percent;
volatile u8 pwm_duty ;       // 当前 PWM 占空比索引（5 档）

void Charge_num(void)
{
	bool hundred = (bool)(power_percent / 100);  // 百位
	tens = (u8)((power_percent % 100) / 10); 		//十位，10-F，11-不显示
	unit = (u8)(power_percent % 10);		//个位，10-F，11-不显示
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
	bool hundred = (bool)(power_percent / 100);  // 百位
	tens = (u8)((power_percent % 100) / 10); 		//十位，10-F，11-不显示
	unit = (u8)(power_percent % 10);		//个位，10-F，11-不显示
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
	hundreds =0;  // 百位
	tens = 0; 		//十位，10-F，11-不显示
	unit = (u8)(pwm_duty+1) ;		//个位，10-F，11-不显示
}
/*
*	百位，百分比，充电指示显示
*					BIT3	BIT2	BIT1	BIT0
*					B1		C1		I		J
*	0-不显示		    0		0		0		0		0x00
*	1-仅百分比		0		0		0		1		0x01
*	2-百分比+充电	0		0		1		1		0x03							
*	3-百分比+百位	1		1		0		1		0x0D
*	4-全部显示		1		1		1		1		0x0F
*/
u8 num_hund[5] = {0x00, 0x01, 0x03,	0x0D, 0x0F};
/*
*	十位显示和个位显示
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
*	不显示			0		0		0		0		0		0		0		0x00
*/
u8 nums[12] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0x47, 0x00};

//数码管引脚初始化
void Led_Gpio_Init(void)
{
	PIN1_IN();
	PIN2_IN();
	PIN3_IN();
	PIN4_IN();
	PIN5_IN();
}
//熄灭所有数码管
void Set_AllPin_INPUT(void)
{
    PIN1_IN();
    PIN2_IN();
    PIN3_IN();
    PIN4_IN();
    PIN5_IN();
}


/*
*	  | 1  | 2  | 3  | 4  | 5  拉高
*	1 |    | B3 | D3 | F3 | G3
*	2 | A3 |    | B2 | D2 | E2
*	3 | C3 | A2 |    | C2 | F2
*	4 | E3 | C1 | B1 |    | G2
*	5 |    | I  | J  |    |  
*  拉低
*/
//1脚拉低，可显示B3 D3 F3 G3
void Display_Scan1(void)
{
    PIN1_L();				//拉低Pin1
    if(nums[unit] & BIT5)	//B3
    	PIN2_H();
    if(nums[unit] & BIT3)	//D3
		PIN3_H();
	if(nums[unit] & BIT1)	//F3
		PIN4_H();
	if(nums[unit] &BIT0)	//G3
		PIN5_H();
}

//2脚拉低，可显示A3 B2 D2 E2
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

//3脚拉低，可显示C3 A2 C2 F2
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

//4脚拉低，可显示E3 C1 B1 G2
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

//5脚拉低，可显示 J(百分比) I（充电）
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
    static u8 scan_cnt;//逐行扫描
    Set_AllPin_INPUT();//消影作用

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
