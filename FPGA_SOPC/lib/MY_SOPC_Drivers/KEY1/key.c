/*
 * key.c
 *
 *  Created on: 2013-1-24
 *      Author: qin
 */
#include "key.h"
#include "led.h"
#include "sys/alt_irq.h"
#include "unistd.h"//��ʱ����usleep

/********************************************************************
* �� �ƣ�KeyDown_interrupts()
* �� �ܣ��������¼��жϷ����ӳ���
* ��֪���
* ��ڲ�����context��һ�����ڴ����ж�״̬�Ĵ�����ֵ������δʹ��
* id���жϺţ�����δʹ��
* ���ڲ�������
********************************************************************/
static void KeyDown_interrupts(void* context, alt_u32 id)
{
	//WR_KEY_IRQ_MASK(0x00);
	usleep(5000); //��ʱ5ms
	/* ���жϲ���Ĵ��� */
	WR_KEY_EDGE_CAP(0x00);
	if(RD_KEY != 0x0f) //������ɶ�������������ж������
	{
		switch(RD_KEY)
		{
			case 0x0e:
			{
				//while(RD_KEY == 0x0e);//�ȴ������ͷ�
				NOT_LEDn(0);
			}break;
			case 0x0d:
			{

				NOT_LEDn(1);

			}break;
			case 0x0b:
			{
				NOT_LEDn(2);
			}break;
			case 0x07:
			{
				while(RD_KEY == 0x07);//�ȴ������ͷ�
				NOT_LEDn(3);
			}break;
		}

	}
	//WR_KEY_IRQ_MASK(0x0f);

}
/********************************************************************
* �� �ƣ�Init_Key()
* �� �ܣ���ʼ��LED_PIOΪ�����KEYΪ���룬���жϣ�����ز���Ĵ���
* ��ڲ�������
* ���ڲ�������
********************************************************************/
void Init_Key(void)
{


	/* ����KEY���ж� ��1--����0--����*/
	WR_KEY_IRQ_MASK(0x0f);
	/* ����ز���Ĵ��� */
	WR_KEY_EDGE_CAP(0x00);

	/* ע���жϷ����ӳ��� */
	alt_irq_register(KEY_IRQ,0, KeyDown_interrupts);
}



