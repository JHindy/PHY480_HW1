//  file: integ_test.cpp
//
//  This is a test program for basic integration methods.               
//                                                                     
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      04-Jan-2004  original version, for 780.20 Computational Physics
//      08-Jan-2005  changed functions to pass integrand
//      09-Jan-2011  updated functions
//
//  Notes:
//   * define with floats to emphasize round-off error  
//   * compile with:  "g++ -Wall -c integ_test.cpp"
//   * adapted from: "Projects in Computational Physics" by Landau and Paez  
//             copyrighted by John Wiley and Sons, New York               
//             code copyrighted by RH Landau                           
// 
//  Answers to Questions for Homework 2:
//  1.(b) I plotted the error for both simpsons and milne rules on a log-log scale. 
//        This allows us to very easily extract the relationship between number of
//        itterations and error. All we need to do is fit these plots to lines in 
//        the regions where they are linear. After doing this I saw that the error
//        simpsons rule goes as 1/N^(-4) and milne rule goes as 1/N^(-6). At a certain
//        point the plot for milne rule is no longer linear. In this range the difference
//        between the exact answer and the estimated answer is so small that it is hard for
//        the computer to be accurate. Changing over to double precision did, however,
//        make the calculations quite a bit more accurate.
//    (c) From the graph it would appear that the optimum number of itterations for Milne
//        integration is around 150. This is because 150 is about the lowest error we can
//        get before we run into problems with machine precision. To calculate the expected
//        optimum number of itterations we would have to solve the equation 1/(N^6) = 10^(-12).
//        This is because 10^(-12) is about the machine precision and the error for Milne
//        integration scales by 1/(N^6) where N is the number of itterations. When we solve
//        this equation we get that the optimum number of itterations is around 100.
//        This is slightly lower than our observed 150 itterations
//
//************************************************************************

// include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

#include "integ_routines.h"	// prototypes for integration routines
#include <gsl/gsl_integration.h> // GSL header for integration routines
#include <gsl/gsl_math.h> // GSL header for mathematical functions

double my_integrand (double x);
double exact_integral (double x);

// Creating the function for GSL routine

struct my_f_params { double a; double b;};       

double
my_f (double x, void * p)
  {
    struct my_f_params * params = (struct my_f_params *)p;
    double a = (params->a);
    double b = (params->b);

    return  a * gsl_asinh(x) + b;
  }

// End function creation

const double ME = 2.7182818284590452354E0;	// Euler's number 

//************************************************************************

int
main ()
{
  // set up the integration specifiction
  const int intervals = 501;	// maximum number of intervals
  const double lower = 0.0;	// lower limit of integration
  const double upper = 1.0;	// upper limit of integration

  gsl_function f;
  struct my_f_params params = { 1.0, 0.0};

  f.function = &my_f;
  f.params = &params;

  const gsl_function F = f;

  //const double answer = 1. - 1. / ME;	 // the "exact" answer for the test 
  double result = 0.;  // approximate answer
  double exact = (exact_integral(upper) - exact_integral(lower));

  // open the output file stream
  ofstream integ_out ("integ.dat");	// save data in integ.dat
  integ_out << "#  N   Milne     Simpsons" << endl;
  integ_out << "#-----------------------------------------" << endl;

  // Simpson's rule requires an odd number of intervals  
  for(int i = 5; i <= intervals; i += 4) {
    integ_out << setw(4) << log(i);

    result = milne_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << log(abs((result - exact)/exact));

    result = simpsons_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << log(abs((result - exact)/exact));

    integ_out << endl;
  }
  // Begin defining outputs for GSL routine
  double result_gsl;
  double abserr_gsl;
  size_t neval_gsl;
  // End

  gsl_integration_qng (&F, lower, upper, 0.01, 0.01,
                       &result_gsl, &abserr_gsl, &neval_gsl);

  cout << "GSL result: " << scientific << result_gsl << "GSL Error: " << abserr_gsl << endl;

  cout << "data stored in integ.dat\n";
  integ_out.close ();

  return (0);
}

//************************************************************************

// the function we want to integrate 
double
my_integrand (double x)
{
  return (asinh(x));
}

double
exact_integral (double x)
{
  return ((x * asinh(x)) - sqrt(pow(x,2) + 1 ));
}
