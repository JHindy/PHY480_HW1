# plot file for diffeq_test_exp_back
set timestamp

set xlabel 't'
set ylabel 'y(t)'

set title 'Comparing Differential Equation Algorithms'


plot \
  "diffeq_test_3.dat" using ($1):(abs(($2)-($3))/(abs($2)+abs($3))) title 'rel error'
