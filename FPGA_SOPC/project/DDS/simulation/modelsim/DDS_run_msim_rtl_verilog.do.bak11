transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+F:/FPGA_Program/DDS0 {F:/FPGA_Program/DDS0/DDS.v}
vlog -vlog01compat -work work +incdir+F:/FPGA_Program/DDS0 {F:/FPGA_Program/DDS0/PLL.v}
vlog -vlog01compat -work work +incdir+F:/FPGA_Program/DDS0 {F:/FPGA_Program/DDS0/DDSROM.v}

vlog -vlog01compat -work work +incdir+F:/FPGA_Program/DDS0/simulation/modelsim {F:/FPGA_Program/DDS0/simulation/modelsim/DDS.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneii_ver -L rtl_work -L work -voptargs="+acc"  DDS_vlg_tst

add wave *
view structure
view signals
run -all
