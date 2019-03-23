#include "STC15.h"
#include "IO.h"
#include "MOTOR.h"
#include "SERVO.h"
#include "SENSOR.h"
#include "PID.h"
#include "USART.h"
//PID Paras
float Kp;
float Ki;
float Kd;
extern  int RANGE[4];
//Data for Apply
//u8 PIDservoAngle = 3600;
void PID_Setup(float PID_KP, float PID_KI, float PID_KD)
{
   Kp=PID_KP;
 	 Ki=PID_KI; 
	 Kd=PID_KD;	
}

int Incremental_PI (int Encoder,int Target) 
{ 	
	 float Kp=0.5,Ki=0.85;      //10  6.4-6.0     Kp=0.5,Ki=0.5; 0.85  Kp=0.8,Ki=0.8;  
	 static float Bias1=0,Last_bias1=0;
	 static int Pwm1=0;
	 Bias1=Encoder-Target; 
	 Pwm1+=Kp*(Bias1-Last_bias1)+Ki*Bias1; 
//   if(Bias1>100000) Bias1=100000; //===积分限幅
//   if(Bias1<-100000) Bias1=-100000; //===积分限幅 

	 Last_bias1=Bias1;	                                
	 return Pwm1;   
}

int Position_PID (int Encoder,int Target) //模板 
{ 	
	
	// float Kp=15,Ki=0.01;      //10  6.4-6.0   50 0.01 Kp=0.48,Ki=0.408,Kd=0; 
   float Kp=5,Ki=0,Kd=5;	   //0.0002   Kp=30,Ki=0.002; Kd=0.175ki↑ kd？ kp↓0.0075  22 Kp=13.2,Ki=0.5,Kd=0 0.001  5
	 int pwm=0,Pwm2=0;  //2 //6 2  
	 static  long  Integral_bias=0,Last_Bias=0,Bias=0;			
	 Bias=Encoder-Target;               
   if(Integral_bias>100) Integral_bias=100; //===积分限幅
   if(Integral_bias<-100) Integral_bias=-100; //===积分限幅     
	 Integral_bias+=Bias;	            
	 pwm=Kp*Bias+Ki*Integral_bias+Kd*(Bias-Last_Bias);
   Last_Bias=Bias;     	
		Pwm2=(int)pwm;
				if(pwm>0)	    
			{
				if(pwm-Pwm2>=0.5)
				{
					Pwm2=Pwm2+1;
				}
			}
			if(pwm<0)
			{
				if(Pwm2-pwm>=0.5)
				{
					Pwm2=Pwm2-1;
				}
			}
	
	if(Bias==1||Bias==-1)
	 return 0;  
	else
	 return Pwm2;           
}


int Position_PID_COM1 (int Encoder,int Target)
{ 	  
	 int pwm=0,Pwm2=0; 
	 static  long  Integral_bias=0,Last_Bias=0,Bias=0,TargetOLD;			
	 if(TargetOLD!=Target)	{Integral_bias=0;Last_Bias=0;Bias=0;}
	 Bias=Encoder-Target;   
   if(Integral_bias>100) Integral_bias=100; 
   if(Integral_bias<-100) Integral_bias=-100;   
	 Integral_bias+=Bias;	            
	 pwm=Kp*Bias+Ki*Integral_bias+Kd*(Bias-Last_Bias);
   Last_Bias=Bias;     	
		Pwm2=(int)pwm;
				if(pwm>0)	    
			{
				if(pwm-Pwm2>=0.5)
				{
					Pwm2=Pwm2+1;
				}
			}
			if(pwm<0)
			{
				if(Pwm2-pwm>=0.5)
				{
					Pwm2=Pwm2-1;
				}
			}
		TargetOLD=Target;
	if(Bias==1||Bias==-1)
	 return 0;  
	else
	 return Pwm2;           
}

