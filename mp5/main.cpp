#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ifstream encryptfile("encryptfile.txt");

  string keyword;
  getline(encryptfile, keyword);

  cout << "keyword is " << keyword << "\n\n";
  keyword.erase(unique(keyword.begin(), keyword.end()), keyword.end());

  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";
  for (int it = 0; it < keyword.length(); it++) {
    alphabet.erase(remove(alphabet.begin(), alphabet.end(), keyword[it]), alphabet.end());
  }

  string string_for_two_dimensional_array = keyword + alphabet;

  char encryptkey[5][5];

  string rows[5];

  for (int row_parser = 0; row_parser < 5; row_parser++) {
    string row = string_for_two_dimensional_array.substr(0, 5);
    string_for_two_dimensional_array.erase(0, 5);

    rows[row_parser] = row;
  }

  cout << "   0 1 2 3 4" << "\n";

  for (int i = 0; i < (sizeof(rows) / sizeof(rows[0])); i++) {
    string row_to_print = "";
    row_to_print += to_string(i);
    row_to_print += "  ";

    int n = rows[i].length();

    char inner_array[n];

    strcpy(inner_array, rows[i].c_str());

    for (int j = 0; j < n; j++) {
      row_to_print += inner_array[j];
      row_to_print += " ";
      encryptkey[i][j] = inner_array[j];
    }
    cout << row_to_print << "\n";
  }

  return 0;
}
