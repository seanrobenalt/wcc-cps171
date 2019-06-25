#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  // variable to store roman numeral_str base
  string base;

  // variable to store loop index as string
  string numeral_str;

  // variable to store last digit of loop index
  int end_num;

  // loop through range from 1-100
  for (int i = 1; i <= 100; i++) {

    // determine what the base of the roman numeral_str should be
    if (i >= 10 && i < 20)
      base = "X";
    else if (i >= 20 && i < 30)
      base = "XX";
    else if (i >= 30 && i < 40)
      base = "XXX";
    else if (i >= 40 && i < 50)
      base = "XL";
    else if (i >= 50 && i < 60)
      base = "L";
    else if (i >= 60 && i < 70)
      base = "LX";
    else if (i >= 70 && i < 80)
      base = "LXX";
    else if (i >= 80 && i < 90)
      base = "LXXX";
    else if (i >= 90 && i < 100)
      base = "XC";
    else if (i == 100)
      base = "C";
    else
      base = "";

    // convert loop index to string and get last digit
    numeral_str = to_string(i).back();

    // get last digit as integer
    end_num = stoi(numeral_str);

    // determine what the trailing chars of roman numeral_str should be
    switch(end_num) {
      case 0: numeral_str = ""; break;
      case 1: numeral_str = "I"; break;
      case 2: numeral_str = "II"; break;
      case 3: numeral_str = "III"; break;
      case 4: numeral_str = "IV"; break;
      case 5: numeral_str = "V"; break;
      case 6: numeral_str = "VI"; break;
      case 7: numeral_str = "VII"; break;
      case 8: numeral_str = "VIII"; break;
      case 9: numeral_str = "IX"; break;
    }

    // print the number converted to roman numeral_str
    cout << i << "." << " " << base << numeral_str << endl;
  }

  return 0;
}
