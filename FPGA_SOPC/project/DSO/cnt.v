module cnt(rst_n,clk_cnt,trig_in,wraddr,cnt_en,cnt_irq,wr_en);
input rst_n,clk_cnt,trig_in,cnt_en;
output cnt_irq,wr_en;
reg trig_en,cnt_irq,r,wr_en;
output reg [8:0] wraddr;

reg [7:0] d1,d2;
/*上升沿触发*/
always @(posedge trig_in)
begin
	if(trig_en )
		r<=1'b1;
		else
			r<=1'b0;
end
/*地址计数器*/
always @(posedge clk_cnt,negedge rst_n,negedge cnt_en)
begin
	if((!rst_n)| (!cnt_en))
	begin
		wr_en<=1;
		trig_en<=1;
		wraddr<=0;
		cnt_irq<=1'b0;
	end
	else if(r & cnt_en)
	begin
		wr_en<=1;
		wraddr<=0;
		trig_en<=0;
		cnt_irq<=1'b0;
	end
	else if(wraddr==9'b111111111)
		begin 
		wr_en<=0;
		cnt_irq<=1'b1;
		if(!cnt_en)trig_en<=1;//保存 
		end
	else	if(wraddr<9'b111111111 & cnt_en)
			wraddr<=wraddr+1;

end

endmodule
