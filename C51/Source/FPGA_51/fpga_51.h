#ifndef __FPGA_51_H
#define __FPGA_51_H	
#include<absacc.h>
#include "my_types.h"

#define	MUCH_DATA //如果读取的数据不是很多可以注释掉本句

//  FPGA_CS-- P1^0 
//  FPGA_RS--A5	
//  FPGA_ADD1--A4	
//  FPGA_ADD2--A3 

sbit	 FPGA_CS=P1^0; 
#define  FPGA_WriteReg XBYTE[0x18]//只写！	
#define  FPGA_R1 XBYTE[0x20]//	
#define  FPGA_R2 XBYTE[0x28]// 
#define  FPGA_R3 XBYTE[0x30]// 
#define  FPGA_R4 XBYTE[0x38]// 

#ifndef MUCH_DATA
 void Write_FPGA_Com(u8 dat);
 void Write_FPGA_Data(u32 dat);//无符号长整型 u32
u32 Read_FPGA_Data();

#else

 void Write_FPGA_Data(u8 Reg,u32 dat);//无符号长整型 u32
 u32 Read_FPGA_Data(u8 Reg);
#endif/*MUCH_DATA*/

#endif /*__FPGA_51_H*/ 