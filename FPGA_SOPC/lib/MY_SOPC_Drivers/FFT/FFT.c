#include <math.h>
#include <stdio.h>
#include "FFT.h"
#include "ili9320.h"
compx fft[512];
alt_u32 lBUFMAG[256];
compx EE(compx b1,compx b2)
{
      compx b3;
      b3.real=b1.real*b2.real-b1.imag*b2.imag;
      b3.imag=b1.real*b2.imag+b1.imag*b2.real;
      return(b3);
}
void FFT(compx *xin,int N)  //�Ը����ṹ�����N��FFT�任����������ͻ�ԭ�ṹ��
{
    int f,m,LH,nm,i,k,j,L;
    double p , ps ;
    int le,B,ip;
    const double  pi=3.141592653589793;
    compx w,t;
    LH=N/2;
    f=N;
    for(m=1;(f=f/2)!=1;m++){;}
    nm=N-2;   
    j=N/2;
    
    for(i=1;i<=nm;i++)                    //����
    {
        if(i<j){t=xin[j];xin[j]=xin[i];xin[i]=t;}
        k=LH;
        while(j>=k){j=j-k;k=k/2;}
        j=j+k;
    }

    for(L=1;L<=m;L++)
    { 
        le=(int)pow((double)2,L);                     //�˷�(ע�⣬VS2005��pow�����ĵ�һ����������Ϊ˫���ȸ�����)
        B=le/2;
         for(j=0;j<=B-1;j++)
          {
               p=pow((double)2,m-L)*j;
               ps=2*pi/N*p;
               w.real=cos(ps);                       //��ת����
               w.imag=-sin(ps);
               for(i=j;i<=N-1;i=i+le)                //���μ���
                 {
                      ip=i+B;
                      t=EE(xin[ip],w);
                      xin[ip].real=xin[i].real-t.real;
                      xin[ip].imag=xin[i].imag-t.imag;
                      xin[i].real=xin[i].real+t.real;
                      xin[i].imag=xin[i].imag+t.imag;
                 }
          }
    }
}

//-------------------------------------------------------------------------
//ȡģ����
//-------------------------------------------------------------------------

void FFTpowerMag(compx *xin,alt_u32 *BUFMAG, int N)
{
	alt_u32 i;
  for (i=0; i < N; i++)
  {
     double Mag = (sqrt(xin[i].real*xin[i].real+ xin[i].imag*xin[i].imag))*2.0f/N;		 // ��ƽ����,�ٿ���
     BUFMAG[i] = (alt_u32)(Mag);
   
  }
  BUFMAG[0] =	BUFMAG[0]/4;//ֱ���ķ�ֵ
}











