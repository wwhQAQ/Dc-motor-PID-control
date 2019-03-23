#ifndef __STDFUNC_H__
#define __STDFUNC_H__

#include "STC15.h"
#include "IO.h"
#include "PWM.h"

void delay_ms(unsigned int t);
int maxInt(int numA, int numB);
double maxDouble(double numA, double numB);
int minInt(int numA, int numB);
double minDouble(double numA, double numB);

#endif
