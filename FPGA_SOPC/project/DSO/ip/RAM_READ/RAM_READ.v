module RAM_READ(
             // clk inputs:
				  csi_clk,
				  csi_reset_n,
				 // Avalon-MM Slave  
              avs_chipselect,
              avs_address,
				  avs_read, 
              avs_readdata,
     
				  coe_DATA_IN,
				  coe_ADDR_OUT
           )
;
  
  output  [7:0] avs_readdata;
  input            csi_clk;
  input            csi_reset_n;
  input            avs_chipselect;
  input         	 avs_read;
  input   [8:0] avs_address;
  output	 reg [8:0] coe_ADDR_OUT; 
  input   [7:0] coe_DATA_IN;

  always @(posedge csi_clk,negedge csi_reset_n)
  if(!csi_reset_n)coe_ADDR_OUT<=9'b0;
  else coe_ADDR_OUT<=avs_address;
  
  

  
assign avs_readdata = (avs_chipselect & avs_read) ? coe_DATA_IN : 8'b0;    

endmodule

