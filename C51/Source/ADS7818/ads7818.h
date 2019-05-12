#ifndef __ADS7818_H
#define __ADS7818_H
#include<absacc.h>
#include "my_types.h"

sbit CLK=P1^3;
sbit DATA=P1^4;
sbit CONV=P1^5;
u16 Read_ADS7818(void);
u16 Filter(void);
void printf_AD(void);

#endif