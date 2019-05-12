#include"fpga_51.h"

#ifndef MUCH_DATA
void Write_FPGA_Com(u8r dat)//写0无效
{
	FPGA_CS=0;
	FPGA_WriteReg = dat;
	FPGA_CS=1;
}

void Write_FPGA_Data(u32 dat)//无符号长整型 u32
{
	FPGA_CS=0;
	FPGA_R4 = (dat>>24)& 0xff;//0004
	FPGA_R3 = (dat>>16)& 0xff;//0043
	FPGA_R2 = (dat>>8)& 0xff; //0432
	FPGA_R1 = dat & 0xff;	  //4321
	FPGA_CS=1;

}

u32 Read_FPGA_Data()
{
	unsigned long int temp;
	FPGA_CS=0;
	temp = FPGA_R4;		//0004
	temp <<= 8;	   		//0040
	temp += FPGA_R3;	//0043
	temp <<= 8;			//0430
	temp += FPGA_R2;	//0432
	temp <<= 8;			//4320
	temp += FPGA_R1;	//4321
	FPGA_CS=1;
	return temp;
}

#else

void Write_FPGA_Data(u8 Reg,u32 dat)//无符号长整型 u32
{
	FPGA_CS=0;
	FPGA_WriteReg = Reg;
	FPGA_R4 = (dat>>24)& 0xff;
	FPGA_R3 = (dat>>16)& 0xff;
	FPGA_R2 = (dat>>8)& 0xff;
	FPGA_R1 = dat & 0xff;
	FPGA_CS=1;

}

u32 Read_FPGA_Data(u8 Reg)
{
	u32 temp;
	FPGA_CS=0;
	FPGA_WriteReg = Reg;
	temp = FPGA_R4;
	temp <<= 8;
	temp += FPGA_R3;
	temp <<= 8;
	temp += FPGA_R2;
	temp <<= 8;
	temp += FPGA_R1;
	FPGA_CS=1;
	return temp;
}

#endif