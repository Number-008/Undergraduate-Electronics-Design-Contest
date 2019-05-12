module AD(	input clk,
				input  [7:0]data_in,
				output reg [7:0]data_out
				);				
//reg [7:0]data_out;
always @(posedge clk)
begin
	data_out<=data_in;
end																
endmodule