int Position_PID_COM2 (int Encoder,int Target)
{ 	 
	 int pwm=0,Pwm2=0; 
	 static  long  Integral_bias=0,Last_Bias=0,Bias=0,TargetOLD;
   if(TargetOLD!=Target)	{Integral_bias=0;Last_Bias=0;Bias=0;}	
	 Bias=Encoder-Target;               
   if(Integral_bias>100) Integral_bias=100;
   if(Integral_bias<-100) Integral_bias=-100;    
	 Integral_bias+=Bias;	            
	 pwm=Kp*Bias+Ki*Integral_bias+Kd*(Bias-Last_Bias);
   Last_Bias=Bias;     	
		Pwm2=(int)pwm;
				if(pwm>0)	    
			{
				if(pwm-Pwm2>=0.5)
				{
					Pwm2=Pwm2+1;
				}
			}
			if(pwm<0)
			{
				if(Pwm2-pwm>=0.5)
				{
					Pwm2=Pwm2-1;
				}
			}
	TargetOLD=Target;
	if(Bias==1||Bias==-1)
	 return 0;  
	else
	 return Pwm2;           
}


int Position_PID_COM3 (int Encoder,int Target)
{ 	
	 int pwm=0,Pwm2=0;
	 static  long  Integral_bias=0,Last_Bias=0,Bias=0,TargetOLD;
   if(TargetOLD!=Target)	{Integral_bias=0;Last_Bias=0;Bias=0;}		
	 Bias=Encoder-Target;               
   if(Integral_bias>100) Integral_bias=100; 
   if(Integral_bias<-100) Integral_bias=-100; 
	 Integral_bias+=Bias;	            
	 pwm=Kp*Bias+Ki*Integral_bias+Kd*(Bias-Last_Bias);
   Last_Bias=Bias;     	
		Pwm2=(int)pwm;
				if(pwm>0)	    
			{
				if(pwm-Pwm2>=0.5)
				{
					Pwm2=Pwm2+1;
				}
			}
			if(pwm<0)
			{
				if(Pwm2-pwm>=0.5)
				{
					Pwm2=Pwm2-1;
				}
			}
	TargetOLD=Target;
	if(Bias==1||Bias==-1)
	 return 0;  
	else
	 return Pwm2;           
}

int Position_PID_COM4 (int Encoder,int Target)
{ 	

	 int pwm=0,Pwm2=0; 
	 static  long  Integral_bias=0,Last_Bias=0,Bias=0,TargetOLD;
  if(TargetOLD!=Target)	{Integral_bias=0;Last_Bias=0;Bias=0;}		
	 Bias=Encoder-Target;               
   if(Integral_bias>100) Integral_bias=100; 
   if(Integral_bias<-100) Integral_bias=-100;   
	 Integral_bias+=Bias;	            
	 pwm=Kp*Bias+Ki*Integral_bias+Kd*(Bias-Last_Bias);
   Last_Bias=Bias;     	
		Pwm2=(int)pwm;
				if(pwm>0)	    
			{
				if(pwm-Pwm2>=0.5)
				{
					Pwm2=Pwm2+1;
				}
			}
			if(pwm<0)
			{
				if(Pwm2-pwm>=0.5)
				{
					Pwm2=Pwm2-1;
				}
			}
			if(Bias)
	TargetOLD=Target;
	if(Bias==1||Bias==-1)
	 return 0;  
	else
	 return Pwm2;           
}


int Xianfu_Pwm(int pwm_xf)
{	
	  
	  int  Amplitude=100;
	  if (pwm_xf>Amplitude) pwm_xf = Amplitude;
		if (pwm_xf< -Amplitude) pwm_xf = -Amplitude;
    return 	pwm_xf;
}

//void speed(int user_input_speed)
//{
////#ifdef PROGRAMMER1
////	int sudu;
////		//	Serial1_SendByte(runpuls);			 //runpuls
////		  sudu=Incremental_PI(runpuls,user_input_speed);
////	    Xianfu_Pwm(sudu);
////			Motor_fo(sudu); //90-0 
////    
////#else
//  
//   	 Motor_fo(user_input_speed);
//	  
////#endif	
//}

int angle(int input,char COM)
	
{
	  int SPEED_OUT;
	  switch(COM)
		{
			case 0:
			{
			SPEED_OUT=Position_PID_COM1(RANGE[0],input);
			}
				break;
			case 1:
			{
			SPEED_OUT=Position_PID_COM2(RANGE[1],input);
			}
	      break;			
			case 2:
			{
			SPEED_OUT=Position_PID_COM3(RANGE[2],input); 			
			}
			  break;
			case 3:
			{
			SPEED_OUT=Position_PID_COM4(RANGE[3],input); 
			}
			  break;
		}
	  Xianfu_Pwm(SPEED_OUT);
	 // Motor_fo(-SPEED_OUT);//-wtf??
    return -SPEED_OUT;
}
