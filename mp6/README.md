This assignment is to give you practice using one-dimensional arrays and sorting.

In competitive diving, each diver makes dives of varying degrees of difficulty. Nine judges score each dive from 0 through 10 in steps of 0.5. The difficulty is a floating-point value between 1.0 and 3.0 that represents how complex the dive is to perform. The total score is obtained by discarding the lowest and highest of the judges’ scores, adding the remaining scores, and then multiplying that total by the degree of difficulty. Write a program to score each of the dives, using the following input and output specifications, and determine the winner of the competition.

Input:

Create the following input file m6dive.txt:

7

Anna	2.0	8.0	8.5	8.5	8.5	9.0	9.0	9.0	9.5	9.5
Sarah	1.6	7.0	7.5	8.0	8.0	8.0	8.5	8.5	8.5	9.0
Deborah	2.3	9.0	9.0	9.5	10.0	10.0	9.5	9.5	9.5	9.5
Kathryn	2.4	9.0	9.0	9.0	9.5	9.5	9.5	9.0	8.0	8.5
Martha	2.7	9.0	9.0	9.5	9.5	9.0	8.5	8.5	8.5	8.5
Elizabeth	2.9	8.0	8.0	7.5	8.5	8.5	8.0	8.0	7.5	8.5
Tina	2.5	8.5	8.5	8.5	8.5	8.5	8.5	8.5	8.5	8.5

The first line contains an integer for the number of divers in the competition and subsequent lines contain:
Diver’s name (10 characters max, no blanks included), difficulty (double), and judges’ ratings (nine doubles). There is one line of data for each diver. Output:The name and difficulty, followed by the scores sorted into increasing order, in tabular form with appropriate headings along with the earned total points for that diver.Example for sample data above

NAME	DIFF	SORTED SCORES        	POINTS
Anne	2.0	8.0	8.5	8.5	8.5	9.0	9.0	9.0	9.5	9.5	124.0
Sarah	1.6	7.0	7.5	8.0	8.0	8.0	8.5	8.5	8.5	9.0	91.2

At the end of the table, print out the name of the winner of the competition (the person with the highest points) and his/her final score.Hint: Use functions to modularize your program.
