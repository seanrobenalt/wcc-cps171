#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  cout << "CPS171 - Machine Problem 6 - Arrays & Sorting by Sean Robenalt\n\n";

  ifstream divers("m6dive.txt");

  string number_of_divers;
  getline(divers, number_of_divers);
  cout << "The number of divers is " << number_of_divers << "\n\n";

  string name_header = "NAME";
  string diff_header = "DIFF";
  string scores_header = "SORTED SCORES";
  string points_header = "POINTS \n";

  int max_name_column_length = 12;
	int scores_column_length = 24;

  cout << name_header << setw(max_name_column_length) << diff_header << " " << scores_header << setw(scores_column_length) << points_header;

  string diver_line;
  while (getline(divers, diver_line)) {

		if (diver_line != number_of_divers) {
			string diver_line_formatted = "";

			string name = diver_line.substr(0, diver_line.find('\t'));
			diver_line_formatted += name;

			diver_line.erase(0, diver_line.find('\t'));

			while(diver_line_formatted.length() < max_name_column_length) {
				diver_line_formatted += " ";
			}

		  for (int i = 0; i < diver_line.length(); i++) {
				bool is_tab = diver_line[i] == '\t';

				if (is_tab == 0 && i == 1) {
					string diff = diver_line.substr(i, i+2);
					diver_line_formatted += diff;

					diver_line.erase(i, i+2);
				}


			}

			cout << diver_line_formatted << endl;

    }
  }

  return 0;
}
