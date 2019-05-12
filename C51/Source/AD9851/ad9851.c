#include"ad9851.h"
#include"lcd.h"
#include"key.h"	
#include"delay.h"
u16 Fraq=0x03e8;
u8 Phase=0x00;




//往AD9851寄存器写入数据
void AD9851WriteData(void)
{
	u8 i,p;
	u32 temp;
	if(Fraq<10000)
	{
		p=Phase<<3 | 0x00;
		temp=(u32)(Fraq*715.824910);//6000024.9135089401152558331647251	//715.825235
	}
	else
	{
		p=Phase<<3 | 0x01;
		temp=(u32)(Fraq*119.3041516);//36000152.97527755155486568393992
	}
   	FQUD=0;
	WCLK=0;
	for(i=0;i<32;i++)
	{
		WCLK=0;
		if(temp&0x00000001)DDS=1;
		else DDS=0; 
		temp>>=1;
		WCLK=1;
	}
	for(i=0;i<8;i++)
	{
		WCLK=0;
		if(p&0x01)DDS=1;
		else DDS=0; 
		p>>=1;
		WCLK=1;
	}
	FQUD=1;
}

//显示相位值
void printf_Phase(void)
{
	char BUF2[7];
	u16 temp;
	temp=36000*(Phase & 0x1f)/32;
	BUF2[0]=temp/10000+0x30;
	BUF2[1]=temp/1000%10+0x30;
	BUF2[2]=temp/100%10+0x30;
	BUF2[3]='.';
	BUF2[4]=temp/10%10+0x30;
	BUF2[5]=temp%10+0x30;
	BUF2[6]='\0';
	if(BUF2[0]==0x30 && BUF2[1]==0x30)
		BUF2[0]=BUF2[1]=' ';
	else if(BUF2[0]==0x30) 	BUF2[0]=' ';
	LCD_ShowString(9,2,BUF2);

}
//显示频率值
void printf_Fraq(void)
{
   char BUF1[9];
   BUF1[8]='\0';
   if(Fraq<1000)
   {
   	BUF1[0]=BUF1[1]=BUF1[2]=BUF1[3]=BUF1[4]=' ';
   	BUF1[5]=Fraq/100+0x30;
	BUF1[6]=Fraq/10%10+0x30;
	BUF1[7]=Fraq%10+0x30;

	if(BUF1[5]==0x30 && BUF1[6]==0x30)
		BUF1[5]=BUF1[6]=' ';
		else if	(BUF1[5]==0x30)
			BUF1[5]=' ';

   }
   else	if(Fraq>=1000)
   {

	BUF1[0]=Fraq/100000+0x30;
   	BUF1[1]=Fraq/10000%10+0x30;
	BUF1[2]=Fraq/1000%10+0x30;
	BUF1[3]='.';
	BUF1[4]=Fraq/100%10+0x30;
	BUF1[5]=Fraq/10%10+0x30;
	BUF1[6]=Fraq%10+0x30;
	BUF1[7]='k';

	if(BUF1[0]==0x30 && BUF1[1]==0x30)
	BUF1[0]=BUF1[1]=' ';
	else if	(BUF1[0]==0x30)
		BUF1[0]=' ';
   }

   	LCD_ShowString(6,1,BUF1);

}
