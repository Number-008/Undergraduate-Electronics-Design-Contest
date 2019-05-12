set_global_assignment -name FAMILY "Cyclone II"
set_global_assignment -name DEVICE EP2C5T144C8
set_global_assignment -name RESERVE_ALL_UNUSED_PINS "AS INPUT TRI-STATED"
set_global_assignment -name CYCLONEII_RESERVE_NCEO_AFTER_CONFIGURATION "USE AS REGULAR IO"
set_global_assignment -name USE_CONFIGURATION_DEVICE ON
set_global_assignment -name STRATIX_CONFIGURATION_DEVICE EPCS1
set_global_assignment -name SMART_RECOMPILE ON
#--------------------------CLK--------------------#
set_location_assignment	PIN_17	-to	CLOCK
set_location_assignment	PIN_90	-to	RST_N
#--------------------------LED--------------------#
#set_location_assignment PIN_73  	-to 	LED
#-------------------------KEY_XY------------------#
set_location_assignment PIN_96  	-to KEY[0]
set_location_assignment PIN_93  	-to KEY[1]
set_location_assignment PIN_87  	-to KEY[2]
set_location_assignment PIN_81  	-to KEY[3]
set_location_assignment PIN_79  	-to KEY[4]
set_location_assignment PIN_75  	-to KEY[5]
set_location_assignment PIN_73  	-to KEY[6]
set_location_assignment PIN_74  	-to KEY[7]
#----------------------LCD11----------------------#
set_location_assignment PIN_112  -to  LCD_D[7]
set_location_assignment PIN_103  -to  LCD_D[6]
set_location_assignment PIN_100  -to  LCD_D[5]
set_location_assignment PIN_97  	-to  LCD_D[4]
set_location_assignment PIN_94  	-to  LCD_D[3]
set_location_assignment PIN_92  	-to  LCD_D[2]
set_location_assignment PIN_86  	-to  LCD_D[1]
set_location_assignment PIN_80  	-to  LCD_D[0]
set_location_assignment PIN_99  	-to  LCD_RS
set_location_assignment PIN_101  -to  LCD_RW
set_location_assignment PIN_104  -to  LCD_E
#----------------------SPI-----------------------#
set_location_assignment	PIN_144		-to  SPWM

#------------------------END------------------------#