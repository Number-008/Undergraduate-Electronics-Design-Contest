module LCD12864_IP(
				//系统时钟
					csi_clk,  
					csi_reset_n,     
				// Avalon-MM Slave
					avs_chipselect,	
					avs_address,  
					avs_write,  
					avs_writedata,  
					avs_read,		
					avs_readdata,      
				//LCD接口
					coe_LCD_E,  
					coe_LCD_RW,   
					coe_LCD_RS,  
					coe_LCD_DB
				 );

input 				csi_clk;
input					csi_reset_n;	 
input		[1:0]   	avs_address; 
input            	avs_write;
input         		avs_chipselect;
input             avs_read;
input  	[ 7: 0]  avs_writedata;
output 	[ 7: 0]  avs_readdata;

output 				coe_LCD_E; 
output				coe_LCD_RW; 
output				coe_LCD_RS;	
inout		[7:0]		coe_LCD_DB;				 


wire 				coe_LCD_E; 
wire				coe_LCD_RW; 
wire				coe_LCD_RS;	
wire		[7:0]	coe_LCD_DB;	
wire		[7:0] avs_readdata;			 
				 
  assign coe_LCD_E    =	avs_read | avs_write;				 				 
  assign coe_LCD_RW   = avs_address[0];//H--读，L--写
  assign coe_LCD_RS   = avs_address[1];//H--数据，L--指令
  assign coe_LCD_DB 	 = (avs_chipselect & (~avs_address[0])) ? avs_writedata : 8'bz;
  assign avs_readdata = coe_LCD_DB;
endmodule 

