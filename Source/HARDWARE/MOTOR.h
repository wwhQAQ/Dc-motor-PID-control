#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "PWM.h"

#define AIN1 0
#define AIN2 1
#define BIN1 2
#define BIN2 3
#define AIN2_1 4
#define AIN2_2 5
#define BIN2_1 5
#define BIN2_2 6


void Motor_Init();
void Motor_f(int value);
void Motor_s(int value);
void Motor_t(int value);
void Motor_fo(int value);


#endif

