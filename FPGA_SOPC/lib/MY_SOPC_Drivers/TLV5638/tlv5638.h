/*
 * tlv5638.h
 *
 *  Created on: 2013-5-19
 *      Author: Qin Hai Cheng
 */

#ifndef TLV5638_H_
#define TLV5638_H_
#include "system.h"
#include "alt_types.h"
#include "io.h"
extern alt_u16 TLV5638;
#define CS 		 *(volatile unsigned long *)(SPI_BASE | (1 << 31))
#define SCLK  	 *(volatile unsigned long *)(SPI_BASE +0x04| (1 << 31))
#define DIN  	 *(volatile unsigned long *)(SPI_BASE +0x08| (1 << 31))
void TLV5638_Write(alt_u16 dat);
void TLV5638_Out(alt_u16 dat);
#endif /* TLV5638_H_ */
