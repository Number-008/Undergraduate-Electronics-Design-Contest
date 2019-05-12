/*
 * spi.h
 *
 *  Created on: 2013-7-21
 *      Author: Qin Hai Cheng
 */

#ifndef SPI_H_
#define SPI_H_

void SpiInit(void);
void SpiWriteDat(u8 c);
u8 SpiReadDat(void);
u8 SpiWriteData(u8 c);
u16 SpiSendData(u16 dat);
void SpiSetCLK(u16 fen);
void SpiSetCK(u8 P);
#endif /* SPI_H_ */
