#include"spi.h"
#include<absacc.h>
/*ע��SPI�ж��ֹ�����ʽ��Ӧ��ʱӦ���ݾ���������ʱ��ͼ��д��������ֻ�ܵ������˼��Ĳο���*/

sbit DIN 	= P1^0;
sbit SCLK 	= P1^1;
sbit CS = P1^2;

//sbit SPI_CS = P2^3;
//SPIд����  
void SPI_Write(u16 dat)    
{  
	u8 i=0;
	SCLK=0;
	CS=1;
	CS=0; 
	for(i=0;i<16;i++)  
	{ 	  
		if(dat&0x8000)DIN=1;
		else DIN=0; 
		dat<<=1;    
		SCLK=1;//��������Ч	   	 
		SCLK=0;      
	}
	CS = 1; 			    
} 		 

//SPI������ 	   
/*u16 SPI_Read()	  
{ 	 
	u8 i;
	u16 dat; 	  
	SCLK=0; 	 
	SPI_CS=0;  
	SCLK=1;  	    
	SCLK=0; 	 
	for(i=0;i<16;i++)  
	{ 				  
		dat<<=1; 	 
		SCLK=0;//�½�����Ч  	    	   
		SCLK=1;
		if(SDOUT)dat++; 		 
	}  	
	SPI_CS=1;	 
	return(dat);   
} */
