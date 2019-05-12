#include"delay.h"

#if (DELAY_MODE==1)
void Delay_Init(void)
{
	TH0=0xff;
	TL0=0xff;
  	//IE=0xff;
	TMOD=0x01;
	ET0=0; 
	TR0=0;
	//EA=0;
}

void delay_us(u16 n)//n<65536
{
	TH0=(65536-n)/256;
	TL0=(65536-n)%256;
	TR0=1;
	while(!TF0);
	TR0=0;
	TF0=0;	
}
#endif

#if (DELAY_MODE==2)
void delay(u8 i)
{
	u16 j;
	while(i--)
	{
		for(j=120;j>0;j--);
	}
}

#endif


#if (DELAY_MODE==3)
void Delay_Init(void)
{
	TH0=0xff;
	TL0=0xff;
  	//IE=0xff;
	TMOD=0x01;
	ET0=0; 
	TR0=0;
	//EA=0;
}

void delay_us(u16 n)//n<65536
{
	TH0=(65536-n)/256;
	TL0=(65536-n)%256;
	TR0=1;
	while(!TF0);
	TR0=0;
	TF0=0;	
}

void delay(u8 i)
{
	u8 j;
	while(i--)
	{
		for(j=120;j>0;j--);
	}
}

#endif