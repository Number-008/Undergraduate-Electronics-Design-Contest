/*
 * delay.h
 *
 *  Created on: 2013-1-28
 *  Author: Qin Hai Cheng
 */
#ifndef DELAY_H_
#define DELAY_H_

#include "alt_types.h"

void Delay_Timer_Init(void);
void delay_ms(alt_u16 n);
void delay_us(alt_u16 n);

#endif /* DELAY_H_ */
