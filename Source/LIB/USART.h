#ifndef __USART_H__
#define __USART_H__

#include "STC15.h"
#include "IO.h"
#include "STDFUNC.h"

//Define System Clock
#define MAIN_FOSC 30000000L
//Define Default BAUD rate
#define DEFAULT_BAUD 9600L 
//Define Read Buffer Length
#define READ_BUFFER_LENGTH 64

extern u8 readBuffer[READ_BUFFER_LENGTH];
extern u8 readBufferLength;
extern u8 readBufferHead;
extern u8 readBufferTail;

void Serial1_Begin(unsigned long BAUD);
void Serial1_SendByte(u8 s);
void Serial1_SendStr(u8 *s);
void Serial1_SendLenStr(u8 *s, int length);
u8 Serial1_Available();
u8 Serial1_ReadByte();

#endif

