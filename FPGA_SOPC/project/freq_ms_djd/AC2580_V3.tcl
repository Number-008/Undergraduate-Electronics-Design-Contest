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
#---------------------END-----------------------#