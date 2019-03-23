#include "STC15.h"
#include "PWM.h"
#include "IO.h"
int lastDutyPWM3 = -1;
int lastDutyPWM4 = -1;
int lastDutyPWM5 = -1;
int lastDutyPWM6 = -1;

//Enable PWM2 et PWM3

void PWM_Init()
{
	//IO P-P Registers Setup
//	pinMode(3, 7, OUTPUT_PP); 
	pinMode(2, 1, OUTPUT_PP); 
	pinMode(2, 2, OUTPUT_PP); 
	pinMode(2, 3, OUTPUT_PP); 
	pinMode(0, 7, OUTPUT_PP);
	P0M0 &=~0xc0;
	P0M1 &=~0xc0;
	P0&=~0xc0;
	P2M0 &=~0x0e;
	P2M1 &=~0x0e;
	P2&=~0x0e;
	P3M0 &=~0x80;
	P3M1 &=~0x80;
	P3&=~0x80;
	//PWM Registers Setup
	P_SW2 |= 0x80;
	PWMCFG = 0x00;
	PWMCKS = 0x0f; //of	
	PWMC = PWM_CYCLE;
//	PWM2CR = 0x00;
// PWM6CR|=(1<<3);
//	PWM2T1 = 0x0000;
//	PWM2T2 = 0x0001;
	PWM3CR = 0x00;
	PWM4CR = 0x00;
	PWM5CR = 0x00;
	PWM6CR = 0x08;
	PWM3T1 = 0x0000;
	PWM3T2 = 0x0001;

	PWM4T1 = 0x0000;  
	PWM4T2 = 0x0001;
	
	PWM5T1 = 0x0000;
	PWM5T2 = 0x0001;
	
	PWM6T1 = 0x0000;
	PWM6T2 = 0x0001;
	PWMCR = 0x3f; //-316
	PWMCR |= 0x80;
	P_SW2 &= ~0x80;
	//Reset lastDuty Value
//	lastDutyPWM2 = -1;
	lastDutyPWM3 = -1;
	lastDutyPWM4 = -1;
	lastDutyPWM5 = -1;
	lastDutyPWM6 = -1;



}

//PWM2 Duty Control
/*void PWM2_Output(unsigned int duty)
{
	if(duty == lastDutyPWM2)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x01;
		PWM2 = duty == PWM_DUTY_MAX;
	}
	else
	{
		P_SW2 |= 0x80;
		PWM2T1 = 0x00;
		PWM2T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x01;
	}
	lastDutyPWM2 = duty;
}
*/

//PWM3 Duty Control
void PWM3_Output(unsigned int duty)
{
	if(duty == lastDutyPWM3)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x02;
		PWM3 = duty == PWM_DUTY_MAX; 
	}
	else
	{
		P_SW2 |= 0x80;
		PWM3T1 = 0x00;
		PWM3T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x02;

	}
	lastDutyPWM3 = duty;

}
//PWM4 Duty Control
void PWM4_Output(unsigned int duty)
{
	if(duty == lastDutyPWM4)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x04;
		PWM4 = duty == PWM_DUTY_MAX; 
	}
	else
	{
		P_SW2 |= 0x80;
		PWM4T1 = 0x00;
		PWM4T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x04;
	}
	lastDutyPWM4 = duty;
}
//PWM5 Duty Control
void PWM5_Output(unsigned int duty)
{
	if(duty == lastDutyPWM5)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x08;
		PWM5 = duty == PWM_DUTY_MAX; 
	}
	else
	{
		P_SW2 |= 0x80;
		PWM5T1 = 0x00;
		PWM5T2 = duty * PWM_CYCLE / 100;
		P_SW2 &= ~0x80;
		PWMCR |= 0x08;
	}
	lastDutyPWM5 = duty;
}
//PWM6 Duty Control
void PWM6_Output(unsigned int duty)
{
	
	if(duty == lastDutyPWM6)return;
	if(duty == PWM_DUTY_MIN || duty == PWM_DUTY_MAX)
	{
		PWMCR &= ~0x10;
		PWM6 = duty == PWM_DUTY_MAX; 
	}
	else
	{
		P_SW2 |= 0x80;
		PWM6T1 = 0x00;
		PWM6T2 = duty * PWM_CYCLE / 100;//
		P_SW2 &= ~0x80;
		PWMCR |= 0x10;
	}
	lastDutyPWM6 = duty;
//	PWMCR|=(unsigned char)(1<<7);//开启PWM计数; //此句记得放最后
}

//Dispose PWM Function
/*void PWM_Dispose()
{
	P_SW2 |= 0x80;
	PWMCR = 0x00;
	P_SW2 &= ~0x80;
	PWM2 = PWM3 = 0;
}
*/
