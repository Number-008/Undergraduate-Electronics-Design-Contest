#ifndef __DELAY_H
#define __DELAY_H	
#include "my_types.h"

#define DELAY_MODE (2)//模式选择：1--只用定时器延时，2--只用程序延时，3--两种都用

#if (DELAY_MODE==1)
 void Delay_Init(void);
 void delay_us(u16 n);//n<65536
#endif

#if (DELAY_MODE==2)
 void delay(u8 i);
#endif

#if (DELAY_MODE==3)
 void Delay_Init(void);
 void delay_us(u16 n);//n<65536
 void delay(u8 i);
#endif


#endif