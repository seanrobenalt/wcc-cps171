#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  // number of rows in the diamond
  int diamond_rows = 6;

  int space = diamond_rows - 1;

  // loop through diamond_rows, one more star per row
  for (int i = 0; i < diamond_rows; i++) {

    for (int j = 0; j < space; j++)
      printf("%s", " ");

    for (int j = 0; j <= i; j++)
      printf("%s%s", "*", " ");

    printf("%s", "\n");;
    space--;

  }

  space = 0;

  // loop through diamond_rows backwards, one less star per row
  for (int i = diamond_rows - 1; i > 0; i--) {

    for (int j = 0; j <= space; j++)
      printf("%s", " ");

    for (int j = 0; j < i; j++)
      printf("%s%s", "*", " ");

    printf("%s", "\n");
    space++;

  }

  cout << "Press any key to continue" << endl;
  cin.ignore();
  cin.get();
}
