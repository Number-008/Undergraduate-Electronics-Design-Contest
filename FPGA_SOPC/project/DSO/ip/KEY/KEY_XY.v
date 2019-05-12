module KEY_XY(
            // clk inputs:
				  csi_clk,
				  csi_reset_n,
				 // Avalon-MM Slave  
              avs_chipselect,
//              avs_address,
				  avs_write,  
				  avs_writedata,
				  avs_read, 
              avs_readdata,
             //KEY_IN interface:
				  coe_KEY_IN
           )
;
  parameter KEY_WIDTH = 8;
  input   [KEY_WIDTH-1: 0] avs_writedata;
  output  [KEY_WIDTH-1: 0] avs_readdata;
  input            csi_clk;
  input            csi_reset_n;
  input            avs_chipselect;
  input            avs_write;
  input         	 avs_read;

  output  [KEY_WIDTH-1: 0] coe_KEY_IN;
  reg 	 [KEY_WIDTH-1: 0]	coe_KEY_IN;
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
		coe_KEY_IN <= 8'hff;
			else if (avs_chipselect & avs_write)
			coe_KEY_IN   <= avs_writedata ;		
end

//读KEY input
  
assign avs_readdata = (avs_chipselect & avs_read) ? coe_KEY_IN : {{KEY_WIDTH-1}{1'b0}};    

endmodule

