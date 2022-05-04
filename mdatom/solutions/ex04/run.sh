#!/bin/bash

# directory paths
input_files_directory=/home/youwuyou/Workspaces/SPCS/mdatom/build
helper_scripts_directory=/home/youwuyou/Workspaces/SPCS/helper_scripts

# copy the file from last repo to the current one
cp ../ex03/coords.final coords_init

# run mdatom with given parameter file - coordinates are generated automatically
../mdatom ${input_files_directory}/ex04/params.inp coords_init > result04.txt

# extract g(r)
python3 ${helper_scripts_directory}/gr.py result04.txt > gr

# plot g(r)
gnuplot plot.gnuplot

# plot coords
gnuplot plot_coords.gnuplot
