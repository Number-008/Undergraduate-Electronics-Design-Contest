module bjq(CLK,D1,D2,Y);

input CLK;
input [9:0] D1,D2;
output Y;

reg Y;

always @(posedge CLK)
if(D1>=D2) Y<=1'b1;
else Y<=1'b0;

endmodule
