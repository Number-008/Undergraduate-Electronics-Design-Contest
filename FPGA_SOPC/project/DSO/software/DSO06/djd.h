/*
 * DJD.h
 *
 *  Created on: 2013-5-18
 *      Author: qin
 */

#ifndef DJD_H_
#define DJD_H_
#include "system.h"
#include "io.h"
#define ReadRef IORD(DJD_BASE,0)
#define ReadTest IORD(DJD_BASE,1)
void DJDaut(double n);
void ReadDJD(void);
double cp(void);
extern double djd_Freq;
#endif /* DJD_H_ */