module Cycle_Measure_IP(
						input	csi_clk,
						input	csi_reset_n,
						input	avs_chipselect,
						input	avs_read, 
						output [31:0]avs_readdata,
						input clk, 
						input coe_S_in 
);

reg Flag,clr;
reg [31:0] cnt,Cycle_R;

always @(posedge coe_S_in,negedge csi_reset_n)
begin
	if(csi_reset_n==0)
		Flag<=0;
		else
			Flag<=~Flag;
end

always @(posedge clk,negedge Flag)
begin
	if(Flag ==0) clr<=1'b0;	
		else clr<=1'b1;						
end

always @(negedge Flag)
	Cycle_R<=cnt;
	
always @(posedge clk,negedge csi_reset_n)
begin
	if(csi_reset_n==0)
		cnt<=0;
		else if(clr==0)
			cnt<=0;
			else if(Flag==1)
				cnt<=cnt+1;
end
assign avs_readdata = (avs_chipselect & avs_read) ? Cycle_R:32'b0; 

endmodule
