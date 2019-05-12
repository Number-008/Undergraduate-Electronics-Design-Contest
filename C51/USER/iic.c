//#include "iic.h"
#include"delay.h"
//#include<intrins.h>//	_nop_(); 

sbit SDA=P1^3;
sbit SCL=P1^4;
 
//����IIC��ʼ�ź�
void IIC_Start(void)
{

	SDA=1;	  	  
	SCL=1;
	delay_us(4);
 	SDA=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	SCL=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
//����IICֹͣ�ź�
void IIC_Stop(void)
{

	SCL=0;
	SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	SCL=1; 
	SDA=1;//����I2C���߽����ź�
	delay_us(4);							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
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
	SCL=0;//ʱ�����0 	   
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(void)
{
	SCL=0;
	SDA=0;
	delay_us(2);
	SCL=1;
	delay_us(2);
	SCL=0;
}
//������ACKӦ��		    
void IIC_NAck(void)
{
	SCL=0;
	SDA=1;
	delay_us(2);
	SCL=1;
	delay_us(2);
	SCL=0;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;       
    SCL=0;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        //SDA=(txd&0x80)>>7;
		if((txd&0x80)>>7)
			SDA=1;
		else
			SDA=0;
		txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		SCL=1;
		delay_us(2); 
		SCL=0;	
		delay_us(2);
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
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
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK   
    return receive;
}



























