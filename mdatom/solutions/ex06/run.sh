#!/bin/bash

# directory paths
input_files_directory=/home/youwuyou/Workspaces/SPCS/mdatom/build
helper_scripts_directory=/home/youwuyou/Workspaces/SPCS/helper_scripts

# run mdatom with given parameter file - coordinates are generated automatically
../mdatom ${input_files_directory}/ex06/params.inp > result06.txt

# extract g(r)
python3 ${helper_scripts_directory}/gr.py result06.txt > gr

# plot g(r)
gnuplot plot.gnuplot

# extract energies
python3 ${helper_scripts_directory}/energy.py result06.txt > ex6_ene
python3 ${helper_scripts_directory}/energy.py ../ex03/result03.txt > ex3_ene


# plot energies
gnuplot plot_ene.gnuplot
