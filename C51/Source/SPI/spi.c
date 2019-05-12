#include"spi.h"
#include<absacc.h>
/*注意SPI有多种工作方式，应用时应根据具体器件的时序图来写，本程序只能当做编程思想的参考。*/

sbit DIN 	= P1^0;
sbit SCLK 	= P1^1;
sbit CS = P1^2;

//sbit SPI_CS = P2^3;
//SPI写数据  
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
		SCLK=1;//上升沿有效	   	 
		SCLK=0;      
	}
	CS = 1; 			    
} 		 

//SPI读数据 	   
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
		SCLK=0;//下降沿有效  	    	   
		SCLK=1;
		if(SDOUT)dat++; 		 
	}  	
	SPI_CS=1;	 
	return(dat);   
} */
