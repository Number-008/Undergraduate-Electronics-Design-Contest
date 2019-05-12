onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /DDS_vlg_tst/RST_N
add wave -noupdate /DDS_vlg_tst/CLK
add wave -noupdate /DDS_vlg_tst/i1/DDS_CLK
add wave -noupdate -radix unsigned /DDS_vlg_tst/FREQW
add wave -noupdate -radix unsigned /DDS_vlg_tst/PHASEW
add wave -noupdate -format Analog-Step -height 128 -max 255.0 -radix unsigned -childformat {{{/DDS_vlg_tst/DA_DB[7]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[6]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[5]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[4]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[3]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[2]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[1]} -radix unsigned} {{/DDS_vlg_tst/DA_DB[0]} -radix unsigned}} -subitemconfig {{/DDS_vlg_tst/DA_DB[7]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[6]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[5]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[4]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[3]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[2]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[1]} {-height 15 -radix unsigned} {/DDS_vlg_tst/DA_DB[0]} {-height 15 -radix unsigned}} /DDS_vlg_tst/DA_DB
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1025790000 ps} 0} {{Cursor 3} {1025779967 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {1025773008 ps} {1025818794 ps}
