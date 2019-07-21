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

  // initialize the string that will be converted to the two dimensional array
  string string_for_two_dimensional_array = keyword + alphabet;

  // loop through the above string, making each 5 characters its own string, which will be a row
  string rows[5];
  for (int row_parser = 0; row_parser < 5; row_parser++) {
    string row = string_for_two_dimensional_array.substr(0, 5);
    string_for_two_dimensional_array.erase(0, 5);

    rows[row_parser] = row;
  }

  // print first row of table
  cout << "   0 1 2 3 4" << "\n";

  // initialize two dimensional array
  char encryptkey_table[5][5];

  // initialize maps that will store location of each char for decrypting/encrypting later on
  map<char,int> char_row_location;
  map<char, int> char_column_location;

  // loop through the rows array that contains 5 strings of 5 chars
  for (int i = 0; i < (sizeof(rows) / sizeof(rows[0])); i++) {

    // initialize the string that will print out this row of chars
    string row_to_print = "";
    row_to_print += to_string(i);
    row_to_print += "  ";

    // convert the 5 character string to an array
    int n = rows[i].length();
    char row_as_array[n];
    strcpy(row_as_array, rows[i].c_str());

    // loop through the 5 character string as an array, add it to the string to print and the two dimensional array
    for (int j = 0; j < n; j++) {
      row_to_print += row_as_array[j];
      row_to_print += " ";

			encryptkey_table[i][j] = row_as_array[j];

      // update the row and column maps so we know the row and column of each char
      char_row_location[row_as_array[j]] = i;
      char_column_location[row_as_array[j]] = j;
    }
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

			// initialize the string that will print the encrypted/decrypted message
			string message = "";

			bool is_encrypt = compare_chars(decrypt_or_encrypt, 'E') == 0;

      if (is_encrypt)
        cout << "encrypts to\n";
      else
        cout << "decrypts to\n";

      for (int i = 0; i < line_for_encryption.length(); i++) {

        bool is_space = compare_chars(line_for_encryption[i], ' ') == 0;
        bool is_dash = compare_chars(line_for_encryption[i], '-') == 0;
        bool is_apostrophe = compare_chars(line_for_encryption[i], '\'') == 0;
        bool encryptkey_table_contains_char = ((keyword + alphabet).find(toupper(line_for_encryption[i])) != string::npos);

				// only encrypt/decrypt the char if it's in the encryptkey_table
        if (encryptkey_table_contains_char) {

					// leave spaces, dashes and apostrophes as is
					if (is_space) {
            message += " ";
          } else if (is_dash) {
            message += "-";
          } else if (is_apostrophe) {
            message += '\'';
          }

					// convert char to upper if we are encrypting
          if (is_encrypt)
            line_for_encryption[i] = toupper(line_for_encryption[i]);

					// if char is not a space, dash or apostrophe then use the maps we made to find the row & column of the char
          if (is_space == false && is_dash == false && is_apostrophe == false) {
            int row_location = char_row_location[line_for_encryption[i]];
            int column_location = char_column_location[line_for_encryption[i]];

						// add to the message in upper case if we are encrypting, convert to lower for decrypting
            if (is_encrypt)
              message += encryptkey_table[column_location][row_location];
            else
              message += tolower(encryptkey_table[column_location][row_location]);

          }

        } else {
					// if char not found in encryptkey_table, add it as is to the encrypted/decrypted message
          message += line_for_encryption[i];
        }

      }
      cout << message << "\n";
    }
  }

  return 0;
}
