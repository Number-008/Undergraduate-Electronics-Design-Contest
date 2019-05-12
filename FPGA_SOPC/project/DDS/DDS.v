module DDS(CLK,RST_N,FREQW,PHASEW,DA_DB);

  parameter       ROMAD_WIDTH = 8;//DA地址的宽度
  
  input 							 CLK,RST_N;
  output	[ROMAD_WIDTH-1:0]  DA_DB;				//输出D/A数据
  input 	[31:0]   FREQW;				//频率寄存器
  input 	[ROMAD_WIDTH-1:0]  PHASEW;				//相位寄存器
  reg 	[31:0]  ACC;					//累加器的寄存器
  wire 	[ROMAD_WIDTH-1:0]  ROMADDR;
	

PLL u0(
	.inclk0(CLK),
	.c0(DDS_CLK));
	
always @(posedge DDS_CLK,negedge RST_N) //累加器
begin
	if(RST_N==0)
		ACC<=0;
	else
		ACC <= ACC + FREQW;
end
	
assign ROMADDR = ACC[31: 32 - ROMAD_WIDTH] + PHASEW;//相位调制器

DDSROM u1(
	.address(ROMADDR),
	.clock(DDS_CLK),
	.q(DA_DB));
   
endmodule
