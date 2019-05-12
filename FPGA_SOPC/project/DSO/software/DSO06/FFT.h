#ifndef __FFT_H
#define __FFT_H
#include "alt_types.h"




typedef struct
{
    float real;//Êµ²¿
    float imag;//Ðé²¿
}compx;
extern compx fft[512];
extern alt_u32 lBUFMAG[256];

void FFT(compx *xin,int N);
void FFTpowerMag(compx *xin,alt_u32 *BUFMAG, int N);
#endif
