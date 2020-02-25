//************************************************************************ 
//  file: order_of_summation1.cpp
// 
//  Program to demonstrate that the order of summation of even positive
//   numbers matters
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      01/02/11  new version from demo1.cpp
//
//  Notes:
//   * An example to try to understand summing upward vs. summing
//      downward.  Add a small number eps (slightly below single-precision
//      machine precision) many times to 1.  It makes a big difference
//      (in single precision) whether you do 1 + eps + eps + ... or
//      eps + eps + ... + 1.
//
//
//   * First pass: no subroutine
//   * Use single precision AND double precision at the same time
//   * Here is the output with eps=5e-8 added 10^7 time:
//
//                           1+eps+eps+...   eps+eps+...+1
//        single precision:  1.0000000000    1.5323836803
//        double precision:  1.4999999992    1.4999999999
//
//  Discussion for Homework
//
//  Since the difference between the two is clearly not constant, one must be doing a more accurate calculation than the other. 
//  On the log plot it appears that between 15.5 and 16 on the x-axis is a power law. The slope here is 1.
//  At large values of N the error between the two appears to come to a power law relation as opposed to the sporadic nature at low N.
//  The downward sum will be more precise because it starts at lower numbers, thus it is more able to add lots of small numbers accurately which is necessary at high N.
//
//*************************************************************************


// include files
#include <iostream>		// note that .h is omitted
#include <iomanip>		// note that .h is omitted
#include <fstream>   
#include <math.h>
using namespace std;		// we need this when .h is omitted

//********************** begin main ******************************
// Function to sum up for set N
float sum_up (float N) {
  float sum = 0;

  for (float i = 1; i <= N; i++)
  {
    sum += 1/i;
  }

  return sum;
}

// Function to sum down for set N
float sum_down (float N) {
  float sum = 1/N;

  for (float i = 1; i < N; i++)
  {
    sum += 1/(N-i);
  }

  return sum;
}

int
main ()
{
  ofstream out ("order_of_summation1.dat");

  float N = 10000000;	// number of times to add 1/n

  float sum_up_sp = 0;	// sum of 1/n starting at 1
  float sum_down_sp = 0;	// sum of 1/n starting at N 

  cout << "Summing 1/n" << endl;

  out << "N                   Sum Up                   Sum Down                 Difference Divided by Average" << endl;
  for(float i = 1; i < N; i += 100000) 
  {
    sum_up_sp = sum_up(i);
    sum_down_sp = sum_down(i);
    float diff_div_avg = (abs(sum_up_sp - sum_down_sp)/((1./2.)*(abs(sum_up_sp) + abs(sum_down_sp))));
    out << fixed << setprecision (16);
    out << i << "               " << sum_up_sp << "               " << sum_down_sp << "               " << diff_div_avg << endl;

  }
  out.close();
  return (0);
}

