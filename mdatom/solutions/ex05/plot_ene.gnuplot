set autoscale
set xtics font ", 8" 100
set mxtics 2
set ytic auto
set xlabel "MD Step"
set ylabel "E_{kin} [kJ/mol]"

set terminal pdf
set output 'energy_kin.pdf'

set style line 1 lc rgb "#0000FF" lw 2
set style line 2 lc rgb "#00FF00" lw 2
set style line 3 lc rgb "#FF0000" lw 2


plot 'ex3_ene' using($1) : ($4) with line linestyle 1 title "E_{kin,3}", \
      'ex4_ene' using($1) : ($4) with line linestyle 2 title "E_{kin,4}", \
      'ex5_ene' using($1) : ($4) with line linestyle 3 title "E_{kin,5}", \

set output 'energy_pot.pdf'
set ylabel "E_{pot} [kJ/mol]"

plot 'ex3_ene' using($1) : ($5) with line linestyle 1 title "E_{pot,3}", \
      'ex4_ene' using($1) : ($5) with line linestyle 2 title "E_{pot,4}", \
      'ex5_ene' using($1) : ($5) with line linestyle 3 title "E_{pot,5}", \
