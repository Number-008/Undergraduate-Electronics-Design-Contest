/*
 * iic.c
 *
 *  Created on: 2013-8-1
 *      Author: ������
 */

#include "iic.h"

//��ʼ��IIC
void IIC_Init(void)
{

}
//����IIC��ʼ�ź�
void IIC_Start(void)
{

}
//����IICֹͣ�ź�
void IIC_Stop(void)
{

}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;//ʱ�����0
	return 0;
}
//1--����ACKӦ��
//0--������ACKӦ��
void IIC_Ack(u8 m)
{

}

//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void IIC_Send_Byte(u8 txd)
{

}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char receive=0;
    IIC_Ack(ack);//����ACK?
    return receive;
}
