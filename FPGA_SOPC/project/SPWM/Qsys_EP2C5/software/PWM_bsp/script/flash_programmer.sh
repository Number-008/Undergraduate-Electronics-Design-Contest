#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: F:\Qsys\Qsys_EP2C5\output_files\Qsys_EP2C5.sof to: "..\flash/Qsys_EP2C5_epcs.flash"
#
sof2flash --input="F:/Qsys/Qsys_EP2C5/output_files/Qsys_EP2C5.sof" --output="../flash/Qsys_EP2C5_epcs.flash" --epcs --verbose 

#
# Programming File: "..\flash/Qsys_EP2C5_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/Qsys_EP2C5_epcs.flash" --base=0x5000 --epcs --sidp=0x6078 --id=0x0 --timestamp=1375016821 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

#
# Converting ELF File: F:\Qsys\Qsys_EP2C5\software\PWM\PWM.elf to: "..\flash/PWM_epcs.flash"
#
elf2flash --input="F:/Qsys/Qsys_EP2C5/software/PWM/PWM.elf" --output="../flash/PWM_epcs.flash" --epcs --after="../flash/Qsys_EP2C5_epcs.flash" --verbose 

#
# Programming File: "..\flash/PWM_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/PWM_epcs.flash" --base=0x5000 --epcs --sidp=0x6078 --id=0x0 --timestamp=1375016821 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

