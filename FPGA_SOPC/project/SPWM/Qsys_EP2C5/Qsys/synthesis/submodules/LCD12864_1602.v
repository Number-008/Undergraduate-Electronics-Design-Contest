module LCD12864_1602(   
 // Clcok Input  

   input        csi_clk,  
   input        csi_reset_n,  
   // Avalon-MM Slave  
   input        avs_chipselect,  
   input [1:0]  avs_address,  
   input        avs_write,  
   input [7:0]  avs_writedata,  
   input        avs_read,  
   output[7:0]  avs_readdata,    
   // Conduit End   
   // lcd12864 interface  
   output reg   coe_e,  
   output reg   coe_rw,   
   output reg   coe_rs,  
   inout [7:0]  coe_data_io  

 );
 
 reg  [7:0] coe_data_o; 
 always@(posedge csi_clk, negedge csi_reset_n)  
 begin  
  if (!csi_reset_n)  
   begin   
    coe_e      <= 1'b1;  
    coe_rw     <= 1'b1;  
    coe_rs     <= 1'b1;  
    coe_data_o <= 8'hff;  
   end  
  else if (avs_chipselect & avs_write)  
  begin  
     case (avs_address)  
          0: coe_e      <= avs_writedata[0];  
          1: coe_rw     <= avs_writedata[0];  
          2: coe_rs     <= avs_writedata[0];  
          3: coe_data_o <= avs_writedata[7:0];  
     endcase  
  end  
end  
 

 reg  [7:0] readdata_r;  
 wire [7:0] coe_data_i;  
always@(posedge csi_clk)  
if (avs_chipselect & avs_read)    
    if (avs_address == 3)  
      readdata_r  <= coe_data_i;  
     else  
      readdata_r  <= 8'b0;  
  
assign avs_readdata =readdata_r;   
 
assign coe_data_i   = coe_data_io;  
assign coe_data_io  = (avs_chipselect & avs_write) ? coe_data_o : 8'bz;    


endmodule 
