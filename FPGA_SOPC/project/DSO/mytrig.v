module mytrig(clk,Din,Sin,trig_out);
input clk;
input [7:0] Din,Sin;
output trig_out;
reg trig_out;
always @(posedge clk)
begin
  if(Din>=Sin) trig_out <= 1'b1;
    else trig_out <=1'b0;

end


endmodule