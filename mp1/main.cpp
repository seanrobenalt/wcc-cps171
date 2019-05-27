#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  std::cout << std::setprecision(4);

  string square_meter_sentence_end = " sq. meter.\n";
  string cube_meter_sentence_end = " cu. meter.\n";

  cout << "Geometry formulas program by Sean Robenalt\n";

  float length_in_cm;
  cout << "\nPlease enter one floating point number for length: ";
  cin >> length_in_cm;

  // perform calculations
  float length_in_m = length_in_cm/100;
  float area_of_square = pow(length_in_m, 2);
  float radius_of_circle = length_in_m/2;
  float area_of_circle = (3.14159 * pow(radius_of_circle, 2));
  float difference_in_circle_and_square_areas = area_of_square - area_of_circle;
  int length_in_m_rounded_down = floor(length_in_m);
  int length_in_m_rounded_up = ceil(length_in_m);

  // print results
  cout << "The number you entered is " << length_in_cm << "cm or " << length_in_m << "m.\n";
  cout << "Area of a square: " << area_of_square << square_meter_sentence_end;
  cout << "Area of a circle: " << area_of_circle << square_meter_sentence_end;
  cout << "Difference is " << difference_in_circle_and_square_areas << square_meter_sentence_end;
  cout << "\nCube volume rounded down is: " << pow(length_in_m_rounded_down, 3) << cube_meter_sentence_end;
  cout << "Cube volume rounded up is: " << pow(length_in_m_rounded_up, 3) << cube_meter_sentence_end;

  // prompt user to press any key to terminate the program
  cout << "Press any key to continue\n";
  cin.ignore();
  cin.get();
}
