set_global_assignment -name FAMILY "Cyclone II"
set_global_assignment -name DEVICE EP2C8Q208C8
set_global_assignment -name RESERVE_ALL_UNUSED_PINS "AS INPUT TRI-STATED"
set_global_assignment -name CYCLONEII_RESERVE_NCEO_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_global_assignment -name USE_CONFIGURATION_DEVICE ON
set_global_assignment -name STRATIX_CONFIGURATION_DEVICE EPCS16
set_global_assignment -name SMART_RECOMPILE ON
#--------------------GLOBAL-----------------------#
set_location_assignment	PIN_23	-to	CLK
set_location_assignment	PIN_206	-to	RST_N 
set_location_assignment PIN_129   -to  clk_test
#----------------------LCD--------------------------#
set_location_assignment PIN_133  -to  LCD_D[7]
set_location_assignment PIN_118  -to  LCD_D[6]
set_location_assignment PIN_127  -to  LCD_D[5]
set_location_assignment PIN_116  -to  LCD_D[4]
set_location_assignment PIN_117  -to  LCD_D[3]
set_location_assignment PIN_114  -to  LCD_D[2]
set_location_assignment PIN_115  -to  LCD_D[1]
set_location_assignment PIN_112  -to  LCD_D[0]
set_location_assignment PIN_134  -to  LCD_RS
set_location_assignment PIN_135  -to  LCD_RW
set_location_assignment PIN_128  -to  LCD_EN
#
set_location_assignment PIN_106  -to  KEY[3]
set_location_assignment PIN_110  -to  KEY[2]
set_location_assignment PIN_30  -to  KEY[1]
set_location_assignment PIN_105  -to  KEY[0]
set_location_assignment PIN_80  -to  SW[2]
set_location_assignment PIN_74  -to  SW[1]
set_location_assignment PIN_76  -to  SW[0]
#
set_location_assignment PIN_33 -to DA_CLK
set_location_assignment PIN_43 -to DA[0]
set_location_assignment PIN_69 -to DA[1]
set_location_assignment PIN_87 -to DA[2]
set_location_assignment PIN_84 -to DA[3]
set_location_assignment PIN_40 -to DA[4]
set_location_assignment PIN_48 -to DA[5]
set_location_assignment PIN_57 -to DA[6]
set_location_assignment PIN_31 -to DA[7]
set_location_assignment PIN_70 -to DA[8]
set_location_assignment PIN_75 -to DA[9]
set_location_assignment PIN_89 -to DA[10]
set_location_assignment PIN_39 -to DA[11]
#
set_location_assignment PIN_4 -to SDR_WE
set_location_assignment PIN_168 -to SDR_RAS
set_location_assignment PIN_208 -to SDR_CS
set_location_assignment PIN_182 -to SDR_CLK
set_location_assignment PIN_181 -to SDR_CKE
set_location_assignment PIN_3 -to SDR_CAS
set_location_assignment PIN_5 -to SDR_DQM[0]
set_location_assignment PIN_185 -to SDR_DQM[1]
set_location_assignment PIN_15 -to SDR_DA[0]
set_location_assignment PIN_14 -to SDR_DA[1]
set_location_assignment PIN_13 -to SDR_DA[2]
set_location_assignment PIN_12 -to SDR_DA[3]
set_location_assignment PIN_11 -to SDR_DA[4]
set_location_assignment PIN_10 -to SDR_DA[5]
set_location_assignment PIN_8 -to SDR_DA[6]
set_location_assignment PIN_6 -to SDR_DA[7]
set_location_assignment PIN_187 -to SDR_DA[8]
set_location_assignment PIN_188 -to SDR_DA[9]
set_location_assignment PIN_189 -to SDR_DA[10]
set_location_assignment PIN_191 -to SDR_DA[11]
set_location_assignment PIN_192 -to SDR_DA[12]
set_location_assignment PIN_193 -to SDR_DA[13]
set_location_assignment PIN_195 -to SDR_DA[14]
set_location_assignment PIN_197 -to SDR_DA[15]
set_location_assignment PIN_207 -to SDR_BA[0]
set_location_assignment PIN_205 -to SDR_BA[1]
set_location_assignment PIN_201 -to SDR_AD[0]
set_location_assignment PIN_200 -to SDR_AD[1]
set_location_assignment PIN_199 -to SDR_AD[2]
set_location_assignment PIN_198 -to SDR_AD[3]
set_location_assignment PIN_170 -to SDR_AD[4]
set_location_assignment PIN_171 -to SDR_AD[5]
set_location_assignment PIN_173 -to SDR_AD[6]
set_location_assignment PIN_175 -to SDR_AD[7]
set_location_assignment PIN_176 -to SDR_AD[8]
set_location_assignment PIN_180 -to SDR_AD[11]
set_location_assignment PIN_169 -to SDR_AD[12]
set_location_assignment PIN_203 -to SDR_AD[10]
set_location_assignment PIN_179 -to SDR_AD[9]
set_location_assignment PIN_99 -to SRAM_CS
set_location_assignment PIN_95 -to SRAM_LB
set_location_assignment PIN_96 -to SRAM_OE
set_location_assignment PIN_97 -to SRAM_UB
set_location_assignment PIN_94 -to SRAM_WE
#---------------------END-----------------------#