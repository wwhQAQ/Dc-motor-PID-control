#include "STC15.h"
#include "STDFUNC.h"
#include "SERVO.h"
#include "USART.h"
#include "PID.h"
#include "MOTOR.h"
#include "PWM.h"
#include "math.h"
int runpuls=0,aaaaa=0;
int puls_count1=0;
int RANGE[]={0,0,0,0};
int FINISH=0;
bit T_3=0,S_3=0,T_0=0,S_0=0,S_1=0,T_1=0,S_2=0,T_2=0;
//10s@30.000Mhz
void Timer0Init(void)  
{
	EA  = 0;
	ET0 = 0;
	TR0 = 0;
  AUXR |= 0x80;		
  TMOD &= 0xF0;		
//	TL0 = 0x80;		
//	TH0 = 0xF8;	
//	TL0 = 0x7C;		//??????
//	TH0 = 0xFC;		//?????? 30
	TL0 = 0xB6;		//??????
	TH0 = 0xFE;		//??????  10
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
	EA  = 1;
}
                                                                                                                                                  
void Timer0_ISP() interrupt 1 
{
 static char COM_POLL=0;
	switch(COM_POLL)
	 {
		 
		 case 0:
		 {
			 S_0=P26;
			if(S_0^T_0)
			{
					T_0=S_0;
					if(S_0==0)
					{
							if(P36==1)
							{
									RANGE[0]++;
							}
							else
							{
									RANGE[0]--;
							}
					}
					else
					{
							if(P36==0)
							{
									RANGE[0]++;
							}
							else
							{
									RANGE[0]--;
							}
					}
		 	}
			COM_POLL=1;
		}  
			break;
   	 
   case 1:
    {
     
		 S_1=P25;
			if(S_1^T_1)
			{
					T_1=S_1;
					if(S_1==0)
					{
							if(P33==1)
							{
									RANGE[1]++;
							}
							else
							{
									RANGE[1]--;
							}
					}
					else
					{
							if(P33==0)
							{
									RANGE[1]++;
							}
							else
							{
									RANGE[1]--;
							}
					}

	  		}  
      COM_POLL=2;
        }
        break;
	 case 2:
		 
	 {
		S_2=P24;
		if(S_2^T_2)
		{
				T_2=S_2;
				if(S_2==0)
				{
						if(P37==1)
						{

								RANGE[2]++;
						}
						else
						{

								RANGE[2]--;
						}
				}
				else
				{
						if(P37==0)
						{

							 RANGE[2]++;
						}
						else
						{
							 RANGE[2]--;
						}
				}

		}
      COM_POLL=3;
	 }
	 break;
		 case 3:		 
		 {
	    S_3=P20;
      if(S_3^T_3)
		{
				T_3=S_3;
				if(S_3==0)
				{
						if(P32==1)
						{
								RANGE[3]++;
						}
						else
						{
								RANGE[3]--;
						}
				}
				else
				{
						if(P32==0)
						{
								RANGE[3]++;
						}
						else
						{
								RANGE[3]--;
						}
				}
	 	}
		
		COM_POLL=0;
	}
     break;
   	
   }
}




