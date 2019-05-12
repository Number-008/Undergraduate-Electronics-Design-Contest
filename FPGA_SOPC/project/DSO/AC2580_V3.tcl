set_global_assignment -name FAMILY "Cyclone II"
set_global_assignment -name DEVICE EP2C8Q208C8
set_global_assignment -name USE_CONFIGURATION_DEVICE ON
set_global_assignment -name STRATIX_CONFIGURATION_DEVICE EPCS4
set_global_assignment -name SMART_RECOMPILE ON
set_global_assignment -name MIN_CORE_JUNCTION_TEMP 0
set_global_assignment -name MAX_CORE_JUNCTION_TEMP 85
set_global_assignment -name STRATIX_DEVICE_IO_STANDARD "3.3-V LVTTL"
set_global_assignment -name RESERVE_ALL_UNUSED_PINS "AS INPUT TRI-STATED"
set_global_assignment -name RESERVE_DATA0_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_global_assignment -name RESERVE_DATA1_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_global_assignment -name CYCLONEII_RESERVE_NCEO_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_global_assignment -name RESERVE_DCLK_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_instance_assignment -name GLOBAL_SIGNAL "GLOBAL CLOCK" -to CLOCK
set_instance_assignment -name CURRENT_STRENGTH_NEW "8mA" -to LED[3]
set_instance_assignment -name CURRENT_STRENGTH_NEW "8mA" -to LED[2]
set_instance_assignment -name CURRENT_STRENGTH_NEW "8mA" -to LED[1]
set_instance_assignment -name CURRENT_STRENGTH_NEW "8mA" -to LED[0]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_LED
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to AD_CLK
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to DA_CLK
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[15]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[14]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[13]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[12]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[11]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[10]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[9]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[8]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[7]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[6]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[5]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[4]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[3]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[2]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[1]
set_instance_assignment -name CURRENT_STRENGTH_NEW "MAXIMUM CURRENT" -to LCD_DB[0]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to DJD
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DA_CLK
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to AD_CLK
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[7]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[6]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[5]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[4]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[3]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[2]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[1]
set_instance_assignment -name FAST_INPUT_REGISTER ON -to ADdata_in[0]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[7]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[6]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[5]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[4]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[3]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[2]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[1]
set_instance_assignment -name FAST_OUTPUT_REGISTER ON -to DAC_DB[0]
#--------------------clk2--------------------#
set_location_assignment	PIN_23	-to	CLOCK
set_location_assignment	PIN_132	-to	CLOCK2
set_location_assignment	PIN_94	-to	RST_N 
set_location_assignment	PIN_110	-to	DJD 
set_location_assignment	PIN_116	-to	DDS_OUT 
set_location_assignment	PIN_112	-to   CLK_100K
#--------------------SPI---------------------------#
set_location_assignment	PIN_106	-to   SPI_CS
set_location_assignment	PIN_105	-to   SCLK
set_location_assignment	PIN_107	-to   MOSI
#set_location_assignment	PIN_165	-to   MISO
#--------------------LED---------------------------#
set_location_assignment PIN_95 -to LED[0]
set_location_assignment PIN_96 -to LED[1]
set_location_assignment PIN_97 -to LED[2]
set_location_assignment PIN_99 -to LED[3]
#---------------------KEY_XY--------------------------#
set_location_assignment PIN_88  -to KEY[0]
set_location_assignment PIN_89  -to KEY[1]
set_location_assignment PIN_90  -to KEY[2]
set_location_assignment PIN_92  -to KEY[3]
set_location_assignment PIN_101 -to KEY[4]
set_location_assignment PIN_102 -to KEY[5]
set_location_assignment PIN_103 -to KEY[6]
set_location_assignment PIN_104 -to KEY[7]
#---------------------AD--------------------------#
set_location_assignment	PIN_128	-to   AD_CLK
set_location_assignment PIN_134  -to ADdata_in[0]
set_location_assignment PIN_137  -to ADdata_in[1]
set_location_assignment PIN_139  -to ADdata_in[2]
set_location_assignment PIN_142  -to ADdata_in[3]
set_location_assignment PIN_144  -to ADdata_in[4]
set_location_assignment PIN_146  -to ADdata_in[5]
set_location_assignment PIN_149  -to ADdata_in[6]
set_location_assignment PIN_151  -to ADdata_in[7]
#---------------------DA--------------------------#
set_location_assignment	PIN_160	-to   DA_CLK
set_location_assignment PIN_161  -to DAC_DB[0]
set_location_assignment PIN_162  -to DAC_DB[1]
set_location_assignment PIN_163  -to DAC_DB[2]
set_location_assignment PIN_164  -to DAC_DB[3]
set_location_assignment PIN_165  -to DAC_DB[4]
set_location_assignment PIN_168  -to DAC_DB[5]
set_location_assignment PIN_169  -to DAC_DB[6]
set_location_assignment PIN_170  -to DAC_DB[7]
#----------------------SSD1298---------------------#
set_location_assignment PIN_180 -to LCD_LED
set_location_assignment PIN_191 -to LCD_RST
set_location_assignment PIN_182 -to LCD_RD
set_location_assignment PIN_193 -to LCD_WR 
set_location_assignment PIN_187 -to LCD_RS 
set_location_assignment PIN_197 -to LCD_CS
# 
set_location_assignment PIN_189 -to LCD_DB[15] 
set_location_assignment PIN_192 -to LCD_DB[13] 
set_location_assignment PIN_195 -to LCD_DB[11]
set_location_assignment PIN_198 -to LCD_DB[9]
set_location_assignment PIN_200 -to LCD_DB[7]  
set_location_assignment PIN_203 -to LCD_DB[5] 
set_location_assignment PIN_207 -to LCD_DB[3]   
set_location_assignment PIN_5   -to LCD_DB[1]
# 
set_location_assignment PIN_199 -to LCD_DB[14]
set_location_assignment PIN_201 -to LCD_DB[12]
set_location_assignment PIN_205 -to LCD_DB[10]
set_location_assignment PIN_208 -to LCD_DB[8] 
set_location_assignment PIN_4   -to LCD_DB[6]  
set_location_assignment PIN_10  -to LCD_DB[4]   
set_location_assignment PIN_12  -to LCD_DB[2]   
set_location_assignment PIN_14  -to LCD_DB[0] 
#---------------------SDRAM38-------------------------#
set_location_assignment PIN_87 -to sdram_D[0] 
set_location_assignment PIN_86 -to sdram_D[1]
set_location_assignment PIN_84 -to sdram_D[2] 
set_location_assignment PIN_82 -to sdram_D[3]
set_location_assignment PIN_81 -to sdram_D[4] 
set_location_assignment PIN_80 -to sdram_D[5]
set_location_assignment PIN_77 -to sdram_D[6] 
set_location_assignment PIN_76 -to sdram_D[7]
set_location_assignment PIN_41 -to sdram_D[8] 
set_location_assignment PIN_43 -to sdram_D[9]
set_location_assignment PIN_44 -to sdram_D[10] 
set_location_assignment PIN_45 -to sdram_D[11]
set_location_assignment PIN_46 -to sdram_D[12] 
set_location_assignment PIN_56 -to sdram_D[13]
set_location_assignment PIN_57 -to sdram_D[14] 
set_location_assignment PIN_58 -to sdram_D[15]
#
set_location_assignment PIN_63 -to sdram_A[0] 
set_location_assignment PIN_61 -to sdram_A[1]
set_location_assignment PIN_60 -to sdram_A[2] 
set_location_assignment PIN_59 -to sdram_A[3]
set_location_assignment PIN_37 -to sdram_A[4] 
set_location_assignment PIN_39 -to sdram_A[5]
set_location_assignment PIN_35 -to sdram_A[6] 
set_location_assignment PIN_34 -to sdram_A[7]
set_location_assignment PIN_33 -to sdram_A[8] 
set_location_assignment PIN_31 -to sdram_A[9]
set_location_assignment PIN_64 -to sdram_A[10] 
set_location_assignment PIN_30 -to sdram_A[11]
#
set_location_assignment PIN_68 -to sdram_BA[0] 
set_location_assignment PIN_67 -to sdram_BA[1]
set_location_assignment PIN_75 -to sdram_DQM[0] 
set_location_assignment PIN_40 -to sdram_DQM[1]
set_location_assignment PIN_69 -to sdram_CS
set_location_assignment PIN_70 -to sdram_RAS
set_location_assignment PIN_72 -to sdram_CAS
set_location_assignment PIN_74 -to sdram_WE 
set_location_assignment PIN_47 -to sdram_CKE
set_location_assignment PIN_48 -to sdram_CLK
#---------------------END-----------------------#