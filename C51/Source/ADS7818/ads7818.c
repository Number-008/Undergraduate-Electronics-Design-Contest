#include"ads7818.h"
#include"lcd.h"	
#include<intrins.h>//	_nop_(); 
#include"ad9851.h"
#include"math.h"
#include"key.h"
#include"delay.h"
//ADS7818 SPI驱动程序
u16 Read_ADS7818(void)
{
	u8 i;
	u16 ADS7818=0;
	CONV=0;
	_nop_();
	_nop_();
	CLK=0;
	CLK=1;
	CLK=0;
	CLK=1;
	for(i=0;i<12;i++)
	{	
		CLK=0;//上升沿有效  	   
		CLK=1; 
		ADS7818<<=1; 
		ADS7818|=DATA;	 
	}
	CLK=0;
	CLK=1;
	CLK=0;
	CLK=1;
	CLK=0;//不可少！
	_nop_();
	_nop_();
	CONV=1;
	ADS7818=ADS7818 & 0x0fff;
	return (ADS7818); 
}
////去掉最高位和最低位，然后取平均值,最后加权平均滤波
#define	READ_TIMES 25
#define	LOST_VAL 4
u16  buf[READ_TIMES];
double  AN0;
double  AN1;
u16 Filter(void)
{	
	u8 i, j;
	u16 temp;
	for(i=0;i<READ_TIMES;i++)
	{				 
		buf[i]=Read_ADS7818();
		delay(5);	    
	}				    
	for(i=0;i<READ_TIMES-1; i++)//排序
	{
		for(j=i+1;j<READ_TIMES;j++)
		{
			if(buf[i]>buf[j])//升序排列
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}	  
	AN0=0;
	for(i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++)AN0+=buf[i];
	AN0=AN0/(READ_TIMES-2*LOST_VAL);
	AN1=0.8*AN1+0.2*AN0;
	return ((u16)AN1);
	//return ((u16)AN0);
}


//显示AD数字

void printf_AD(void)
{
	u16 max;
	u8 pm;
	char BUF2[8];
	double temp;
	if(k)
	{
	  pm=max=0;
	  for(Phase=0;Phase<31;Phase++)
	  {
	  	AD9851WriteData();
		printf_Phase();
		temp=Read_ADS7818();
		if(max<temp)
			{
				max=temp;
				pm=Phase;
			}
			delay(450);
		}
		k=0;
		//Phase=pm-2;
		Phase=pm;
		AD9851WriteData();
		printf_Phase();
		printf_Fraq();
	
	}
	temp=Filter();
	//temp=Read_ADS7818();
	if(temp>=0x7f6) 
	{
		temp=temp-0x7f6;
		BUF2[0]=' ';
	}
	else   
	{
		temp=0x7f6-temp;
		BUF2[0]='-';
	}

	switch (PGA)
	{
		case 0:temp=981.8105399*temp;break;
		case 1:temp=95.037469*temp;break;
		case 2:temp=9.519789*temp;break;//9.5873799224853515625
		case 3:temp=1.488261*temp;break;
		default:break;
	}
	//temp=(78539.815*temp)/4096.0;	 // 39269.9081625
	//temp=(39269.9075*temp)/4096.0;
	//temp=(50000*temp)/4096.0;
	if(((u32)temp%10)>=5)temp+=10;//四舍五入
	//if(temp>25000)temp+=10;//
	if(temp>=0 && temp<10000)
   	{
		BUF2[1]=' ';
		BUF2[2]=(u32)temp/1000%10+0x30;
		BUF2[3]=(u32)temp/100%10+0x30;
		BUF2[4]=(u32)temp/10%10+0x30;
		BUF2[5]='m';
		if(BUF2[2]==0x30 && BUF2[3]==0x30)
			BUF2[2]=BUF2[3]=' ';
		else if	(BUF2[2]==0x30)
			BUF2[2]=' ';	
	}
	else if(temp>10000)
	{
		BUF2[1]=(u32)temp/10000+0x30;
		BUF2[2]='.';
		BUF2[3]=(u32)temp/1000%10+0x30;
		BUF2[4]=(u32)temp/100%10+0x30;
		BUF2[5]=(u32)temp/10%10+0x30;
	}
	BUF2[6]='V';
	BUF2[7]='\0';
	LCD_ShowString(0,2,BUF2);
}
