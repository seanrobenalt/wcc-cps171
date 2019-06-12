#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream applicants("input.txt");

  string applicant;
  int total_expected_applicants = 14;

  string school;
  float gpa;
  int math;
  int verbal;
  string alumnus;

  int liberal_arts_students_accepted = 0;
  int music_students_accepted = 0;
  int total_actual_applicants = 0;

  for (int i = 1; i <= total_expected_applicants; i++) {
    total_actual_applicants += 1;

    string rejection_string = "Rejected - ";
    bool accept = true;

    getline(applicants, applicant);

    school = applicant.front();
    gpa = strtof((applicant.substr(2, 3)).c_str(), 0);
    math = stoi(applicant.substr(6, 3));
    verbal = stoi(applicant.substr(10, 3));
    alumnus = applicant.back();

    cout << "Applicant #: " << i << endl;
    cout << "School = " << school << " GPA = " << gpa << " math = " << math;
    cout << " verbal = " << verbal << " alumnus = " << alumnus << endl;

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

  cout << "There were " << total_actual_applicants << " applicants in the file." << endl;
  cout << "There were " << liberal_arts_students_accepted << " acceptances to Liberal Arts." << endl;
  cout << "There were " << music_students_accepted << " acceptances to Music." << endl;

  cout << "Press any key to continue" << endl;
  cin.ignore();
  cin.get();
}
