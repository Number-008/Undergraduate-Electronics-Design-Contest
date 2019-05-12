#include "key.h"
#include "dds.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
/********************************************************************
* �� �ƣ�key(void)
* �� �ܣ���������
* ��ڲ�����KEY_INPUT
* ���ڲ�����
********************************************************************/

void key(void)
{
	if(KEY_INPUT != 0x0f)
		{
			usleep(10000);                      //��ʱ20ms
			if(KEY_INPUT != 0x0f)               //������ɶ�������������ж������
			{
				switch(KEY_INPUT)
					{
						case 0x0e:
							{
								
								//while(KEY_INPUT==0x0e);//�ȴ������ͷ�
								if(IORD_ALTERA_AVALON_PIO_DATA(SW2_BASE))
								{
									if(freq<=10000000)freq+=1000;

								}
								else
								{
									if(freq<=10000000)freq+=1;
								}

								DDS_OUT(freq);
								usleep(50);

							}break;
						case 0x0d:
							{
								
								//while(KEY_INPUT==0x0d);//�ȴ������ͷ�

								if(IORD_ALTERA_AVALON_PIO_DATA(SW2_BASE))
								{
									if(freq>1000)freq-=1000;

								}
								else
								{
									if(freq>0)freq--;
								}
								DDS_OUT(freq);
								usleep(50);
							}break;
						case 0x0b:
							{
								
								//while(KEY_INPUT==0x0b);//�ȴ������ͷ�
								if(pha<360)pha++;
								DDS_Phasew(pha);
								usleep(8);
							}break;
						case 0x07:
							{
								
								//while(KEY_INPUT==0x07);//�ȴ������ͷ�
								if(pha>0)pha--;
								DDS_Phasew(pha);
								usleep(8);
							}break;
					}
			}
			
		}

}