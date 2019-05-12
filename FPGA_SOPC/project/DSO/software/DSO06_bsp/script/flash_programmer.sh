#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: F:\Qsys\DSO_2014_1\output_files\DSO.sof to: "..\flash/DSO_epcs_flash.flash"
#
sof2flash --input="F:/Qsys/DSO_2014_1/output_files/DSO.sof" --output="../flash/DSO_epcs_flash.flash" --epcs --verbose 

#
# Programming File: "..\flash/DSO_epcs_flash.flash" To Device: epcs_flash
#
nios2-flash-programmer "../flash/DSO_epcs_flash.flash" --base=0x0 --epcs --sidp=0x24F0 --id=0x0 --timestamp=1400146849 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

#
# Converting ELF File: F:\Qsys\DSO_2014_1\software\DSO06\DSO06.elf to: "..\flash/DSO06_epcs_flash.flash"
#
elf2flash --input="F:/Qsys/DSO_2014_1/software/DSO06/DSO06.elf" --output="../flash/DSO06_epcs_flash.flash" --epcs --after="../flash/DSO_epcs_flash.flash" --verbose 

#
# Programming File: "..\flash/DSO06_epcs_flash.flash" To Device: epcs_flash
#
nios2-flash-programmer "../flash/DSO06_epcs_flash.flash" --base=0x0 --epcs --sidp=0x24F0 --id=0x0 --timestamp=1400146849 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

