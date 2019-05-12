/*
 * PhaseMeasure.h
 *
 *  Created on: 2013-8-24
 *      Author: qin
 */

#ifndef PHASEMEASURE_H_
#define PHASEMEASURE_H_
#include "system.h"
#include "alt_types.h"

#define ReadPhase IORD(PHASE_MEASURE_BASE,0)
#define ReadCycle IORD(PHASE_MEASURE_BASE,1)

double ReadReg(alt_u32 R);
void TimeAuto(double n,alt_u16 x,alt_u16 y);

#endif /* PHASEMEASURE_H_ */
