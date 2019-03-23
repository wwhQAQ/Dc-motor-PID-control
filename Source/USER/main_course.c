#include "STC15.h"
#include "IO.h"
#include "PWM.h"
#include "STDFUNC.h"
#include "USART.h"
#include "PID.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"
extern int RANGE[4];
int user_input_angel =0;
int user_input_speed =0,spppp=0;
int last_in_angel[4]={0,0,0,0},STATE[4];
extern int flag1,aaa,FINISH;
extern int puls_count1;
extern bit T_3,T_0,T_1,T_2;
//2ms@30.0000Mhz
//void Timer2Init(void)
//{
//	AUXR |= 0x04;		
//	T2L = 0xA0;		
//	T2H = 0x15;		
//	AUXR |= 0x10;	
//	EA = 1;
//}
//30um@30.0000Mhz
void Timer1Init(void)		
{
	AUXR |= 0x40;		
	TMOD &= 0x0F;		
	TL1 = 0xD0;		
	TH1 = 0x8A;		
	TF1 = 0;	
	TR1 = 1;	
	ET1=1;
  EA=1;
}

void Motor_cal(int in_angel,int in_speed,char COM) 
{
   int ADJUST=2;  //wtf
   if(last_in_angel[COM]!=in_angel)STATE[COM]=2;
	 if(in_angel>0)
     {
	   if(RANGE[COM]<=in_angel-ADJUST&&STATE[COM]==2)
		 {

			spppp=in_speed;
			FINISH=1;
			
		 }
     else  
		 { 
			STATE[COM]=1;
			spppp=angle(in_angel,COM);
		  FINISH=0;
	
		 }
	 }
 else	if(in_angel<0)
	 {
		 if(RANGE[COM]>=in_angel+ADJUST&&STATE[COM]==2)
	   {
		 spppp=(-in_speed);
     FINISH=1;			 
		 }
		 else
		 {		 
     STATE[COM]=1;
		 spppp=angle(in_angel,COM);
     FINISH=0;			 
		 }
	 } 

//---------------------------------// 
    switch(COM)
		{
			case 0:
			Motor_f(spppp);
			break;
			case 1:
			Motor_s(spppp);
			break;
			case 2:
			Motor_t(spppp);
			break;
			case 3:
			Motor_fo(spppp);
			break;
		}
		last_in_angel[COM]=in_angel;
}

// Main Control
void main()
{
  T_3=P32;
  T_0=P36;
	T_1=P33;
	T_2=P37;
//Init Devices 
	Timer0Init();
//Timer1Init();
//Timer3Init();
  Motor_Init();	
	IO_INIT();  //exit
//PWM_Init();
  Serial1_Begin(9600);
	PID_Setup(3.5,0,5);//10 3  6 4
  delay_ms(500);
	Serial1_SendStr("Hello");
	while(1)
	{   
  
	if(flag1==1)
	{
	  Motor_cal(180,100,0);
	  Motor_cal(180,100,1);
		Motor_cal(180,100,2);
		Motor_cal(180,100,3);
	}
	if(flag1==0)
	{
	  Motor_cal(-180,50,0);
	  Motor_cal(-180,50,1);
		Motor_cal(-180,50,2);
		Motor_cal(-180,50,3);
	}		
	
	//Serial1_SendByte(RANGE[0]);
	//Serial1_SendByte(start_flag);
	//Serial1_SendByte(puls_count1);
	}
}
 