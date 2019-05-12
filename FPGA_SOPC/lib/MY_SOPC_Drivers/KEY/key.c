/*
 * key.c
 *  ������̶�ȡ����
 *  Created on: 2013-4-17
 *      Author: Qin Hai Cheng
 */
#include "key.h"
#include "unistd.h"//��ʱ����usleep
#include "io.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

alt_u8 Key_XY(void)
{
	alt_u8 temp=0;
	IOWR_ALTERA_AVALON_PIO_DIRECTION(KEY_BASE,0x0f);   //�趨PIO���� ,��4λΪ�������4λΪ����
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
	if(Key_XY())
	{
		usleep(5000); //��ʱ5ms
		if(Key_XY() != 0xff) //������ɶ�������������ж������
		{
			switch(Key_XY())
			{
				case 0xee://S11
				{

					//while(Key_XY() == 0xee);//�ȴ������ͷ�

				}break;
				case 0xde://S12
				{
					//while(Key_XY() == 0xde);//�ȴ������ͷ�

				}break;
				case 0xbe://S13
				{
					//while(Key_XY() == 0xbe);//�ȴ������ͷ�


				}break;
				case 0x7e://S14
				{
					//while(Key_XY() == 0x7e);//�ȴ������ͷ�


				}break;
////////////////////////////////////////////////////////////////
				case 0xed://S21
				{

					//while(Key_XY() == 0xed);//�ȴ������ͷ�

				}break;
				case 0xdd://S22
				{
					//while(Key_XY() == 0xdd);//�ȴ������ͷ�


				}break;
				case 0xbd://S23
				{
					//while(Key_XY() == 0xbd);//�ȴ������ͷ�



				}break;
				case 0x7d://S24
				{
					//while(Key_XY() == 0x7d);//�ȴ������ͷ�



				}break;
/////////////////////////////////////////////////////////////////
				case 0xeb://S31
				{

					//while(Key_XY() == 0xeb);//�ȴ������ͷ�



				}break;
				case 0xdb://S32
				{
					//while(Key_XY() == 0xdb);//�ȴ������ͷ�


				}break;
				case 0xbb://S33
				{
					//while(Key_XY() == 0xbb);//�ȴ������ͷ�



				}break;
				case 0x7b://S34
				{
					//while(Key_XY() == 0x7b);//�ȴ������ͷ�



				}break;
/////////////////////////////////////////////////////////////////////////
				case 0xe7://S41
				{

					//while(Key_XY() == 0xe7);//�ȴ������ͷ�


				}break;
				case 0xd7://S42
				{
					//while(Key_XY() == 0xd7);//�ȴ������ͷ�



				}break;
				case 0xb7://S43
				{
					//while(Key_XY() == 0xb7);//�ȴ������ͷ�



				}break;
				case 0x77://S44
				{
				//while(Key_XY() == 0x77);//�ȴ������ͷ�



				}break;
			}

		}
	}
}



