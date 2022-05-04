set autoscale
set xtic auto
set ytic auto

set terminal pdf
set output 'gr4.pdf'

set ylabel "g(r)"
set xlabel "r"

set style line 1 lc rgb "#000000" lw 2

plot 'gr' using($1) : ($2) notitle with line linestyle 1 \
