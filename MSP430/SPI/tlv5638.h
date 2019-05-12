/*
 * tlv5638.h
 *
 *  Created on: 2013-5-19
 *      Author: Qin Hai Cheng
 */

#ifndef TLV5638_H_
#define TLV5638_H_
#include "msp430g2553.h"
extern u16 TLV5638;

void TLV5638_Write(u16 dat);
void TLV5638_Out(u16 dat);

#endif /* TLV5638_H_ */