Many prestigious universities have a system called a “Legacy Preference System” which is used to decide which applicants should be accepted to the university. If an applicant’s parent is an alumnus of the university, the applicant will be admitted with lower GPA and SAT scores than if the parent is not an alumnus. (There is currently a lot of discussion about the fairness of this system, but universities get a lot of money from their alumni so they are unwilling to change it!!)

Your assignment for MP2 is to implement a computerized system like this for a very small prestigious university. The university has two schools, Liberal Arts and Music, each with their own criteria for accepting students. Your program must read in certain information about an applicant and print a message saying whether the applicant should be accepted or not.

The criteria for acceptance are:

### Liberal Arts

1. No more than 5 people can be accepted.
2. If a parent is an alumnus, the GPA must be at least 3.0, but if no parents are alumni the GPA must be at least 3.5.
3. If a parent is an alumnus, the combined SAT score must be at least 1000, but if no parents are alumni the SAT must be at least 1200.

### Music – no preferences for alumni here.

1. No more than 3 people can be accepted.
2. Math and verbal SAT’s must be at least 500.

Your program must accept as input the school the student is applying to (L or M), their high school grade point average, their math SAT score, their verbal SAT score and whether or not either parent is an alumnus (Y or N). The program must process several applicants, echoing the data for each applicant and printing a message indicating if the student was accepted to the school they were applying to. If they were not accepted, the message should indicate why. This message only has to indicate one reason for failure in cases of multiple disqualifications. Acceptances are to be made in the order received so that if a school is full, a later applicant cannot be accepted even if they happen to have better qualifications than an earlier one. You do NOT have to check for bad data coming from the file – assume that it is in the required format and has appropriate values.

The data file is arranged with the information for each applicant on a separate line. Your program must process the data until the end of file is reached, at which time the program must print out the total number of applicants and the number of acceptances to each school. The data file should be created by you. Create the file and store it in the same project folder as your program. Please turn in a hard copy of this file along with your program and output.

SUGGESTION You should design, compile, run and debug your program in stages. You might start by testing if your program can just read and echo the data file. After this is working accurately move on to identifying the school the person is applying to, then continue to add more of the details. Remember to use good style with consistent indentation, plenty of comments, good variable names etc. and don't forget to echo the data as it is read. The output must be clear and readable with appropriate string constants and spacing. Here is an example of the input data file:

L 4.0 600 650 N
M 3.9 610 520 N
L 3.8 590 600 N
…
Sample output from the first few lines of the data file follows:

```
Acceptance to College by (your name)

Applicant #: 1
School = L GPA = 4.0 math = 600 verbal = 650 alumnus = N
Applying to Liberal Arts
Accepted to Liberal Arts!!!
*******************************
Applicant #: 2
School = M GPA = 3.9 math = 610 verbal = 520 alumnus = N
Applying to Music
Accepted to Music!!
*******************************
Applicant #: 3
School = L GPA = 3.8 math = 590 verbal = 600 alumnus = N
Applying to Liberal Arts
Rejected - SAT is too low
*******************************
…
There were xx applicants in the file
There were xx acceptances to Liberal Arts
There were xx acceptances to Music
Press any key to continue
```
