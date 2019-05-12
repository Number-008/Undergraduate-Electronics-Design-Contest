#ifndef __AD9851_H
#define __AD9851_H
#include<absacc.h>
#include "my_types.h"
extern u16 Fraq;
extern u8 Phase;

sbit WCLK=P1^0;
sbit FQUD=P1^1;
sbit DDS=P1^2;

void AD9851WriteData(void);
void printf_Phase(void);
void printf_Fraq(void);
#endif