module RAM_WRITE(
             // clk inputs:
				  csi_clk,
				  csi_reset_n,
				 // Avalon-MM Slave  
              avs_chipselect,
              avs_address,
				  avs_write, 
              avs_writedata,
     
				  coe_DATA_OUT,
				  coe_ADDR,
				  coe_WRITE_EN
           )
;
  parameter       			RAM_WIDTH = 12;//RAM地址的宽度
  input         				csi_clk;
  input         				csi_reset_n;
  input         				avs_chipselect;
  input	[RAM_WIDTH-1:0]	avs_address; 
  input         				avs_write;
  input  [31:0] 				avs_writedata;
  
  output [RAM_WIDTH-1:0]	coe_DATA_OUT;
  output [RAM_WIDTH-1:0]	coe_ADDR;
  output 						coe_WRITE_EN;
  reg 	[RAM_WIDTH-1:0] 	DATA_OUT;
  


	
//地址译码
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
	begin
		DATA_OUT  <= 0;
	end
	else if (avs_chipselect && avs_write)  
	begin  
		DATA_OUT[RAM_WIDTH-1:0]  <= avs_writedata[RAM_WIDTH-1:0];
	end  
end

assign coe_WRITE_EN = (avs_chipselect);
assign coe_ADDR = avs_address;
assign coe_DATA_OUT = DATA_OUT;
   
endmodule

