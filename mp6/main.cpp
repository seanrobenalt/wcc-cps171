#include <iostream>
#include <fstream>
using namespace std;

int main() {
  cout << "CPS171 - Machine Problem 6 - Arrays & Sorting by Sean Robenalt\n\n";

  ifstream divers("m6dive.txt");

  string number_of_divers;
  getline(divers, number_of_divers);
  cout << "The number of divers is " << number_of_divers << "\n";

  return 0;
}
