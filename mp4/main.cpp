#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int convert_from_roman_to_int(char roman_numeral) {

  switch(roman_numeral) {
    case 'I' : return 1;
    case 'V' : return 5;
    case 'X' : return 10;
    case 'L' : return 50;
    case 'C' : return 100;
    case 'D' : return 500;
    case 'M' : return 1000;
    default : return 0;
  }
}

int perform_calculation(int a, int b, char oper) {

  switch(oper) {
    case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '/' : return a/b;
    default : return 0;
  }
}

int print_number(string number_as_string, string first_or_second) {
  int number_as_int = 0;
  string num_to_print;

  if (first_or_second == "second") {
    // remove the operator from the string if it's second string
    num_to_print = number_as_string.erase(number_as_string.length()-3);
  } else {
    num_to_print = number_as_string;
  }

  for (int i = 0 ; i < number_as_string.length(); i++)
    // get each char converted to the proper int and add it to the total
    number_as_int += convert_from_roman_to_int(number_as_string[i]);

    cout << "The " << first_or_second << " number is " << num_to_print << " ( " << number_as_int << " ). " << "\n";

  return number_as_int;
}

string convert_from_int_to_roman(int num_to_convert) {
  string return_value = "";

  int divide_by_thousand = num_to_convert/1000;

  if (divide_by_thousand > 0) {
    while(divide_by_thousand) {
      return_value += 'M';
      divide_by_thousand--;
    }
  }

  int remainder = num_to_convert%1000;

  int divide_by_five_hundred = remainder/500;

  if (divide_by_five_hundred > 0) {
    while(divide_by_five_hundred) {
      return_value += 'D';
      divide_by_five_hundred--;
    }
  }

  remainder = num_to_convert%500;

  int divide_by_hundred = remainder/100;

  if (divide_by_hundred > 0) {
    while(divide_by_hundred) {
      return_value += 'C';
      divide_by_hundred--;
    }
  }

  remainder = num_to_convert%100;

  int divide_by_fifty = remainder/50;

  if (divide_by_fifty > 0) {
    while(divide_by_fifty) {
      return_value += 'L';
      divide_by_fifty--;
    }
  }

  remainder = num_to_convert%50;

  int divide_by_ten = remainder/10;

  if (divide_by_ten > 0) {
    while(divide_by_ten) {
      return_value += 'X';
      divide_by_ten--;
    }
  }

  remainder = num_to_convert%10;

  int divide_by_five = remainder/5;

  if (divide_by_five > 0) {
    while(divide_by_five) {
      return_value += 'V';
      divide_by_five--;
    }
  }

  remainder = num_to_convert%5;

  int divide_by_one = remainder/1;

  if (divide_by_one > 0) {
    while(divide_by_one) {
      return_value += 'I';
      divide_by_one--;
    }
  }

  return return_value;
}

void print_operator(char operator_to_print) {
  cout << "The operator is " << operator_to_print << "\n";
}

void print_final_result(int int_result, string roman_result) {
  cout << "The result is " << int_result << " ( " << roman_result << " ). " << "\n";
}

void process_file(ifstream& input_file) {
  string line;

  string first_number;
  int first_number_as_int = 0;

  string second_number;
  int second_number_as_int = 0;

  string result_as_roman;
  int result_as_int;

  while(getline(input_file, line)) {
    char oper = line.back();

    // parse the input file by splitting the two numbers by whitespace
    first_number = line.substr(0, line.find(" "));
    second_number = line.substr(line.find(" ")).substr(2);

    // print_number takes care of printing the initial number and converting it to int
    first_number_as_int = print_number(first_number, "first");
    second_number_as_int = print_number(second_number, "second");

    // this prints the operator
    print_operator(oper);

    // this method performs the calculation of the two roman numerals
    result_as_int = perform_calculation(first_number_as_int, second_number_as_int, oper);

    // this method converts the int calculated to a roman numeral
    result_as_roman = convert_from_int_to_roman(result_as_int);

    // this prints the final result as int and roman numeral
    print_final_result(result_as_int, result_as_roman);
  }
}

int main() {
  cout << "Roman Numeral Calculator by Sean Robenalt" << "\n" << "\n";

  ifstream roman_numeral_file("mp4romanletrdata.txt");

  process_file(roman_numeral_file);
  return 0;
}
