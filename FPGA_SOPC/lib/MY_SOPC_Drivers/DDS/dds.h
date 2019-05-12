/*
 * dds.h
 *
 *  Created on: 2013-7-12
 *  Author: Qin Hai Cheng
 */
#ifndef DDS_H_
#define DDS_H_


#include "alt_types.h"
#include "system.h"
#include "io.h"

#define FREQW_L(data)      	IOWR(DDS_BASE,0,data)
#define FREQW_H(data)      	IOWR(DDS_BASE,1,data)
#define PHASEW(data)       	IOWR(DDS_BASE,2,data)

#define Fmax 50000000
extern  double Freq;
extern  float Phasew;

void WriteFreq(double n);
void DDS_OUT(double n);
void DDS_Phasew(float n);

#endif /* DDS_H_ */
