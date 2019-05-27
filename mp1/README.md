*Skills Needed*: cin, cout, constants, arithmetic expressions, rounding, int main, meaningful variable names, spacing, indentation, documentation, output.

### Computing Basic Geometric Formulas

Write a program to compute answers to some basic geometry formulas. The program prompts the user to input a length (in centimeters) specified as a floating point value. The program then echoes the input and computes areas of squares and circles and the volume of a cube. For the squares, you will assume that the input length value is the length of a side. For the circles, this same value becomes the diameter. Use the meter value (divide the centimeters by 100) to calculate the results in square (or cubic) meters and then print the answers in square (or cubic) meters.

1. Area of a square (length times width)
2. Area of a circle (pi times radius squared)
3. How much bigger the area of the square is than the circle (see previous calculations)
4. Round the length down to the next whole number of meters, compute the volume of a cube with this value as the length of its side. (hint: Volume = length ^ 3). Make sure you round first.
5. Round the length up to the next whole number of meters, compute the volume of a cube with this value as the length of its side. Make sure you round first.

You are to run the program three times using the following input values:

1. 1000
2. 1999.9
3. 299.4

Please turn in the program and the outputs of running the program three times as directed. Be sure to use good style, appropriate comments and make use of constants in this program.

### Important Notes

For the constant PI, please use 3.14159
Use the floor() and ceil() functions to round down and up respectively. For example, ceil(3.02) is 4.
Be sure to #include <cmath> to get access to these two functions.
xx.xxx means the output must have this many decimal points, use setprecision(3) to display the result with 3 decimal precision, ...etc.
Sample Output

Your output format should look similar in style to the one below.

```
Geometry formulas by (Your name)
Enter one floating point number for length: 123.4

The number you entered is 123.4 cm or 1.234 meter.
Area of square xx.xxx sq. meter.
Area of a circle xx.xxx sq. meter.
Difference is xx.xxx sq. meter.

Cube volume rounded down is xx.xxx cu. meter.
Cube volume rounded up is xx.xxx cu. meter.
Press any key to continue
```
