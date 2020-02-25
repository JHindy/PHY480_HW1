//  file: area.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//
//  Notes:  
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************// 

// include files
#define _USE_MATH_DEFINES

#include <iostream>	     // this has the cout, cin definitions
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;     // if omitted, then need std::cout, std::cin 

//*********************************************************************//

const double pi = M_PI;   // define pi as a constant 

inline double square (double x){
  return x*x;
}

struct circle {
  const double pi = M_PI;
  double radius = 0;
  double area = 0;
  void change_area () {
    area = pi * square(radius);
  }
};

int
main ()
{
  ofstream out;
  out.open("area_new_data.txt");

  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;

  if (radius <= 0) {
    cout << "You entered a non-positive radii, please try again" << endl;
  } else {
  circle c;
  c.radius = radius;  
  c.change_area();

  out << "radius = " << setprecision(10) << c.radius << ",  area = " << c.area;

  out.close();
  }
  return 0;			// "0" for successful completion
}

//*********************************************************************//
