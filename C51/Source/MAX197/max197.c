#include "my_types.h"
#include "max197.h"
#include"delay.h"
#include"lcd.h"
#include<intrins.h>//	_nop_(); 
#include<absacc.h>
#include"ad9851.h"

#define max197 XBYTE[0x8000]	 //cs0
sbit HBEN=P1^4;
sbit INT=P1^5;

u16 ReadMax_197()//启动转换并读数据
{
	u16 data197=0;
	
	max197=0x48;//0~5 0x40

	_nop_(); 
	while(INT==1);
	HBEN=1;
	_nop_(); 
	data197=(max197 & 0x0f)<<8;
	HBEN=0;
	_nop_(); 
	data197+=max197;
	//delay(10);
	return data197; 

}

////去掉最高的LOST_VAL位和最低的LOST_VAL位，然后取平均值
//#define	READ_TIMES 20
//#define	LOST_VAL 2
//
//u16 AVG()
//{	
// 	u8 i, j;
//	u16 buf[READ_TIMES];
//	u32 sum=0;
//	u16 temp;
//	for(i=0;i<READ_TIMES;i++)
//	{				 
//		buf[i]=ReadMax_197()& 0x0fff;	    
//	}				    
//	for(i=0;i<READ_TIMES-1; i++)//排序
//	{
//		for(j=i+1;j<READ_TIMES;j++)
//		{
//			if(buf[i]>buf[j])//升序排列
//			{
//				temp=buf[i];
//				buf[i]=buf[j];
//				buf[j]=temp;
//			}
//		}
//	}	  
//	sum=0;
//	for(i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++)sum+=buf[i];
//	temp=sum/(READ_TIMES-2*LOST_VAL);
//	return temp; 
//
//
//}

void disp_MAX197()
{
	char d[6];
	u8 s=0;
	u16 x;
	float dy;
	x=ReadMax_197();
	if(x & 0x800) 
	{
		x=0xfff-x;
		d[0]='-';
		x-=4; //-0.010V补偿
	}
	else 
	{
		d[0]='+';
		x+=8; //+0.020V补偿

	}
	 
	dy=5000*((double)x)/2048;//0.0015 10000	
	dy=	1.5707963*dy;
	s=(u16)dy%10;
	if(s>4)dy+=10;//四舍五入,+0.01
	d[1]=(u8)((u16)dy/1000)+0x30;
	d[3]=(u8)((u16)dy/100%10)+0x30;
 	d[4]=(u8)((u16)dy/10%10)+0x30;


	d[2]='.';
	d[5]='V';
	d[6]='\0';
	LCD_ShowString(0,2,d);

}