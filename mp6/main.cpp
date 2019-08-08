#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
  cout << "CPS171 - Machine Problem 6 - Arrays & Sorting by Sean Robenalt\n\n";

  // initialize what will keep track of highest score
  map<int, map<string, double> > winner;

  ifstream divers("m6dive.txt");

  // print first line, which is number of divers
  string number_of_divers;
  getline(divers, number_of_divers);
  cout << "The number of divers is " << number_of_divers << "\n\n";

  // set length of column headers and print
  string name_header = "NAME";
  string diff_header = "DIFF";
  string scores_header = "SORTED SCORES";
  string points_header = "POINTS \n";

  int max_name_column_length = 12;
	int scores_column_length = 34;

  cout << name_header << setw(max_name_column_length) << diff_header << " " << scores_header << setw(scores_column_length) << points_header;

  // read the lines with diver names, difficulty and scores
  string diver_line;
  while (getline(divers, diver_line)) {

		if (diver_line != number_of_divers) {
      // initialize variables to keep track of the line to print and difficulty as double
			string diver_line_formatted = "";
      double diff_as_double;

      // get name of the diver, add it to the line to print and delete name from the line
			string name = diver_line.substr(0, diver_line.find('\t'));
			diver_line_formatted += name;

			diver_line.erase(0, diver_line.find('\t'));

      // add spaces to make sure the name column fills and the difficulty is printed in alignment
			while (diver_line_formatted.length() < max_name_column_length) {
				diver_line_formatted += " ";
			}

      // get the difficulty, add it to line to print, convert it to double for later, delete it from line
		  for (int i = 0; i < diver_line.length(); i++) {
				bool is_tab = diver_line[i] == '\t';

				if (is_tab == 0 && i == 1) {
					string diff = diver_line.substr(i, i+2);
					diver_line_formatted += diff;
          diff_as_double = stod(diff);
          diver_line_formatted += "  ";

					diver_line.erase(i, i+3);
				}


			}

      // initialize array to hold all scores, and counter to keep track of number of scores
      double scores[9];
      int total_scores = 0;

      // loop through the scores, convert them to double and add to scores array, increase total_scores counter
      for (int i = 0; i < diver_line.length(); i++) {
        bool is_tab = diver_line[i] == '\t';
        double score;

        if (is_tab == 1) {

          if (diver_line[i+1] == '1') {
            score = 10.0;
          } else {
            string string_of_double = "";
            string_of_double += diver_line[i+1];
            string_of_double += ".";
            string_of_double += diver_line[i+3];

            score = stod(string_of_double);
          }

          scores[total_scores] = score;
          total_scores++;
        }
      }

      // sort the scores array by ascending value
      int length_of_scores = (sizeof(scores) / sizeof(scores[0]));

      for (int i = 0; i < length_of_scores; i++) {
        for (int j = i+1; j < length_of_scores; j++) {
          if (scores[i] > scores[j]) {
            double temp = scores[i];
				    scores[i] = scores[j];
				    scores[j] = temp;
			    }
		    }
	    }

      // remove the highest and lowest scores from the scores array
      double scores_with_low_and_high_removed[7] = {scores[1], scores[2], scores[3], scores[4], scores[5], scores[6], scores[7]};

      // initialize counter to keep track of total scores added together
      double sum = 0;

      // add score to the sum, and convert it to string to add to line to print
      for (int i = 0; i < (sizeof(scores_with_low_and_high_removed) / sizeof(scores_with_low_and_high_removed[0])); i++) {
        sum += scores_with_low_and_high_removed[i];
        string score_as_string = to_string(scores_with_low_and_high_removed[i]);
        diver_line_formatted += score_as_string.substr(0, score_as_string.find(".")+2);
        diver_line_formatted += " ";
      }

      // add spaces to make sure column fills out and the points are printed in alignment
      int header_length = name_header.length()+diff_header.length()+1+scores_header.length()+scores_column_length;

      while (diver_line_formatted.length() < header_length) {
        diver_line_formatted += " ";
      }

      // multiply difficulty by sum to get total points
      double sum_multiplied = sum*diff_as_double;

      // check the winner map if a higher score already exists, otherwise erase current winner and add new highest
      double current_highest = winner[1].begin()->second;

      if (current_highest < sum_multiplied) {
        winner.erase(1);
        winner[1][name] = sum_multiplied;
      }

      // add total points to line to print and print the line
      string sum_as_string = to_string(sum_multiplied);
      diver_line_formatted += sum_as_string.substr(0, sum_as_string.find(".")+2);
      cout << diver_line_formatted;
    }
    cout << "\n";
  }
  cout << "\n";

  // use the winner map to print the diver with the highest score
  cout << "The winner of the diving competition is " << winner[1].begin()->first << " with a score of " << winner[1].begin()->second << "\n";

  return 0;
}
