#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"
#include "PWM.h"
#include "MOTOR.h"

//Motor Init
void Motor_Init()
{
	int i;
	PWM_Init();
	for(i = AIN1; i <= AIN2_2 ; i++)  
		pinMode(4, i, OUTPUT_PP);	
	for(i = BIN2_1; i <= BIN2_2;i++)
		pinMode(0, i, OUTPUT_PP);
}

//Set Motor First
void Motor_f(int value)
{
	if(value > 0)
	{
	 //digitalWrite(OUTPUT_PP, 4, AIN1, 1); //0
	 //digitalWrite(OUTPUT_PP, 4, AIN2, 0);//1
    P40=1;
		P41=0;
		
	}
	else
	{
		//digitalWrite(OUTPUT_PP, 4, AIN1, 0);
		//digitalWrite(OUTPUT_PP, 4, AIN2, 1);
		P40=0;
		P41=1;
		value *= -1;
	}
	PWM3_Output(value);
}

//Set Motor Second
void Motor_s(int value)
{
	if(value > 0)
	{
	//	digitalWrite(OUTPUT_PP, 4, BIN1, 1);    //u8 IOMode, u8 IOGroup, u8 IONumber, u8 content)
	//	digitalWrite(OUTPUT_PP, 4, BIN2, 0);
		P42=1;
		P43=0;
	}
	else
	{
	//	digitalWrite(OUTPUT_PP, 4, BIN1, 0);
	//	digitalWrite(OUTPUT_PP, 4, BIN2, 1);
		P42=0;
		P43=1;
		value *= -1;
	}
	PWM4_Output(value);
}
//Set Motor Third
void Motor_t(int value)
{
	if(value > 0)
	{
		//digitalWrite(OUTPUT_PP, 4, AIN2_1, 1);    //u8 IOMode, u8 IOGroup, u8 IONumber, u8 content)
		//digitalWrite(OUTPUT_PP, 4, AIN2_2, 0);
		P44=1;
		P45=0;
	}
	else
	{
		//digitalWrite(OUTPUT_PP, 4, AIN2_1, 0);
		//digitalWrite(OUTPUT_PP, 4, AIN2_2, 1);
		P44=0;
		P45=1;
		value *= -1;
	}
	PWM5_Output(value);
}
//Set Motor Fourth
void Motor_fo(int value)
{

	if(value > 0)
	{		
	//digitalWrite(OUTPUT_PP, 0, BIN2_1, 1);
  //digitalWrite(OUTPUT_PP, 0, BIN2_2, 0);
	  P05=1;
		P06=0;		
	}
	else
	{

	//digitalWrite(OUTPUT_PP, 0, BIN2_1, 0);    //u8 IOMode, u8 IOGroup, u8 IONumber, u8 content)
	//digitalWrite(OUTPUT_PP, 0, BIN2_2, 1);
		P05=0;
   	P06=1;		
		value *= -1;
	}
	PWM6_Output(value);	
}

