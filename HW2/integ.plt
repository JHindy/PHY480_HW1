# plot file for diffeq_test_exp_back
set timestamp

set xlabel 'N'
set ylabel 'Error'

set title 'Comparing Integration Algorithms'

f(x) = a*x + b
fit [2:6] f(x) "integ.dat" using ($1):($3) via a,b

g(x) = c*x + d
fit [2:5] g(x) "integ.dat" using ($1):($2) via c,d


plot "integ.dat" using ($1):($2) title 'Milne Rule', \
     "integ.dat" using ($1):($3) title 'Simpsons Rule', \
     a*x + b title 'Simpsons Fit', \
     c*x + d title 'Milne Fit   
