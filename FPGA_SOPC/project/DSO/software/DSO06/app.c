#include "ili9320.h"
#include "app.h"
#include "altera_avalon_pio_regs.h"
#include "includes.h"
#include "system.h"
#include "unistd.h"
#include "flash.h"
#include "div.h"
#include "FFT.h"
#include "key.h"

alt_u8 data_in[1024];
alt_u16 Vpp;
alt_u8 Y0=120;
alt_u8 X0=0;
alt_u8 save_flag=0;
alt_u8 save_control=0;

__inline void sx(alt_u16 x)
{
	alt_u8 i,temp;
	if(x>100) temp=x%100;
	else temp=x;
	if(x==159 || x==161 || temp==10  || temp==35  || temp==60  || temp==85 )
	{
		for (i=20; i <=220; i++)
		{
			if(i%5==0) 	ili9320_SetPoint(x ,i, WHITE);
				else 	ili9320_SetPoint(x ,i, BLACK);
		}
		ili9320_SetPoint(x ,119, WHITE);
		ili9320_SetPoint(x ,121, WHITE);
		//break;
	}
	else
	{
		if(x%5==0)
		{
			for (i = 20; i <=220; i++)
			{
				if(i>100) temp=i%100;
				else temp=i;
				if(temp==20  || temp==45  || temp==70  || temp==95)
					ili9320_SetPoint(x ,i, WHITE);
				else 	ili9320_SetPoint(x ,i, BLACK);
			}

			ili9320_SetPoint(x ,119, WHITE);
			ili9320_SetPoint(x ,121, WHITE);
		}
		else
		{
			for (i=20; i <= 220; i++)
			{
				ili9320_SetPoint(x ,i, BLACK);
			}
		}

	}
}
void Save_data(void)
{
	alt_u16 x;
	for(x=0;x<=511;x++)
	{
		data_in[x]=Read_RAM(x);
	}
	data_in[513]=TRIG_DATA;
	data_in[514]=LCKDIV;
	data_in[515]=VDIV;
	data_in[516]=Y0;
	data_in[517]=X0;
	data_in[518]=0;
	Flash_WriteData();

}
void Play_data(void)
{
	ili9320_ShowString(2,Y0-5,12,12,12," ",GRAY-20,BLUE);
	Flash_ReadData();
	TRIG_DATA=data_in[513];
	LCKDIV=data_in[514];
	VDIV=data_in[515];
	Y0=data_in[516];
	X0=data_in[517];
	save_flag=data_in[518];
	if(save_flag==0xff)
	{
		TRIG_DATA=127;
		LCKDIV=0;
		VDIV=8;
		Y0=120;
		X0=0;
	}
	WrVDiv(VDIV);
	WrClkDiv(LCKDIV);
	ili9320_ShowNum(300,225,X0,3,12,WHITE,BLACK);
	IOWR_ALTERA_AVALON_PIO_DATA(TRIG_D_BASE,TRIG_DATA);
	ili9320_ShowNum(300,5,TRIG_DATA,3,12,WHITE,BLACK);
	ili9320_ShowString(2,Y0-5,12,12,12,">",BLACK,YELLOW);
}

