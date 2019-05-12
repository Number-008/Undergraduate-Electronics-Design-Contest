#include "key.h"
#include "unistd.h"//延时函数usleep
#include "io.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "div.h"
#include "ili9320.h"
#include "app.h"
#include "djd.h"
#include "dds.h"
alt_u8 TRIG_DATA=127;
alt_u8 Key_XY(void)
{
	alt_u8 temp=0;
	IOWR_ALTERA_AVALON_PIO_DIRECTION(KEY_BASE,0x0f);   //设定PIO方向 ,低4位为输出，高4位为输入
	IOWR_ALTERA_AVALON_PIO_DATA(KEY_BASE, 0xf0);
	usleep(5);
	temp=IORD_ALTERA_AVALON_PIO_DATA(KEY_BASE) & 0xf0;
	IOWR_ALTERA_AVALON_PIO_DIRECTION(KEY_BASE,0xf0);
	IOWR_ALTERA_AVALON_PIO_DATA(KEY_BASE, 0x0f);
	usleep(5);
	temp=temp | (IORD_ALTERA_AVALON_PIO_DATA(KEY_BASE) & 0x0f);
	return temp;
}

void KeyScan(void)
{
	if(Key_XY() != 0xff)
	{
		usleep(5000); //延时5ms
		if(Key_XY() == 0xff) return;//如果是由短暂脉冲引起的中断则忽略

		if((save_control & 0x20)==0x20)
		{
			switch(Key_XY())
			{
				case 0xee://S11
				{
					//while(Key_XY() == 0xee);//等待按键释放
					Freq+=0.000001;
					if(Freq>=Fmax)Freq=Fmax;
					DDS_OUT(Freq);

				}break;
				case 0xde://S12
				{
					//while(Key_XY() == 0xde);//等待按键释放
					Freq+=0.001;
					if(Freq>=Fmax)Freq=Fmax;
					DDS_OUT(Freq);
				}break;
				case 0xbe://S13
				{
					//while(Key_XY() == 0xbe);//等待按键释放
					Freq+=1;
					if(Freq>=Fmax)Freq=Fmax;
					DDS_OUT(Freq);

				}break;
				case 0x7e://S14
				{
					//while(Key_XY() == 0x7e);//等待按键释放
					Freq+=1000;
					if(Freq>=Fmax)Freq=Fmax;
					DDS_OUT(Freq);
				}break;
		////////////////////////////////////////////////////////////////
				case 0xed://S21
				{

					//while(Key_XY() == 0xed);//等待按键释放
					if(Freq>=0.000001)
					Freq-=0.000001;
					DDS_OUT(Freq);

				}break;
				case 0xdd://S22
				{
					//while(Key_XY() == 0xdd);//等待按键释放
					if(Freq>=0.001)
					Freq-=0.001;
					DDS_OUT(Freq);

				}break;
				case 0xbd://S23
				{
					//while(Key_XY() == 0xbd);//等待按键释放
					if(Freq>=1)
					Freq-=1;
					DDS_OUT(Freq);
				}break;
				case 0x7d://S24
				{
					//while(Key_XY() == 0x7d);//等待按键释放
					if(Freq>=1000)
					Freq-=1000;
					DDS_OUT(Freq);

				}break;
		/////////////////////////////////////////////////////////////////
				case 0xeb://S31
				{

					//while(Key_XY() == 0xeb);//等待按键释放
					Freq+=1000000;
					if(Freq>=Fmax)Freq=Fmax;
					DDS_OUT(Freq);

				}break;
				case 0xdb://S32
				{
					//while(Key_XY() == 0xdb);//等待按键释放


				}break;
				case 0xbb://S33
				{
					while(Key_XY() == 0xbb);//等待按键释放
					save_control^=0x80;

				}break;
				case 0x7b://S34
				{
					while(Key_XY() == 0x7b);//等待按键释放
					if(DDSn<=3)
					{
						DDS_RAM_WR(DDSn);
						DDSn++;
						if(DDSn>3) DDSn = 0;
					}


				}break;
		/////////////////////////////////////////////////////////////////////////
				case 0xe7://S41
				{

					//while(Key_XY() == 0xe7);//等待按键释放
					if(Freq>=1000000)
					Freq-=1000000;
					DDS_OUT(Freq);
				}break;
				case 0xd7://S42
				{
					//while(Key_XY() == 0xd7);//等待按键释放

				}break;
				case 0xb7://S43
				{
					ili9320_ShowString(313,115,48,12,12,"T",WHITE,RED);
					while(Key_XY() == 0xb7);//等待按键释放
					save_control^=0x40;
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
				}break;
				case 0x77://S44
				{
					ili9320_ShowString(313,205,48,12,12,"D",WHITE,RED);
					while(Key_XY() == 0x77);//等待按键释放
					save_control^=0x20;
					if((save_control & 0x20)==0x20)
					{
						ili9320_ShowString(313,205,48,12,12,"D",WHITE,RED);
					}
					else
					{
						ili9320_ShowString(313,205,48,12,12,"D",WHITE,BLACK);
					}

				}break;
				default:
					break;
			}

		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else
		{
			switch(Key_XY())
			{
				case 0xee://S11
				{

					while(Key_XY() == 0xee);//等待按键释放
					//delay_ms(20);

					if(VDIV>0) VDIV--;
					WrVDiv(VDIV);

				}break;
				case 0xde://S12
				{
					//while(Key_XY() == 0xde);//等待按键释放
					delay_ms(5);
					LCKDIV++;
					if(LCKDIV>=14) LCKDIV=14;
					WrClkDiv(LCKDIV);



				}break;
				case 0xbe://S13
				{
					//while(Key_XY() == 0xbe);//等待按键释放
					delay_ms(10);
					ili9320_ShowString(2,Y0-5,12,12,12," ",GRAY-20,BLUE);
					Y0-=5;
					if(Y0<=20) Y0=20;
					ili9320_ShowString(2,Y0-5,12,12,12,">",BLACK,YELLOW);

				}break;
				case 0x7e://S14
				{
					//while(Key_XY() == 0x7e);//等待按键释放
					//delay_ms(1);
					X0+=1;
					if(X0>=200) X0=200;
					ili9320_ShowNum(300,225,X0,3,12,WHITE,BLACK);


				}break;
////////////////////////////////////////////////////////////////
				case 0xed://S21
				{

					while(Key_XY() == 0xed);//等待按键释放
					//delay_ms(20);
					VDIV++;
					if(VDIV>=9) VDIV=9;
					WrVDiv(VDIV);

				}break;
				case 0xdd://S22
				{
					//while(Key_XY() == 0xdd);//等待按键释放
					delay_ms(5);
					if(LCKDIV!=0) LCKDIV--;
					WrClkDiv(LCKDIV);

				}break;
				case 0xbd://S23
				{
					//while(Key_XY() == 0xbd);//等待按键释放
					delay_ms(10);
					ili9320_ShowString(2,Y0-5,12,12,12," ",GRAY-20,BLUE);
					Y0+=5;
					if(Y0>=220) Y0=220;
					ili9320_ShowString(2,Y0-5,12,12,12,">",BLACK,YELLOW);



				}break;
				case 0x7d://S24
				{
					//while(Key_XY() == 0x7d);//等待按键释放
					//delay_ms(1);
					if(X0>=1)
					X0-=1;
					ili9320_ShowNum(300,225,X0,3,12,WHITE,BLACK);

				}break;
/////////////////////////////////////////////////////////////////
				case 0xeb://S31
				{

					//while(Key_XY() == 0xeb);//等待按键释放
					if(TRIG_DATA<=254)
					TRIG_DATA+=1;
					//if(TRIG_DATA>=255) TRIG_DATA=255;
					IOWR_ALTERA_AVALON_PIO_DATA(TRIG_D_BASE,TRIG_DATA);
					ili9320_ShowNum(300,5,TRIG_DATA,3,12,WHITE,BLACK);
				}break;
				case 0xdb://S32
				{
					//ili9320_ShowString(250,225,110,12,12,"P",WHITE,RED);
					ili9320_ShowString(135,50,110,16,16," Play ",RED,WHITE);
					while(Key_XY() == 0xdb);//等待按键释放
					save_control^=0x01;
					if(save_control & 0x01)
					{

						ili9320_ShowString(313,25,48,12,12,"P",WHITE,RED);
					}
					else
					{

						ili9320_ShowString(313,25,48,12,12,"P",WHITE,BLACK);
					}

				}break;
				case 0xbb://S33
				{
					//ili9320_ShowString(265,225,110,12,12,"S",WHITE,RED);
					ili9320_ShowString(135,50,110,16,16," Save ",RED,WHITE);
					while(Key_XY() == 0xbb);//等待按键释放
					save_control^=0x02;
				}break;
				case 0x7b://S34
				{
					//ili9320_ShowString(280,225,110,12,12,"T",WHITE,RED);
					ili9320_ShowString(135,50,110,16,16," Ready ",RED,WHITE);
					while(Key_XY() == 0x7b);//等待按键释放
					save_control^=0x04;
				}break;
/////////////////////////////////////////////////////////////////////////
				case 0xe7://S41
				{

					//while(Key_XY() == 0xe7);//等待按键释放
					if(TRIG_DATA>=1) TRIG_DATA-=1;
					IOWR_ALTERA_AVALON_PIO_DATA(TRIG_D_BASE,TRIG_DATA);
					ili9320_ShowNum(300,5,TRIG_DATA,3,12,WHITE,BLACK);

				}break;
				case 0xd7://S42
				{
					ili9320_ShowString(210,5,48,12,12,"FFT",WHITE,RED);
					while(Key_XY() == 0xd7);//等待按键释放
					save_control^=0x10;
					if(save_control & 0x10)
					{

						ili9320_ShowString(210,5,48,12,12,"FFT",WHITE,GREEN);
					}
					else
					{

						ili9320_ShowString(210,5,48,12,12,"FFT",WHITE,BLACK);
					}

				}break;
				case 0xb7://S43
				{

					ili9320_ShowString(247,5,48,12,12,"Stop",WHITE,RED);
					while(Key_XY() == 0xb7);//等待按键释放
					save_control^=0x08;
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

				}break;
				case 0x77://S44
				{

					ili9320_ShowString(313,205,48,12,12,"D",WHITE,RED);
					while(Key_XY() == 0x77);//等待按键释放
					save_control^=0x20;
					if((save_control & 0x20)==0x20)
					{
						ili9320_ShowString(313,205,48,12,12,"D",WHITE,RED);
					}
					else
					{
						ili9320_ShowString(313,205,48,12,12,"D",WHITE,BLACK);
					}
				}break;
				default:
					break;
			}
		}

	}
}



