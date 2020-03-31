#  file: eigen_basis.plt 
#
#  Gnuplot plot file for eigen_basis.cpp output
#  
#  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
# 
#  Revision history
#   2004-01-24  original version for 780.20 session 5
#   2004-01-16  added postscript enhanced and comments for session 4
#

# record the time and date the graph was generated
set timestamp

# titles and labels
set title 'Test of eigen basis'
set xlabel 'r'
set ylabel 'u(r)'

# move the legend to a free space
set key left

# set the terminal type to be the screen (which is x11 here)
set term x11

# plot the data as well as the fit, with appropriate titles 
plot "eigen_basis_11.dat" using ($1):($2) title 'b = 1, basis = 1', \
     "eigen_basis_110.dat" using ($1):($2) title 'b = 10, basis = 1', \
     "eigen_basis_51.dat" using ($1):($2) title 'b = 1, basis = 5', \
     "eigen_basis_510.dat" using ($1):($2) title 'b = 10, basis = 5', \
     "eigen_basis_101.dat" using ($1):($2) title 'b = 1, basis = 10', \
     "eigen_basis_1010.dat" using ($1):($2) title 'b = 10, basis = 10', \
     "eigen_basis_201.dat" using ($1):($2) title 'b = 1, basis = 20' , \
     "eigen_basis_2010.dat" using ($1):($2) title 'b = 10, basis = 20'


# output the plot to the file derivative_test_plt.ps   
set out "eigen_Basis_plt.ps"
set term postscript color enhanced
replot
