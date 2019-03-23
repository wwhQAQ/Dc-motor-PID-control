#include "STC15.h"
#include "IO.h"
#include "PWM.h"
#include "STDFUNC.h"

//Delay 1ms for 30Mhz Clock
void delay_ms(unsigned int t)
{
	unsigned char i, j;
	while(t--)
	{
		i = 30;
		j = 43;
		do
		{
			while (--j);
		}
		while (--i);
	}
}

//Select the max number
int maxInt(int numA, int numB)
{
	if(numA > numB)return numA;
	return numB;
}


//Select the max number
double maxDouble(double numA, double numB)
{
	if(numA > numB)return numA;
	return numB;
}


//Select the min number
int minInt(int numA, int numB)
{
	if(numA < numB)return numA;
	return numB;
}

//Select the min number
double minDouble(double numA, double numB)
{
	if(numA < numB)return numA;
	return numB;
}

