#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: F:\Qsys\SPWM\Qsys_EP2C5\output_files\Qsys_EP2C5.sof to: "..\flash/Qsys_EP2C5_epcs.flash"
#
sof2flash --input="F:/Qsys/SPWM/Qsys_EP2C5/output_files/Qsys_EP2C5.sof" --output="../flash/Qsys_EP2C5_epcs.flash" --epcs --verbose 

#
# Programming File: "..\flash/Qsys_EP2C5_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/Qsys_EP2C5_epcs.flash" --base=0x5000 --epcs --sidp=0x6038 --id=0x0 --timestamp=1375083247 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

#
# Converting ELF File: F:\Qsys\SPWM\Qsys_EP2C5\software\SPWM\SPWM.elf to: "..\flash/SPWM_epcs.flash"
#
elf2flash --input="F:/Qsys/SPWM/Qsys_EP2C5/software/SPWM/SPWM.elf" --output="../flash/SPWM_epcs.flash" --epcs --after="../flash/Qsys_EP2C5_epcs.flash" --verbose 

#
# Programming File: "..\flash/SPWM_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/SPWM_epcs.flash" --base=0x5000 --epcs --sidp=0x6038 --id=0x0 --timestamp=1375083247 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

