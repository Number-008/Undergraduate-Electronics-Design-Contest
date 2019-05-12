/***************************************************************
  Filename    : DDS_IP.v
  Created on: : 2013/05/18 
  Athor       : Qin Hai Cheng
  Function    : 48位累加器DDS IP核
***************************************************************/
module DDS_48_IP(
				 // inputs:
				  csi_clk,
              csi_reset_n,
             // Avalon-MM Slave   
              avs_chipselect,
				  avs_address, 
              avs_write,
              avs_writedata,

             // outputs:
				  coe_DDS_CLK,
              ROMADDR
					);
					
  //parameter       FREQ_WIDTH  = 32;//输入频率字的宽度
  //parameter       PHASE_WIDTH = 14;//输入相位字的宽度
  //parameter       ADDER_WIDTH = 32;//累加器的宽度
  parameter       ROMAD_WIDTH = 12;//DA地址的宽度
 
  input         	csi_clk;
  input         	csi_reset_n;
  input         	avs_chipselect;
  input	[1:0]	   avs_address; 
  input         	avs_write;
  input  [31 : 0] avs_writedata;
  
  input 							 coe_DDS_CLK;
  output	[ROMAD_WIDTH-1:0]  ROMADDR;				//输出D/A数据
  
  reg 	[47:0]  ACC;					//累加器的寄存器
  //wire 	[PHASE_WIDTH-1:0]  PHASEADD;
  wire 	[ROMAD_WIDTH-1:0]  ROMADDR;
  reg 	[47:0]   FREQW;				//频率寄存器
  reg 	[ROMAD_WIDTH-1:0]  PHASEW;				//相位寄存器

	
//地址译码
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
	begin
		FREQW  <= 0;
		PHASEW <= 0;
	end
	else if (avs_chipselect && avs_write)  
	begin  
		case (avs_address)  
			2'b00:FREQW [31:0] 	  	<= avs_writedata[31 : 0];
			2'b01:FREQW [47:32] 	  	<= avs_writedata[15 : 0]; 	
			2'b10:PHASEW     			<= avs_writedata[ROMAD_WIDTH-1: 0];
		endcase  
	end  
end

always @(posedge coe_DDS_CLK) //累加器
begin
	ACC <= ACC + FREQW;
end
	
assign ROMADDR = ACC[47: 48 - ROMAD_WIDTH] + PHASEW;//相位调制器
//assign ROMADDR  = PHASEADD[PHASE_WIDTH - 1: PHASE_WIDTH - ROMAD_WIDTH];
   
endmodule
