############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project copy_streams
set_top copy_streams
add_files ../src/copy_streams.cpp
add_files ../src/copy_streams.h
add_files -tb ../tb/copy_streams_test.cpp
add_files -tb ../tb/elon_720.bmp
open_solution "solution1"

# zynq 045
#set_part {xc7z045ffg900-3} -tool vivado

#vcu108
set_part {xcvu095-ffva2104-2-e} -tool vivado

create_clock -period 5 -name default
#source "./hit_calc_256_stream_mem/solution1/directives.tcl"
csim_design -compiler gcc
csynth_design
#cosim_design -rtl vhdl -tool xsim
export_design -rtl vhdl -format ip_catalog
