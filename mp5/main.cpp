#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  cout << "CPS171 - Machine Problem 5 - Arrays by Sean Robenalt\n\n";

  // read file
  ifstream encryptfile("encryptfile.txt");

  // get keyword we will use to make the two dimensional array
  string keyword;
  getline(encryptfile, keyword);

  // print keyword, then delete duplicate chars in the keyword
  cout << "keyword is " << keyword << "\n\n";
  keyword.erase(unique(keyword.begin(), keyword.end()), keyword.end());

  // delete chars in the alphabet that are found in the keyword
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";
  for (int it = 0; it < keyword.length(); it++) {
    alphabet.erase(remove(alphabet.begin(), alphabet.end(), keyword[it]), alphabet.end());
  }

  // make the string that will be converted to the two dimensional array
  string string_for_two_dimensional_array = keyword + alphabet;

  // loop through the 25 character string_for_two_dimensional_array, makking each 5 characters its own string
  string rows[5];
  for (int row_parser = 0; row_parser < 5; row_parser++) {
    string row = string_for_two_dimensional_array.substr(0, 5);
    string_for_two_dimensional_array.erase(0, 5);

    rows[row_parser] = row;
  }

  // print first row of output
  cout << "   0 1 2 3 4" << "\n";

  // initialize two dimensional array
  char encryptkey[5][5];

  // loop through the rows array that contains 5 strings of 5 chars
  for (int i = 0; i < (sizeof(rows) / sizeof(rows[0])); i++) {

    // initialize the string that will print out this row of chars
    string row_to_print = "";
    row_to_print += to_string(i);
    row_to_print += "  ";

    // convert the char to an array
    int n = rows[i].length();
    char inner_array[n];
    strcpy(inner_array, rows[i].c_str());

    // loop through the char as an array, add it to the string to print and the two dimensional array
    for (int j = 0; j < n; j++) {
      row_to_print += inner_array[j];
      row_to_print += " ";
      encryptkey[i][j] = inner_array[j];
    }
    // print out the row
    cout << row_to_print << "\n";
  }

  // continue reading the file, and decrypting or encrypting the lines
  string line_for_encryption;
  while(getline(encryptfile, line_for_encryption)) {
    if (line_for_encryption != keyword) {

      // determine if we are decrypting or encrypting, then delete that char
      char decrypt_or_encrypt = line_for_encryption.front();
      line_for_encryption.erase(0, 2);
    }
  }

  return 0;
}
