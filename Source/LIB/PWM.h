#ifndef __PWM_H__
#define __PWM_H__

#include "STC15.h"
#include "IO.h"
#define PWM_CYCLE 6000L
#define PWM_DUTY_MAX 100
#define PWM_DUTY_MIN 0

//sbit PWM2 = P3^7;
sbit PWM3 = P2^1;
sbit PWM4 = P2^2;
sbit PWM5 = P2^3;
sbit PWM6 = P0^7;

//extern int lastDutyPWM2;
extern int lastDutyPWM3;
extern int lastDutyPWM4;
extern int lastDutyPWM5;
extern int lastDutyPWM6;

void PWM_Init();
void PWMInit();
//void PWM2_Output(unsigned int duty);
void PWM3_Output(unsigned int duty);
void PWM4_Output(unsigned int duty);
void PWM5_Output(unsigned int duty);
void PWM6_Output(unsigned int duty);
void PWM_Dispose();

#endif
