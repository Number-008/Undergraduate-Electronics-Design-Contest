#ifndef __DELAY_H
#define __DELAY_H	
#include "my_types.h"

#define DELAY_MODE (2)//ģʽѡ��1--ֻ�ö�ʱ����ʱ��2--ֻ�ó�����ʱ��3--���ֶ���

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