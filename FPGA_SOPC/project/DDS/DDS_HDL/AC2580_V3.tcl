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
#---------------------DDS--------------------------#
set_location_assignment	PIN_160 -to DA_CLK 
set_location_assignment PIN_144 -to DA_DB[0]
set_location_assignment PIN_142 -to DA_DB[1]
set_location_assignment PIN_139 -to DA_DB[2]
set_location_assignment PIN_137 -to DA_DB[3]
set_location_assignment PIN_135 -to DA_DB[4]
set_location_assignment PIN_138 -to DA_DB[5]
set_location_assignment PIN_141 -to DA_DB[6]
set_location_assignment PIN_143 -to DA_DB[7]
#set_location_assignment PIN_145 -to DA_DB[8]
#set_location_assignment PIN_147 -to DA_DB[9]
#set_location_assignment PIN_150 -to DA_DB[10]
#set_location_assignment PIN_152 -to DA_DB[11]
#---------------------END-----------------------#