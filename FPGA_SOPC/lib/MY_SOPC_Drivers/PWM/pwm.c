/*
 * pwm.c
 *
 *  Created on: 2013-7-28
 *      Author:  Qin Hai Cheng
 */
#include"pwm.h"


void PWMDutyCycle(alt_u8 x,alt_u8 y,alt_u16 n)
{
	char BUF2[8];
	BUF2[0]=n/10000+0x30;
	BUF2[1]=n/1000%10+0x30;
	BUF2[2]=n/100%10+0x30;
	BUF2[3]='.';
	BUF2[4]=n/10%10+0x30;
	BUF2[5]=n%10+0x30;
	BUF2[6]='%';
	BUF2[7]='\0';
	LCD_ShowString(x,y,BUF2);
}
