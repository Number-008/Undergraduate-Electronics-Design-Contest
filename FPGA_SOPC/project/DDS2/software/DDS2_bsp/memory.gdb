# memory.gdb - GDB memory region definitions
#
# Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'NIOS2'
# SOPC Builder design path: F:/Qsys/DDS2/NIOS2.sopcinfo
#
# Generated: Wed May 14 17:44:37 CST 2014

# DO NOT MODIFY THIS FILE
#
# Changing this file will have subtle consequences
# which will almost certainly lead to a nonfunctioning
# system. If you do modify this file, be aware that your
# changes will be overwritten and lost when this file
# is generated again.
#
# DO NOT MODIFY THIS FILE

# License Agreement
#
# Copyright (c) 2008
# Altera Corporation, San Jose, California, USA.
# All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# This agreement shall be governed in all respects by the laws of the State
# of California and by the laws of the United States of America.

# Define memory regions for each memory connected to the CPU.
# The cache attribute is specified which improves GDB performance
# by allowing GDB to cache memory contents on the host.

# sdram
memory 0x2000000 0x4000000 cache

# onchip_memory2_0
memory 0x4041000 0x4042000 cache

# epcs_flash_controller_0
memory 0x4043000 0x4043800 cache
