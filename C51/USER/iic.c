//#include "iic.h"
#include"delay.h"
//#include<intrins.h>//	_nop_(); 

sbit SDA=P1^3;
sbit SCL=P1^4;
 
//产生IIC起始信号
void IIC_Start(void)
{

	SDA=1;	  	  
	SCL=1;
	delay_us(4);
 	SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	SCL=0;//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC_Stop(void)
{

	SCL=0;
	SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	SCL=1; 
	SDA=1;//发送I2C总线结束信号
	delay_us(4);							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0; 
	SDA=1;delay_us(1);	   
	SCL=1;delay_us(1);	 
	while(SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	SCL=0;//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	SCL=0;
	SDA=0;
	delay_us(2);
	SCL=1;
	delay_us(2);
	SCL=0;
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	SCL=0;
	SDA=1;
	delay_us(2);
	SCL=1;
	delay_us(2);
	SCL=0;
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;       
    SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        //SDA=(txd&0x80)>>7;
		if((txd&0x80)>>7)
			SDA=1;
		else
			SDA=0;
		txd<<=1; 	  
		delay_us(2);   //对TEA5767这三个延时都是必须的
		SCL=1;
		delay_us(2); 
		SCL=0;	
		delay_us(2);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;

    for(i=0;i<8;i++ )
	{
        SCL=0; 
        delay_us(2);
		SCL=1;
        receive<<=1;
        if(SDA)receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK   
    return receive;
}



























