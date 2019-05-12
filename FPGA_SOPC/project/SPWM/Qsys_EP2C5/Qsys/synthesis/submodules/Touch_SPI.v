module Touch_SPI(
				 // inputs:
				  csi_clk,
              csi_reset_n,
             // Avalon-MM Slave   
              avs_chipselect,
				  avs_address, 
              avs_write_n,
              avs_writedata,
				  avs_readdata,

             // outputs:
              coe_TCS,
				  SCLK,
				  MOSI,
				  MISO
           )
;
  output coe_TCS,SCLK,MOSI;
  input	MISO;//主器件数据输入，从器件数据输出

  input         csi_clk;
  input         csi_reset_n;
  input         avs_chipselect;
  input	[1:0]  avs_address; 
  input         avs_write_n;
  input    		 avs_writedata;
  output   		 avs_readdata;

	
  reg     coe_TCS,SCLK,MOSI;
  wire    MISO;

	assign avs_readdata =(avs_chipselect & avs_write_n
		& avs_address==3 )? MISO : 1'b0;
//地址译码
  always @(posedge csi_clk or negedge csi_reset_n)
    begin
      if (csi_reset_n == 0)
		begin 
			coe_TCS	<=1;
			SCLK		<=1;
			MOSI		<=1;
		end
			else if (avs_chipselect && ~avs_write_n)  
				begin  
					case (avs_address)  
						0:coe_TCS 	<= avs_writedata; 
						1:SCLK 		<= avs_writedata;
						2:MOSI 		<= avs_writedata;
						default:;
					endcase  
				end  
    end

endmodule