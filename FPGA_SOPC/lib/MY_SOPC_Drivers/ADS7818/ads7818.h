/*
 * dac7818.h
 *
 *  Created on: 2013-7-16
 *      Author: Qin Hai Cheng
 */
#ifndef __ADS7818_H
#define __ADS7818_H
#include "system.h"
#include "io.h"
#include "alt_types.h"

#define SCLK 	*(volatile unsigned long *) ((SPI_BASE +0x04)| (1 << 31))
#define MOSI 	*(volatile unsigned long *) ((SPI_BASE +0x08)| (1 << 31))
#define MISO 	*(volatile unsigned long *) ((SPI_BASE +0x0c)| (1 << 31))
#define SCS1	*(volatile unsigned long *) (SPI_BASE | (1 << 31))
#define SCS2	*(volatile unsigned long *) (SPI_CS2_BASE | (1 << 31))

alt_u16 Read_ADS7818(void);
void printf_AD(void);
alt_u16 Filter(void);

#endif
