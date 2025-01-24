#ifndef __PWM_H
#define __PWM_H
#include "SC8F072.h"

void PWM_Init(void);
void Set_PWM(unsigned char channel, unsigned char duty);

#endif