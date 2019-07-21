#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int compare_chars(char a,char b) {
	if (a == b)
		return 0;
	else
		return -1;
}

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
  for (int i = 0; i < keyword.length(); i++) {
    alphabet.erase(remove(alphabet.begin(), alphabet.end(), keyword[i]), alphabet.end());
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

  // initialize maps that will store location of each char
  map<char,int> char_row_location;
  map<char, int> char_column_location;

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

      // update the row and column maps so we know the row and column of each char
      char_row_location[inner_array[j]] = i;
      char_column_location[inner_array[j]] = j;
    }
    // print out the row
    cout << row_to_print << "\n";
  }

  // continue reading the file, and decrypting or encrypting the lines
  string line_for_encryption;
  while (getline(encryptfile, line_for_encryption)) {
    if (line_for_encryption != keyword) {

      // determine if we are decrypting or encrypting, then delete that char
      char decrypt_or_encrypt = line_for_encryption.front();
      line_for_encryption.erase(0, 2);

      cout << "****************************************\n";
      cout << line_for_encryption << "\n";
      string message = "";
      string new_letter;

      if (compare_chars(decrypt_or_encrypt, 'E') == 0)
        cout << "encrypts to\n";
      else
        cout << "decrypts to\n";

      for (int i = 0; i < line_for_encryption.length(); i++) {

        bool is_space = compare_chars(line_for_encryption[i], ' ') == 0;
        bool is_dash = compare_chars(line_for_encryption[i], '-') == 0;
        bool is_apostrophe = compare_chars(line_for_encryption[i], '\'') == 0;
        bool is_encrypt = compare_chars(decrypt_or_encrypt, 'E') == 0;
        bool two_dimensional_array_contains_char = ((keyword + alphabet).find(toupper(line_for_encryption[i])) != string::npos);

        if (two_dimensional_array_contains_char) {
          if (is_space) {
            message += " ";
          } else if (is_dash) {
            message += "-";
          } else if (is_apostrophe) {
            message += '\'';
          }

          if (is_encrypt)
            line_for_encryption[i] = toupper(line_for_encryption[i]);

          if (is_space == false && is_dash == false && is_apostrophe == false) {
            int row_location = char_row_location[line_for_encryption[i]];
            int column_location = char_column_location[line_for_encryption[i]];

            if (is_encrypt)
              message += encryptkey[column_location][row_location];
            else
              message += tolower(encryptkey[column_location][row_location]);

          }

        } else {
          message += line_for_encryption[i];
        }

      }
      cout << message << "\n";
    }
  }

  return 0;
}
