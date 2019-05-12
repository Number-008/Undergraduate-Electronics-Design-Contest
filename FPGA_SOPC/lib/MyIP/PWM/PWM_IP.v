/***************************************************************
  Filename    : PWM_IP.v
  Created on: : 2013/08/11 
  Athor       : Qin Hai Cheng
  Function    : 产生PWM信号，频率、占空比可预置
***************************************************************/
module PWM_IP(
				 // inputs:
				  csi_clk,
              csi_reset_n,
             // Avalon-MM Slave   
              avs_chipselect,
				  avs_address, 
              avs_write,
              avs_writedata,
				  
				  coe_PWM_CLK,
				  PWM_OUT,
				  PWM_N_OUT
					);
  input         csi_clk;
  input         csi_reset_n;
  input         avs_chipselect;
  input	[1:0]  avs_address; 
  input         avs_write;
  input  [31:0] avs_writedata;

  input coe_PWM_CLK;
  output PWM_OUT,PWM_N_OUT,PWM_N_OUT;

  reg PWM_EN,PWM_OUT;
  reg [31:0]cnt;
  reg [31:0]PWM_T,PWM_D;
  //地址译码
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
	begin 
		PWM_EN	<=0;
		PWM_T		<=0;
		PWM_D		<=0;
	end
	else if (avs_chipselect && avs_write)  
	begin  
		case (avs_address)  
			0:PWM_EN 		<= avs_writedata[0]; 
			1:PWM_T[31:0] 	<= avs_writedata[31:0];
			2:PWM_D[31:0] 	<= avs_writedata[31:0];
			default:;
		endcase  
	end  
end
	 	 
always @(posedge coe_PWM_CLK,negedge csi_reset_n)
begin
	if(csi_reset_n==0)
		cnt<=0;
	else 
	begin
		if(PWM_EN)
		begin
			if(cnt>=PWM_T)
				cnt<=0;
				else 
					cnt<=cnt+1;
		end
		else cnt<=0;
	end
end

always @(posedge coe_PWM_CLK,negedge csi_reset_n)
begin
	if(csi_reset_n==0)
		PWM_OUT<=0;
		else
		begin
			if(PWM_EN)
			begin
				if(cnt==PWM_D)
					PWM_OUT<=1'b0;
				else if(cnt==PWM_T)
					PWM_OUT<=1'b1;
			end
			else 
				PWM_OUT<=1'b0;
		end
end

always @(posedge coe_PWM_CLK,negedge csi_reset_n)
begin
	if(csi_reset_n==0)
		PWM_N_OUT<=0;
		else
		begin
			if(PWM_EN)
			begin
				if(cnt==(PWM_D-100))
					PWM_N_OUT<=1'b1;
				else if(cnt==(PWM_T+100))
					PWM_N_OUT<=1'b0;
			end
			else 
				PWM_N_OUT<=1'b0;
		end
end

endmodule
