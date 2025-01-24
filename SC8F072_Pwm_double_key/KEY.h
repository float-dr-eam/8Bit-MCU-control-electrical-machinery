#ifndef __KEY_H
#define __KEY_H
#include "SC8F072.h"
#include <stdbool.h>

//129个元素

/*const unsigned char index_wave[] = 
{
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
    32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62,
    64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94,
    96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126,
    128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158,
    160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190,
    192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222,
    224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254,
    255 // 最后一个元素是255
};*/
extern bool breath_TFlag;
const unsigned char duty_steps[6] = {50, 60, 70, 80, 90,0};
//按键和PWM
unsigned char pwm_duty = 0;       // 当前 PWM 占空比索引（5 档）
unsigned char LED_num=0;           //LED按键索引

extern unsigned int Time_delay; //显示延时
extern bool T_flag; // LED刷新标志

extern bool button_sflag; // 按键短状态标志
extern bool button_lflag; // 按键长状态标志

extern bool LED_sflag;  // LED按键状态标志
extern bool LED_lflag;  // LED按键状态标志

//void delay(unsigned int ms);
//void breath_LED(void);
void Button_response(void);

#endif