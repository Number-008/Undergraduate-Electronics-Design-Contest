module FIFO_READ(
             // clk inputs:
				  csi_clk,
				  csi_reset_n,
				 // Avalon-MM Slave  
              avs_chipselect,
              avs_address,
				  avs_read, 
              avs_readdata,
     
				  coe_DATA_IN,
				  coe_rdempty,
				  coe_rdreq
           )
;
  
  output  [7:0] avs_readdata;
  output				 coe_rdreq;
  input            csi_clk;
  input            csi_reset_n;
  input            avs_chipselect;
  input         	 avs_read;
  input				 avs_address;
  input				 coe_rdempty;
  input   [7:0] coe_DATA_IN;


  
assign coe_rdreq=(avs_chipselect & avs_read & avs_address & !coe_rdempty);    
assign avs_readdata = (avs_chipselect & avs_read) ? (avs_address ? (coe_rdempty ? 8'b0 : coe_DATA_IN) : coe_rdempty): 8'b0;    

endmodule

