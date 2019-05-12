#ifndef __KEY_H
#define __KEY_H	
#include "my_types.h"
#include<absacc.h>
sbit PGA_A0= P1^6;
sbit PGA_A1= P1^7;
extern bit k;
//extern u16 Vr;
extern u8 PGA;

#define READ_INT0 XBYTE[0xFD00]//Y5
#define KEY_1 XBYTE[0xFE00]//Y6
#define KEY_2 XBYTE[0xFF00]//Y7
							  
//void Key_Init(void);
//void Key_Scan(void);


#endif
