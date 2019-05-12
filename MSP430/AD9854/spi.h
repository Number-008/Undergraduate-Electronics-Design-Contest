/*
 * spi.h
 *
 *  Created on: 2013-7-21
 *      Author: qin
 */

#ifndef SPI_H_
#define SPI_H_

void SpiInit(void);
void SpiWriteDat(u8 c);
u8 SpiReadDat(void);
u8 SpiWriteData(u8 c);
void SpiSetCK(u8 P);
#endif /* SPI_H_ */
