/***************************************************************
  Filename    : DIV_IP.v
  Created on: : 2013/05/18 
  Athor       : Qin Hai Cheng
  Function    : 对时钟信号进行分频
***************************************************************/
module DIV_IP(	
             // inputs:
				input  csi_clk,
            input  csi_reset_n,
             // Avalon-MM Slave   
            input  avs_chipselect,
            input  avs_write,
            input  [31:0]avs_writedata,
				input  clk_in,
				output coe_clk_out
				 );
reg [31:0]data;			 
reg [31:0]cnt;
reg out;
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
	   data <= 32'b0;

	else if (avs_chipselect & avs_write) 
		 data[31:0]<=avs_writedata[31:0];

end
always @(posedge clk_in)
begin
	if(cnt==data) 
	begin
		cnt<=0;
		out<=~out;
	end
	 else if(cnt<data)
		cnt<=cnt+1;
		else
			cnt<=0;
end
				 
assign coe_clk_out=out;
endmodule
