/*
 * ads8513.h
 *
 *  Created on: 2013-7-20
 *      Author: Qin Hai Cheng
 */

#ifndef ADS8513_H_
#define ADS8513_H_

#include "msp430G2553.h"

#define CONV_H  P2OUT |= BIT4
#define CONV_L  P2OUT &= ~BIT4

#define DATACLK_H  P2OUT |= BIT5
#define DATACLK_L  P2OUT &= ~BIT5
void ADS8513Init(void);
u16 ADS8513(void);
void Printf_AD(void);
#endif /* ADS8513_H_ */
