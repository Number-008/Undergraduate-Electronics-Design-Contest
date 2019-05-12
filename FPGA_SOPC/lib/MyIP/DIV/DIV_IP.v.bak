module div500(	input clk_in,
					output clk_out
				 );
				 
reg [7:0] cnt;
reg out;

always @(posedge clk_in)
begin
	if(cnt==249) 
	begin
		cnt<=0;
		out<=~out;
	end
	 else
	 cnt<=cnt+1;
end
				 
assign clk_out=out;
endmodule
