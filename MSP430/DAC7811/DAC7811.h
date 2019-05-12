/*
 * DAC7811.h
 *
 *  Created on: 2013-7-11
 *      Author: fan_hang
 */
/*
P1.0 = SYNC, P1.1 = SCLK,P1.2 = SDI
*/

#ifndef  _DAC7811_H
#define  _DAC7811_H
#include "msp430G2553.h"
#define SYNC_H  P1OUT |= BIT0
#define SYNC_L  P1OUT &= ~BIT0

#define SCLK_H  P1OUT |= BIT1
#define SCLK_L  P1OUT &= ~BIT1

#define SDI_H  P1OUT |= BIT2
#define SDI_L  P1OUT &= ~BIT2

void DAC7811(u8 dB);
void Init_7811();

#endif
