set autoscale
set xtic auto
set ytic auto
set ztic auto

set terminal pdf

set output 'coords_init.pdf'
set xrange [0:10]
set yrange [0:10]
set zrange [0:10]

set xlabel "x"
set ylabel "y"
set zlabel "z"

set key off

splot 'coords.final' using($2) : ($3) : ($4) pt 7 ps .5 lc rgb "#0000FF"
