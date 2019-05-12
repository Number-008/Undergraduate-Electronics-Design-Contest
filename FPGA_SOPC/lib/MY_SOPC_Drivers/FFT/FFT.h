#ifndef __FFT_H
#define __FFT_H
#include "alt_types.h"




typedef struct
{
    float real;//ʵ��
    float imag;//�鲿
}compx;
extern compx fft[512];
extern alt_u32 lBUFMAG[256];

void FFT(compx *xin,int N);
void FFTpowerMag(compx *xin,alt_u32 *BUFMAG, int N);
#endif
