# plot file for gsl_spline_test_class
set timestamp

set title 'gsl_spline_test_class'

set xlabel 'E'
set ylabel 'theta'
plot "gsl_spline_test_class.dat" using ($1):($2) title 'Exact' with linespoints, \
     "gsl_spline_test_class.dat" using ($1):($3) title 'Cubic' with linespoints, \
     "gsl_spline_test_class.dat" using ($1):($4) title 'Polynomial' with linespoints, \
     "gsl_spline_test_class.dat" using ($1):($5) title 'Linear' with linespoints
 