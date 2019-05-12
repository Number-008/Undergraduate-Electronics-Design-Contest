module KEY_IN (
             // clk inputs:
				  csi_clk,
				  csi_reset_n,
				 // Avalon-MM Slave  
              avs_chipselect,
              avs_address,
              avs_write,
				  avs_read, 
              avs_writedata,
              avs_irq,
              avs_readdata,
				  
             //KEY_IN interface:
				  coe_KEY_IN
           )
;

  output           avs_irq;
  output  [ 31: 0] avs_readdata;
  input   [ 31: 0] avs_writedata;
  input            csi_clk;
  input            csi_reset_n;
  input            avs_chipselect;
  input            avs_write;
  input         	 avs_read;
  input   [  1: 0] avs_address;
  input   [  3: 0] coe_KEY_IN;

  reg     [  3: 0] d1_data_in;
  reg     [  3: 0] d2_data_in;
  wire    [  3: 0] data_in;
  reg     [  3: 0] edge_capture;           //边沿捕获
  wire             edge_capture_wr_strobe; //边沿捕获闸门
  wire    [  3: 0] edge_detect;            //边沿检测
  wire             avs_irq;                //中断信号
  reg     [  3: 0] irq_mask;               //中断屏蔽控制

  
//读KEY input
  reg  [3:0] readdata_r;   
always@(posedge csi_clk or negedge csi_reset_n) 
begin
	if (csi_reset_n == 0)
		readdata_r  <= 4'b0;
	else if (avs_chipselect && avs_read && avs_address == 0)  
      readdata_r  <= data_in;  
     else  
      readdata_r  <= 4'b0; 
end		
assign data_in = coe_KEY_IN; 	  
assign avs_readdata = {24'b0, readdata_r};    

always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
		irq_mask <= 0;
   else if (avs_chipselect && avs_write && (avs_address == 2))
      irq_mask <= avs_writedata[3 : 0];
end


  assign avs_irq = |(edge_capture & irq_mask);
  assign edge_capture_wr_strobe = avs_chipselect && avs_write && (avs_address == 3);
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
		edge_capture[0] <= 0;
	else if (edge_capture_wr_strobe)
		edge_capture[0] <= 0;
		 else if (edge_detect[0])
			edge_capture[0] <= -1;
end
always @(posedge csi_clk or negedge csi_reset_n)
 begin
	if (csi_reset_n == 0)
		 edge_capture[1] <= 0;
	else
		 if (edge_capture_wr_strobe)
			  edge_capture[1] <= 0;
		 else if (edge_detect[1])
			  edge_capture[1] <= -1;
end
always @(posedge csi_clk or negedge csi_reset_n)
 begin
	if (csi_reset_n == 0)
		 edge_capture[2] <= 0;
	else
		 if (edge_capture_wr_strobe)
			  edge_capture[2] <= 0;
		 else if (edge_detect[2])
			  edge_capture[2] <= -1;
 end
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
		 edge_capture[3] <= 0;
	else
		 if (edge_capture_wr_strobe)
			  edge_capture[3] <= 0;
		 else if (edge_detect[3])
			  edge_capture[3] <= -1;
 end
always @(posedge csi_clk or negedge csi_reset_n)
begin
	if (csi_reset_n == 0)
	  begin
		 d1_data_in <= 0;
		 d2_data_in <= 0;
	  end
	else
	  begin
		 d1_data_in <= data_in;
		 d2_data_in <= d1_data_in;
	  end
 end
assign edge_detect = ~d1_data_in & d2_data_in;

endmodule

