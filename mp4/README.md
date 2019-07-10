You are to design and implement a Roman numeral calculator. The subtractive Roman numeral notation commonly in use today was used only rarely during the time of the Roman Republic and Empire. For ease of calculation, the Romans most frequently used a purely additive notation in which a number was simply the sum of its digits (4 equals IIII in this notation, not IV). Each number starts with the digit of highest value and ends with the digit of smallest value. This is the notation you will use in this program.

Your program inputs two Roman numbers and an arithmetic operator and prints out the result of the operation, also as a Roman number. The values of the Roman digits are as follows:

I     1
V     5
X     10
L     50
C     100
D     500
M     1000
Thus, the number MDCCCCLXXXXVI represents 1996, because 1996 really consists of:

1000 + 500 + 100 + 100 + 100 + 100 + 50 + 10 + 10 + 10 + 10 + 5 + 1.

M      D     C     C     C     C     L    X    X    X    X    V   I

The arithmetic operators that your program should recognize in the input are +, -, \*, and /. These should perform the C++ operations of integer addition, subtraction, multiplication, and division.

One way of approaching this problem is to convert the Roman numbers into integers, then perform the required operation, and then convert the result back into a Roman number for printing.

Assume that the input numbers are in purely additive form - that is, digits are followed only by digits of the same or lower value. Also assume that the letters are all legal, no need to check for errors in the input file. Also, assume that the answer to each calculation will be a positive number.

REQUIREMENTS:  This program is to be done using functions. These functions must NOT reference global variables directly (use parameter lists). The prototypes and descriptions below are a suggested method of breaking up the problem into functions – if you prefer to design your own functions, feel free to do so, but make sure you have both value-returning and void functions in your solution.

### FUNCTION get_Data

This function receives the input file, reads one series of chars representing a Roman numeral, and sends back the value of the numeral read in. This function can call the function convert_from_Roman_to_Decimal to do the conversion while it is reading each letter.

### FUNCTION convert_from_Roman_to_Decimal
int convert_from_Roman_to_Decimal(......)
This function is to receive a char (e.g. an 'M' or a 'C' etc.) and return its corresponding integer value as an integer. Use a value-returning function. It can be called from the get_Data function.

### FUNCTION convert_from_ Decimal_ to _ Roman
string convert_from_Decimal_to_Roman(.....)
This function is to receive a integer (e.g. 13) and return its corresponding roman value as a string (e.g. XIII). Use a value-returning function.


### FUNCTION get_Oper
char get_Oper(.....)
This function receives the input file (remember that files are passed by reference such as ifstream&), reads the operator, and sends back the character read in.
### FUNCTION calc_Romans
void calc_Romans(......)
This function is given the two integers and a char (the operator) and returns the result of doing the required operation on the two integers, (using the reference 4th parameter.)

### FUNCTION print_Result
void print_Result(....)
This void function receives the integer result of the calculation, and prints it out. It does not have to return anything to the calling program.

### INPUT/OUTPUT: The input file will have number of lines. Each line will have two Roman numbers followed by an operator, separated by blanks. Include a copy of the file with your program and output.  The style of the data file looks as follows:

MCCXXVI   CV   +
MCCXXVI   MCCXXVI   /
...
etc.

Output Example:
The two lines above would produce the output:

The first number is MCCXXVI ( 1226 ).
The second number is CV ( 105 ).
The operator is +
The result is 1331 ( MCCCXXXI ).
************************************************

The first number is MCCXXVI ( 1226 ).
The second number is MCCXXVI ( 1226 ).
The operator is /

The result is 1 ( I ).
************************************************
Hint: Write this program in stages, concentrating on one function at a time. For example, write the Get_Data function and a main program to test it. Make sure that it works and can read a Roman numeral in the file correctly before working on any of the other functions.  Your main program will be quite short with lots of function calls to do all the work.

The input file (mp4romanletrdata.txt) has the following data:

MCCXXVI   CV   +
MCCXXVI  MCCXXVI   /
VI  I  -
MDCLXVI   III  *
DL DXXXXVIII   -
D  L  /
MDI   CXI   +
XXV    IIII   /
XI  CII  *
