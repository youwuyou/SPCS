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


plot 'ex3_ene' using($1) : ($4) with line linestyle 1 title "E_{kin,3}", \
      'ex6_ene' using($1) : ($4) with line linestyle 2 title "E_{kin,6}", \

set output 'energy_pot.pdf'
set ylabel "E_{pot} [kJ/mol]"

plot 'ex3_ene' using($1) : ($5) with line linestyle 1 title "E_{pot,3}", \
      'ex6_ene' using($1) : ($5) with line linestyle 2 title "E_{pot,6}", \



set output 'energy_tot.pdf'
set ylabel "E_{tot} [kJ/mol]"

plot 'ex3_ene' using($1) : ($3) with line linestyle 1 title "E_{tot,3}", \
      'ex6_ene' using($1) : ($3) with line linestyle 2 title "E_{tot,6}", \
