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
#include <fstream>		// file input and output                                
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class

inline double sqr (double z) {return z*z;}  // inline function for z^2
double theta (double E);

int
main (void)
{
  ofstream out;
  out.open ("gsl_spline_test_class.dat");


  const int NMAX = 9;   // maximum number of array points 
  double x_values[NMAX] = {0.0, 25.0, 50.0, 75.0, 100.0, 125.0, 150.0, 175.0, 200.0};
  double y_values[NMAX] = {9.34, 17.9, 41.5, 83.5, 51.5, 21.5, 10.8, 6.29, 4.09};

  // Test: interpolate y = sin(x^2) from xmin to xmax with npts points 
  //double xmin = 1.;
  //double xmax = 3.;
  int npts = 9;
  //double deltax = (xmax - xmin)/double(npts-1);
  //for (int i = 0; i < npts; i++)
  //{
  //  double x_temp = xmin + double(i) * deltax;   // grid of x points
  //  x_values[i] = x_temp;
  //  y_values[i] = sin (x_temp * x_temp);
  //}

  // Make the spline object
  string type = "cubic";
  Spline my_cubic_spline (x_values, y_values, npts, type);
  Spline my_poly_spline (x_values, y_values, npts, "polynomial");
  Spline my_lin_spline (x_values, y_values, npts, "linear");

  //double x;
  //cout << "Enter x: ";
  //cin >> x;    // test point 

  // Evaluate the spline and derivatives
  //double y = my_cubic_spline.y (x);
  //double y_deriv = my_cubic_spline.yp (x);
  //double y_deriv2 = my_cubic_spline.ypp (x);

  //double x_sq = sqr(x);
  out << "#E          Exact          Cubic          Polynomial          Linear" << endl;
  double E_0 = 0;

  while (E_0 <= 200)
  {
    double E_ex = theta(E_0);
    double E_cu = my_cubic_spline.y (E_0);
    double E_po = my_poly_spline.y (E_0);
    double E_li = my_lin_spline.y (E_0);

    out << E_0 << "         " << E_ex << "         " << E_cu << "          " << E_po << "          " << E_li << "          " << endl;
    E_0 = E_0 + 5; 
  }

  //cout << "    x     y_exact   y_spline" << endl;  //y'_exact  y'_spline";
  //cout << "  y''_exact  y''_spline" << endl;
  //cout << fixed << setprecision(6) 
  //     << x << "  " << theta(x) << "  " <<  y << endl;//"  "
       //<<  2.*x*cos(x_sq) << "  " << y_deriv << "  "
       //<<  -4.*x_sq* sin(x_sq) + 2.*cos(x_sq) << "  " <<  y_deriv2
       //<< endl;

  out.close ();			// close the output file

  return (0);      // successful completion 
}

double theta (double E) 
{
  double theta_0 = 63900.0;
  double E_r = 78.0;
  double gamma = 55.0;

  return (theta_0/(sqr(E-E_r) + (sqr(gamma)/4)));
}