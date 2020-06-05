# GradeBook-CSV-Parsing
A simple program responsible for parsing a CSV consisting of grades.
I have implemented a set of functions that can be used to retrieve information
from a grade book stored in a CSV (comma-separated values) file. The CSV file consists of 47 columns as
shown below. The first two columns are always the first name and the last name. The order of the remaining 45
columns are unknown, and they can be in any order.

• First Name and Last Name.
• L1 through L10 for 10 labs.
• B1 through B10 for 10 textbook exercises.
• Q1 through Q11 for 11 quizzes.
• P1 through P6 for 6 projects.
• E1 through E8 for 8 exams (tracing and coding are considered as two different exams).

The first row (or line) of the CSV file is the header, i.e. column names. Each following row represents a student. The
first name and the last name in each row will not be blank or contain a space. Each score under the 45 headings will
be either blank (with no score) or a real number. A blank score is considered as 0 in some calculations and is ignored
in the others

There are five simple functions implemented on the CSV:
  • double getMin(char csvfile[], char column[]); Given a CSV file, return the minimum
    score of the specified column. The blank cells are excluded from the calculation.
    
  • double getMax(char csvfile[], char column[]); Given a CSV file, return the maximum
    score of the specified column. The blank cells are excluded from the calculation.

  • double getAvg(char csvfile[], char column[]); Given a CSV file, return the average
  score of the specified column. The blank cells are excluded from the calculation.

  • int getCount(char csvfile[], char column[], double threshold); Given a CSV
  file, return the number of students with their specified score >= threshold. The blank cells are excluded from
  the calculation.

  • double getGrade(char csvfile[], char first[], char last[]); Given a CSV
    file, return the weighted average of the specified student. A blank cell is viewed as 0 in the calculation. The
    weight percentage for each column is specified below. The lowest quiz score will be dropped from the
    calculation.
    
Column Weight Percentage Score Range:
L1 through L10   1% for each lab          0-100
Q1 through Q11   1% for each quiz.        0-10
B1 through B10   1% for each exercise     0-100
P1 through P6    2% for P1
                 4% each for P2, P3
                 5% each for P4, P5, P6
                                          0-100
E1 through E6    5% for each exam         0-50
E7, E8           7.5% for each exam       0-75

Compile with:
  gcc -Wall -std=gnu99 main.c functions.c
