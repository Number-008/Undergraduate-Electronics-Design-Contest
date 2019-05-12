module MY_RST(clk,rst_n_in, rst_n_out);
input clk;
input rst_n_in;
output rst_n_out;			  			  
reg a,b;
initial                                                
begin                                                  
 a=1;
 b=1; 
end 
always @(posedge clk,negedge rst_n_in)
begin 
	if(rst_n_in==0)
	begin
		a<=0;
		b<=0;
	end
	else
	begin
		a<=1'b1;
		b<=a;
	end
end
assign rst_n_out=b;
endmodule