void Vpp_printf(void)
{
	double x;
	char BUF2[7];
	x=5000*Vpp;//y=(2/255)*n+1.5;
	switch(VDIV)
		{
			case 0:{
				//125  2.00mV/div  FF--16mV
				x=(x*0.016)/255.0f;
			}break;
			case 1:{
				//50  5mV/div   FF--40mV
				x=(x*0.04)/255.0f;
			}break;
			case 2:{
				//25 10mV/div   FF--80mV
				x=(x*0.08)/255.0f;
			}break;
			case 3:{
				//12.5  20mV/div   FF--160mV
				x=(x*0.16)/255.0f;
			}break;
			case 4:{
				//5  50mV/div  FF--400mV
				x=(x*0.4)/255.0f;
			}break;
			case 5:{
				//2.5  100mV/div   FF--800mV
				x=(x*0.8)/255.0f;
			}break;
			case 6:{
				//1.25 200mV/div   FF--1.6V
				x=(x*1.6)/255.0f;
			}break;
			case 7:{
				//1/2  500mV/div   FF--4V
				x=(x*4)/255.0f;
			}break;
			case 8:{
				//1/4 1V/div   FF--8V
				//4*2/255
				x=(x*8)/255.0f;
			}break;
			case 9:{
				//1/8  2.00V/div   FF--16V
				x=(x*16)/255.0f;
			}break;
			default:
				break;
		}
	if(x>=0 && x<1000)
   	{
		BUF2[0]=(alt_u32)x/100%10+0x30;
		BUF2[1]=(alt_u32)x/10%10+0x30;
		BUF2[2]='.';
		BUF2[3]=(alt_u32)x%10+0x30;
		BUF2[4]='m';
		if(BUF2[0]==0x30) 	BUF2[0]=' ';
	}
	else if(x>=1000 && x<10000)
   	{
		BUF2[0]=' ';
		BUF2[1]=(alt_u32)x/1000%10+0x30;
		BUF2[2]=(alt_u32)x/100%10+0x30;
		BUF2[3]=(alt_u32)x/10%10+0x30;
		BUF2[4]='m';
	}
	else if(x>=10000 && x<100000)
	{
		BUF2[0]=' ';
		BUF2[1]=x/10000+0x30;
		BUF2[2]='.';
		BUF2[3]=(alt_u32)x/1000%10+0x30;
		BUF2[4]=(alt_u32)x/100%10+0x30;

	}
	else if(x>=100000 && x<1000000)
	{
		BUF2[0]=x/100000+0x30;;
		BUF2[1]=(alt_u32)x/10000%10+0x30;
		BUF2[2]='.';
		BUF2[3]=(alt_u32)x/1000%10+0x30;
		BUF2[4]=(alt_u32)x/100%10+0x30;

	}
	else
		BUF2[0]=BUF2[1]=BUF2[2]=BUF2[3]=BUF2[4]='*';
	BUF2[5]='V';
	BUF2[6]='\0';
	ili9320_ShowString(34,225,110,12,12,BUF2,YELLOW,BLACK);
}
/*******************************************************************************
*	函数名: DispFrame
*	输  入:	无
*	输  出:	无
*	功  能：显示波形窗口的边框和刻度线
*/
void DispFrame(void)
{
	alt_u16 x, y;
	ili9320_ShowString(2,Y0-5,12,12,12,">",BLACK,YELLOW);
	ili9320_ShowString(10,225,110,12,12,"Vpp=******",YELLOW,BLACK);
	ili9320_ShowString(77,225,120,12,12,"Freq=",YELLOW,BLACK);
	//ili9320_ShowNum(300,5,TRIG_DATA,3,12,WHITE,BLACK);
	//ili9320_ShowNum(300,225,X0,3,12,WHITE,BLACK);
	if(save_control & 0x01)
	{

		ili9320_ShowString(313,25,48,12,12,"P",WHITE,RED);
	}
	else
	{

		ili9320_ShowString(313,25,48,12,12,"P",WHITE,BLACK);
	}
	if(save_control & 0x10)
	{

		ili9320_ShowString(210,5,48,12,12,"FFT",WHITE,GREEN);
	}
	else
	{

		ili9320_ShowString(210,5,48,12,12,"FFT",WHITE,BLACK);
	}
	if(save_control & 0x08)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(RAM_WREN_BASE, 0x00);
		ili9320_ShowString(247,5,48,12,12,"Stop",WHITE,RED);
	}
	else
	{
		IOWR_ALTERA_AVALON_PIO_DATA(RAM_WREN_BASE, 0x01);
		ili9320_ShowString(247,5,48,12,12,"Stop",WHITE,BLACK);
	}
	if(save_control & 0x20)
	{
		ili9320_ShowString(313,205,48,12,12,"D",WHITE,RED);
	}
	else
	{
		ili9320_ShowString(313,205,48,12,12,"D",WHITE,BLACK);
	}
	if(save_control & 0x40)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(TRIG_S_BASE, 0x00);
		ili9320_ShowString(313,115,48,12,12,"T",WHITE,RED);
	}
	else
	{
		IOWR_ALTERA_AVALON_PIO_DATA(TRIG_S_BASE, 0x01);
		ili9320_ShowString(313,115,48,12,12,"T",WHITE,BLACK);
	}
	ili9320_Fill(9, 19, 311, 221,BLACK);
	/* 绘制一个实线矩形框 x, y, h, w */
	ili9320_DrawRectangle(9, 19, 311, 221,LGRAY);
	/* 绘制垂直刻度点 */
	for (x = 0; x < 13; x++)
	{
		for (y = 0; y < 41; y++)
		{
			ili9320_SetPoint(10 + (x * 25), 20 + (y * 5), WHITE);
		}
	}

	/* 绘制水平刻度点 */
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 61; x++)
		{
			ili9320_SetPoint(10 + (x * 5), 20 + (y * 25), WHITE);
		}
	}

	/* 绘制垂直中心刻度点 */
	for (y = 0; y < 41; y++)
	{
		ili9320_SetPoint(9 + (6 * 25), 20 + (y * 5), WHITE);//159
		ili9320_SetPoint(11 + (6 * 25), 20 + (y * 5), WHITE);//161
	}

	/* 绘制水平中心刻度点 */
	for (x = 0; x < 61; x++)
	{
		ili9320_SetPoint(10 + (x * 5), 19 + (4 * 25), WHITE);
		ili9320_SetPoint(10 + (x * 5), 21 + (4 * 25), WHITE);
	}

}

