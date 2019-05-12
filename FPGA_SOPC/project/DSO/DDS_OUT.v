module DDS_OUT(clk,Din,Dout);
input clk;
input [7:0] Din;
output Dout;
reg Dout;

 always @(posedge clk)
 if(Din>8'b0111_1111)  Dout<=1'b1;
	else Dout <=1'b0;
	
endmodule
