#ifndef _LED_188_H
#define _LED_188_H


#include "SC8F072.h"


#define u8    unsigned char
#define u16    unsigned int
#define u32    unsigned long

#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80

//把连接到数码管脚的IO口配置为输入模式，注意这些引脚不要开启上拉或下拉，引起不必要的麻烦
#define PIN1_IN()       TRISB0 = 1;    //PB0对应数码管PIN1
#define PIN2_IN()       TRISB1 = 1;    //PB1对应数码管PIN2
#define PIN3_IN()       TRISB2 = 1;    //PB2对应数码管PIN3
#define PIN4_IN()       TRISB3 = 1;    //PB3对应数码管PIN4
#define PIN5_IN()       TRISB4 = 1;    //PB4对应数码管PIN5

//把单片机IO口配置为输出模式，输出低电平
#define PIN1_L()        TRISB0 = 0;RB0 = 0;
#define PIN2_L()        TRISB1 = 0;RB1 = 0;
#define PIN3_L()        TRISB2 = 0;RB2 = 0;
#define PIN4_L()        TRISB3 = 0;RB3 = 0;
#define PIN5_L()        TRISB4 = 0;RB4 = 0;

//把单片机IO口配置为输出模式，输出高电平
#define PIN1_H()        TRISB0 = 0;RB0 = 1;
#define PIN2_H()        TRISB1 = 0;RB1 = 1;
#define PIN3_H()        TRISB2 = 0;RB2 = 1;
#define PIN4_H()        TRISB3 = 0;RB3 = 1;
#define PIN5_H()        TRISB4 = 0;RB4 = 1;
void Led_Gpio_Init(void);
void Charge_num(void);
void Uncharge_num(void);
void Motor_num(void);
void Set_AllPin_INPUT(void);
void Display(void);

#endif