__inline void DispWave(void)
{
	alt_u16 x;
	alt_u8 v1,v2;
	alt_u8 max=0;
	alt_u8 min=0xff;
	alt_u16 timer_cnt=0;
	v1=v2=0;

	if(save_control & 0x04)
	{
		//ili9320_ShowString(100,50,110,12,12,"Ready",RED,WHITE);
		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);
		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x00);
		//usleep(1);
		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);
		//while(!IORD_ALTERA_AVALON_PIO_DATA(CNT_IRQ_BASE));
		for(timer_cnt=0;timer_cnt<=65535;timer_cnt++)
		if(IORD_ALTERA_AVALON_PIO_DATA(CNT_IRQ_BASE)==1) break;
		Save_data();
		save_control^=0x04;
		//ili9320_ShowString(280,225,110,12,12,"T",WHITE,BLACK);
	}
	else
	if(save_control & 0x01)
	{
		//ili9320_ShowString(10,20,110,12,12,"Play",BLACK,WHITE);
		//usleep(5000);
		Play_data();
		for(x=0;x<=511;x++)
		{
			if(data_in[x]>max) max=data_in[x];
			if(data_in[x]<min) min=data_in[x];
			switch(x)
			{
				case 255:{v1=max-min;min=0xff;max=0;}break;
				case 510:{v2=max-min;min=0xff;max=0;}break;
				default:break;
			}
		}
	}
	else
	{
		for(timer_cnt=0;timer_cnt<=65535;timer_cnt++)
		if(IORD_ALTERA_AVALON_PIO_DATA(CNT_IRQ_BASE)==1) break;
		for(x=0;x<=511;x++)
		{
			data_in[x]=Read_RAM(x);
			if(data_in[x]>max) max=data_in[x];
			if(data_in[x]<min) min=data_in[x];
			switch(x)
			{
				case 255:{v1=max-min;min=0xff;max=0;}break;
				case 510:{v2=max-min;min=0xff;max=0;}break;
				default:break;
			}
		}


		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);
		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x00);
		//usleep(100);
		IOWR_ALTERA_AVALON_PIO_DATA(CNT_EN_BASE, 0x01);
		if(save_control & 0x02)
		{
			//ili9320_ShowString(100,50,110,12,12,"Save ",RED,WHITE);
			//usleep(5000);
			//Flash_WriteData();
			Save_data();
			//ili9320_ShowString(265,225,110,12,12,"S",WHITE,BLACK);
			save_control^=0x02;
		}
	}
	if(save_control & 0x10)
	{
		for(x=0; x<512; x++)
		{
			fft[x].imag=0;
			fft[x].real=data_in[x];
		}
		FFT(fft,512);
		FFTpowerMag(fft,lBUFMAG,256);
	}
	for(x=10;x<309;x++)
	{
		sx(x);
		if(x==308)sx(309);
		ili9320_DrawLine2(x,239-0.78125*data_in[x-8+X0]-(0.78125*127-Y0+40),x+1,239-0.78125*data_in[x-7+X0]-(0.78125*127-Y0+40),YELLOW);
		if(save_control & 0x10)
		{
			if(x>=35&&x<290)
			ili9320_DrawLine2(x,239-0.78125*lBUFMAG[x-35]-(0.78125*127-Y0+40),x+1,239-0.78125*lBUFMAG[x-34]-(0.78125*127-Y0+40),RED);
		}
	}
/*	for(x=310;x>10;x--)
	{
		sx(x);
		ili9320_DrawLine2(x,239-0.78125*data_in[311-x+X0]-(0.78125*127-Y0+40),x+1,239-0.78125*data_in[312-x+X0]-(0.78125*127-Y0+40),YELLOW);
	}*/
	Vpp=v1+v2;
	Vpp_printf();
}


