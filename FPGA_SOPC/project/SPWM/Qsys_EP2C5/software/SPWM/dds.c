#include "dds.h"
alt_32 Freq=1000;
void WriteFreq(double f)//2^56=72057594037927936;
{
	alt_u64 K;
	K=f*360287970.18963968;
	FREQW_L((alt_u32) K);
	FREQW_H((alt_u32)(K>> 32 ));
}

//œ‘ æ∆µ¬ ÷µ
void printf_Freq(void)
{
   char BUF1[9];
   BUF1[8]='\0';
   WriteFreq(Freq);
   if(Freq<1000)
   {
   	BUF1[0]=BUF1[1]=BUF1[2]=BUF1[3]=BUF1[4]=' ';
   	BUF1[5]=Freq/100+0x30;
	BUF1[6]=Freq/10%10+0x30;
	BUF1[7]=Freq%10+0x30;

	if(BUF1[5]==0x30 && BUF1[6]==0x30)
		BUF1[5]=BUF1[6]=' ';
		else if	(BUF1[5]==0x30)
			BUF1[5]=' ';

   }
   else	if(Freq>=1000)
   {

	BUF1[0]=Freq/100000+0x30;
   	BUF1[1]=Freq/10000%10+0x30;
	BUF1[2]=Freq/1000%10+0x30;
	BUF1[3]='.';
	BUF1[4]=Freq/100%10+0x30;
	BUF1[5]=Freq/10%10+0x30;
	BUF1[6]=Freq%10+0x30;
	BUF1[7]='K';

	if(BUF1[0]==0x30 && BUF1[1]==0x30)
	BUF1[0]=BUF1[1]=' ';
	else if	(BUF1[0]==0x30)
		BUF1[0]=' ';
   }

   	LCD_ShowString(1,1,BUF1);

}
