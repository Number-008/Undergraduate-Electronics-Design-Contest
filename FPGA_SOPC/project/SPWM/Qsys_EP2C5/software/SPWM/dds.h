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

#define FREQW_L(data)      	IOWR(DDS_BASE,0,data)
#define FREQW_H(data)      	IOWR(DDS_BASE,1,data)
#define PHASEW(data)       	IOWR(DDS_BASE,2,data)
extern  alt_32 Freq;
void WriteFreq(double f);
void printf_Freq(void);


#endif /* DDS_H_ */
