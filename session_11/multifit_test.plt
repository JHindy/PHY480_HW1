# plot file for multifit_test
set timestamp

set title 'multifit test'

A = 5.04536
lambda = 0.10405
b = 1.01925 
f(x) = A*exp(-lambda*x)+b

set xlabel 't'
set ylabel 'y(t)'
plot "multifit_test.dat" using ($1):($2):($3) title 'data' with errorbars, \
     f(x)
 