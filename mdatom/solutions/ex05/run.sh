#!/bin/bash

# directory paths
input_files_directory=/home/youwuyou/Workspaces/SPCS/mdatom/build
helper_scripts_directory=/home/youwuyou/Workspaces/SPCS/helper_scripts

# copy the file from last repo to the current one
cp ../ex04/coords.final coords_init

# run mdatom with given parameter file - coordinates are generated automatically
../mdatom ${input_files_directory}/ex05/params.inp coords_init > result05.txt

# extract g(r)
python3 ${helper_scripts_directory}/gr.py result05.txt > gr

# plot g(r)
gnuplot plot.gnuplot

# plot coords
gnuplot plot_coords.gnuplot

# repeat simulations of ex04 and ex05 using PropertyPrintingInterval = 1 to make
# fair comparison, which was set like this in the one in ex03
cp ../ex03/result03.txt fullresult03.txt

../mdatom params_ex4_print_all.inp ../ex04/coords_init > fullresult04.txt
../mdatom params_ex5_print_all.inp ../ex05/coords_init > fullresult05.txt

# extract energies
python3 ${helper_scripts_directory}/energy.py fullresult03.txt > ex3_ene
python3 ${helper_scripts_directory}/energy.py fullresult04.txt > ex4_ene
python3 ${helper_scripts_directory}/energy.py fullresult05.txt > ex5_ene

# plot energies
gnuplot plot_ene.gnuplot
