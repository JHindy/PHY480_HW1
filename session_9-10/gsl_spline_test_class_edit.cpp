//  file: gsl_spline_test_class.cpp
// 
//  Test program for the gsl spline routines using the Spline class
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/10/09 -- created from gsl_cubic_spline_test.cpp
//
//  Notes:
//   * uses the GSL interpolation functions (see online documentation) 
//
//*****************************************************************
// include files
#include <iostream>    // cout and cin
#include <iomanip>     // manipulators like setprecision
#include <cmath>
#include <string>     // C++ strings                                 
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class

inline double sqr (double z) {return z*z;}  // inline function for z^2
double U (double r);

int 
main (void)
{
  const int NMAX = 300;   // maximum number of array points 
  double x_values[NMAX], y_values[NMAX];

  // Test: interpolate y = sin(x^2) from xmin to xmax with npts points 
  double xmin = 1.;
  double xmax = 3.;
  int npts = 33;
  double deltax = (xmax - xmin)/double(npts-1);
  for (int i = 0; i < npts; i++)
  {
    double x_temp = xmin + double(i) * deltax;   // grid of x points
    x_values[i] = x_temp;
    y_values[i] = 2*x_temp*exp(-x_temp);
  }

  // Make the spline object
  string type = "cubic";
  Spline my_cubic_spline (x_values, y_values, npts, type);

  double r;
  cout << "Enter r: ";
  cin >> r;    // test point 

  // Evaluate the spline and derivatives
  double y = my_cubic_spline.y (r);
  //double y_deriv = my_cubic_spline.yp (r);
  //double y_deriv2 = my_cubic_spline.ypp (r);

  cout << "    x     y_exact   y_spline" << endl;
  cout << fixed << setprecision(7) 
       << r << "  " << 2*r*exp(-r) << "  " <<  y
       << endl;

  return (0);      // successful completion 
}

double U (double r)
{
  return (2*r*exp(-r));
}