/*
 * dds.h
 *
 *  Created on: 2013-7-12
 *      Author: qin
 */

#ifndef DDS_H_
#define DDS_H_


#include "alt_types.h"
#include "system.h"
#include "io.h"

#define FREQW_L(data)      				IOWR(DDS_BASE,0,data)
#define FREQW_H(data)      				IOWR(DDS_BASE,1,data)
#define PHASEW(data)       				IOWR(DDS_BASE,2,data)

#define DDS_DATA_WRITE(addr,data)       IOWR(RAM_WR_BASE,addr,data)
#define Fmax 50000000
extern  alt_u32 freq;
extern  alt_u16 pha;
void WriteFreq(double n);
void DDS_OUT(alt_u32 n);
void DDS_Phasew(float n);
void DDS_RAM_WR(alt_u8 n);
void DDS_Init(void);

#endif /* DDS_H_ */
