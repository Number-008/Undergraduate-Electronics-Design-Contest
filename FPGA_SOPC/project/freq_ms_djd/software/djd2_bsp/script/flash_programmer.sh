#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: F:\Qsys\freq_ms_djd\output_files\freq_ms_djd.sof to: "..\flash/freq_ms_djd_epcs.flash"
#
sof2flash --input="F:/Qsys/freq_ms_djd/output_files/freq_ms_djd.sof" --output="../flash/freq_ms_djd_epcs.flash" --epcs --verbose 

#
# Programming File: "..\flash/freq_ms_djd_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/freq_ms_djd_epcs.flash" --base=0x9000 --epcs --sidp=0xA018 --id=0xA010 --timestamp=1386328807 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

#
# Converting ELF File: F:\Qsys\freq_ms_djd\software\djd2\djd2.elf to: "..\flash/djd2_epcs.flash"
#
elf2flash --input="F:/Qsys/freq_ms_djd/software/djd2/djd2.elf" --output="../flash/djd2_epcs.flash" --epcs --after="../flash/freq_ms_djd_epcs.flash" --verbose 

#
# Programming File: "..\flash/djd2_epcs.flash" To Device: epcs
#
nios2-flash-programmer "../flash/djd2_epcs.flash" --base=0x9000 --epcs --sidp=0xA018 --id=0xA010 --timestamp=1386328807 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

