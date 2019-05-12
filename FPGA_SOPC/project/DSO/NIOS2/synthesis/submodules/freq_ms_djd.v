module freq_ms_djd(
						input	csi_clk,
						input	csi_reset_n,
						input	avs_chipselect,
						input avs_address,
						input	avs_read, 
						output [31:0]avs_readdata,
						input coe_clk_ref,          //参考时钟
						input clk_test          //被测信号
						); 
						
reg ena;                    //等精度门控信号
reg clr;                    //清零信号
reg tgate;                  //时间门控信号
reg [31:0] timer;           //计时器信号
reg [31:0] ref_cnt;         //参考计数器
reg [31:0] test_cnt;        //被测计数器
reg [31:0] refer;
reg [31:0] test;

always @ (posedge coe_clk_ref)  //计时器：100MHZ时钟，计时1.1S
begin 
	if(timer==32'd110000001) 
		timer<=32'd0;
	else 
		timer<=timer+1;
end

always @ (negedge coe_clk_ref)    //时间门控信号：tgate,清零信号clr
begin  
		if(timer==32'd100000000) 
			tgate<=0;
		else 
			if(timer==32'd110000000)
				clr<=1; 
			else
				if(timer==32'd110000001) 
					begin clr<=0;tgate<=1;end 
end
//等精度门控信号产生：从tgate到ena，由被测信号clk_test触发
always @ (posedge clk_test or posedge clr)
begin
	if(clr==1) 
		ena<=1'b0;
	else  
		ena<=tgate;	
end

always @ (negedge csi_reset_n,negedge ena)  //每1.1S更新一次输出
begin
	if (!csi_reset_n)  
		begin   
			refer <= 32'b0; 
			test  <= 32'b0; 
		end
	else	
		begin 
			refer<=ref_cnt;
			test<=test_cnt;
		end
end
always @ (posedge coe_clk_ref or posedge clr) //参考时钟计数器
begin 
	if(clr==1)
		ref_cnt<=32'd0;
	else if(ena)
		ref_cnt<=ref_cnt+1;
end
always @(posedge clk_test or posedge clr) //被测信号计数器
begin
	if(clr==1)
		test_cnt<=32'd0;
	else if (ena) 
		test_cnt<=test_cnt+1;
end

assign avs_readdata = (avs_chipselect & avs_read) ? (avs_address==0 ? refer : test):32'b0; 

endmodule
