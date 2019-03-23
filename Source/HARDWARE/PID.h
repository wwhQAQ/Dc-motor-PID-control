#ifndef __PID_H__
#define __PID_H__

#include "STC15.h"
#include "IO.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"

//PID Paras

extern int  runpuls;
//extern xdata int RANGE[4];

//Data for Apply
//extern u8 PIDservoAngle;


int Incremental_PI (int Encoder,int Target);
int Position_PID (int Encoder,int Target);
int Position_PID_COM1 (int Encoder,int Target);
int Position_PID_COM2 (int Encoder,int Target);
int Position_PID_COM3 (int Encoder,int Target);
int Position_PID_COM4 (int Encoder,int Target);
int Xianfu_Pwm(int pwm_xf);
void speed(int user_input_speed);
int angle(int input,char COM);
void PID_Setup(float PID_KP, float PID_KI, float PID_KD);

#endif

