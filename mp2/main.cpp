#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // read the file
  ifstream applicants("input.txt");

  // setup variable to store each line in
  string applicant;

  // counter for looping through each line
  int total_input_lines = 14;

  // setup variables to store applicant info in
  string school;
  float gpa;
  int math;
  int verbal;
  string alumnus;

  // setup counters for number/type of applicants
  int liberal_arts_students_accepted = 0;
  int music_students_accepted = 0;
  int total_actual_applicants = 0;

  cout << "Acceptance to College by Sean Robenalt" << endl << endl;

  // loop through each line of file
  for (int i = 1; i <= total_input_lines; i++) {

    // increment number of applicants by 1
    total_actual_applicants++;

    // setup variables to use for output
    string rejection_string = "Rejected - ";
    bool accept = true;

    // get a line of file, store it in applicant variable
    getline(applicants, applicant);

    // parse the line and store info
    school = applicant.front();
    gpa = strtof((applicant.substr(2, 3)).c_str(), 0);
    math = stoi(applicant.substr(6, 3));
    verbal = stoi(applicant.substr(10, 3));
    alumnus = applicant.back();

    // print out applicant info
    cout << "Applicant #: " << i << endl;
    cout << "School = " << school << " GPA = " << gpa << " math = " << math;
    cout << " verbal = " << verbal << " alumnus = " << alumnus << endl;

    // perform logic to determine whether accepted or rejected
    if (school == "L") {

      cout << "Applying to " << "Liberal Arts" << endl;

      if (liberal_arts_students_accepted >= 5) {
        rejection_string += "max number of students accepted to Liberal Arts";
        cout << rejection_string << endl << "*******************************" << endl;
        continue;
      }

      if (alumnus == "Y") {
        if (gpa < 3.0) {
          accept = false;
          rejection_string += " GPA is too low.";
        }

        if ((math + verbal) < 1000) {
          accept = false;
          rejection_string += " SAT scores are too low.";
        }
      } else {
        if (gpa < 3.5) {
          accept = false;
          rejection_string += " GPA is too low.";
        }

        if ((math + verbal) < 1200) {
          accept = false;
          rejection_string += " SAT scores are too low.";
        }
      }

      if (accept) {
        liberal_arts_students_accepted++;
        cout << "Accepted to Liberal Arts!!!" << endl << "*******************************" << endl;
      } else {
        cout << rejection_string << endl << "*******************************" << endl;
      }

      continue;

    } else {

      cout << "Applying to " << "Music" << endl;

      if (music_students_accepted >= 3) {
        rejection_string += " max number of students accepted to Music";
        cout << rejection_string << endl << "*******************************" << endl;
        continue;
      }

      if (math < 500) {
        accept = false;
        rejection_string += " SAT math score is too low.";
      }

      if (verbal < 500) {
        accept = false;
        rejection_string += " SAT verbal score is too low.";
      }

      if (accept) {
        music_students_accepted++;
        cout << "Accepted to Music!!!" << endl << "*******************************" << endl;
      } else {
        cout << rejection_string << endl << "*******************************" << endl;
      }
    }
  }

  // print out final numbers
  cout << "There were " << total_actual_applicants << " applicants in the file." << endl;
  cout << "There were " << liberal_arts_students_accepted << " acceptances to Liberal Arts." << endl;
  cout << "There were " << music_students_accepted << " acceptances to Music." << endl;

  cout << "Press any key to continue" << endl;
  cin.ignore();
  cin.get();
}
