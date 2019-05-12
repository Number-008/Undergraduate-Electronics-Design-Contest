/*
 * iic.c
 *
 *  Created on: 2013-8-1
 *      Author: 覃海程
 */

#include "iic.h"

//初始化IIC
void IIC_Init(void)
{

}
//产生IIC起始信号
void IIC_Start(void)
{

}
//产生IIC停止信号
void IIC_Stop(void)
{

}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
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
	IIC_SCL=0;//时钟输出0
	return 0;
}
//1--产生ACK应答
//0--不产生ACK应答
void IIC_Ack(u8 m)
{

}

//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答
void IIC_Send_Byte(u8 txd)
{

}
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char receive=0;
    IIC_Ack(ack);//发送ACK?
    return receive;
}
