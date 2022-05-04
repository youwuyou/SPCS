#!/bin/bash

# directory paths
input_files_directory=/home/youwuyou/Workspaces/SPCS/mdatom/build
helper_scripts_directory=/home/youwuyou/Workspaces/SPCS/helper_scripts

# run mdatom with given parameter file - coordinates are generated automatically
../mdatom ${input_files_directory}/ex03/params.inp > result03.txt

# extract g(r)
python3 ${helper_scripts_directory}/gr.py result03.txt > gr

# plot g(r)
gnuplot plot.gnuplot

# plot coords
gnuplot plot_coords.gnuplot
