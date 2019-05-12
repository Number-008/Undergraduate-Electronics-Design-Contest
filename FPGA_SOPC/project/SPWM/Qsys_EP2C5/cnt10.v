module cnt10(clk,c);
input clk;
output [9:0] c;
reg [9:0]c;
reg [8:0] cnt;
reg clk_div;
always @(posedge clk)
if(cnt>=25)
begin
	clk_div<=~clk_div;
	cnt<=0;
end
	else 
		cnt<=cnt+1;

always @(posedge clk_div)
if(c>=9'b111111111)
	c<=0;
	else
		c<=c+1;

endmodule
