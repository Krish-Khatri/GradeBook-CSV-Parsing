/*
Krish Khatri
10/18/2018
The Task of this Project was to read from a CSV File and
get the minimum, maximum, average and threshold count
for each column and get the weighted grade given a student
name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This Function is Finds the Column Position in the CSV File
int columnPosition (char csvfile[], char column[])
{
  char *string, *found, line[300];
  int count = 0;
  FILE *fp;
  fp = fopen (csvfile,"r");
  string = fgets(line,300,fp);


  while (1)
  {
    found = strsep(&string,",");
    if(found == NULL)
    {
      count = 46;
      break;
    } else if(strcmp(found,column) == 0)
    {
      break;
    }
    count++;
  }

  return count;
}

// Given a csv file, return the minimum of the specified column, excluding blanks
double getMin(char csvfile[], char column[])
{
  char line[300], *found, *string;
  int  skipCount = 0, posColumn = 0, arrayLength = 0;
  double minimum = 110;
  double numbers[10000];

  FILE *fp;
  fp = fopen (csvfile,"r");
  string = fgets(line,300,fp);

  posColumn = columnPosition(csvfile,column);
  while (1)
  {
    string = fgets(line,300,fp);
    if(string == NULL) break;
    for (int i = 0; i < 47; i++)
    {
      found = strsep(&string,",");
      if(skipCount == posColumn)
      {
        if(strcmp(found,"") != 0)
        {
          numbers[arrayLength++] = atof(found);
        }
        break;
      }
      skipCount++;
    }
  skipCount = 0;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    if(numbers[i] < minimum) minimum = numbers[i];
  }

  return minimum;
}

// Given a csv file, return the maximum of the specified column, excluding blanks
double getMax(char csvfile[], char column[])
{
  char line[300], *found, *string;
  int  skipCount = 0, posColumn = 0, arrayLength = 0;
  double maximum = 0;
  double numbers[10000];

  FILE *fp;
  fp = fopen (csvfile,"r");
  string = fgets(line,300,fp);

  posColumn = columnPosition(csvfile,column);

  while (1)
  {
    string = fgets(line,300,fp);
    if(string == NULL) break;
    for (int i = 0; i < 47; i++)
    {
      found = strsep(&string,",");
      if(skipCount == posColumn)
      {
        if(strcmp(found,"") != 0)
        {
          numbers[arrayLength++] = atof(found);
        }
        break;
      }
      skipCount++;
    }
  skipCount = 0;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    if(numbers[i] > maximum) maximum = numbers[i];
  }

  return maximum;
}

// Given a csv file, return the average of the specified column, excluding blanks
double getAvg(char csvfile[], char column[])
{
  char line[300], *found, *string;
  int  skipCount = 0, posColumn = 0, arrayLength = 0;
  double sum = 0, avg = 0;
  double numbers[10000];

  FILE *fp;
  fp = fopen (csvfile,"r");
  string = fgets(line,300,fp);

  posColumn = columnPosition(csvfile,column);

  while (1)
  {
    string = fgets(line,300,fp);
    if(string == NULL) break;
    for (int i = 0; i < 47; i++)
    {
      found = strsep(&string,",");
      if(skipCount == posColumn)
      {
        if(strcmp(found,"") != 0)
        {
          numbers[arrayLength++] = atof(found);
        }
        break;
      }
      skipCount++;
    }
  skipCount = 0;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    sum += numbers[i];
  }

  avg = sum/arrayLength;
  return avg;
}

// Given a csv file, return the number of students with their column value >= threshold, excluding blanks
int getCount(char csvfile[], char column[], double threshold)
{

  char line[300], *found, *string;
  int  skipCount = 0, posColumn = 0, arrayLength = 0;
  int thresholdCounter = 0;
  double numbers[10000];

  FILE *fp;
  fp = fopen (csvfile,"r");
  string = fgets(line,300,fp);

  posColumn = columnPosition(csvfile,column);

  while (1)
  {
    string = fgets(line,300,fp);
    if(string == NULL) break;
    for (int i = 0; i < 47; i++)
    {
      found = strsep(&string,",");
      if(skipCount == posColumn)
      {
        if(strcmp(found,"") != 0)
        {
          numbers[arrayLength++] = atof(found);
        }
        break;
      }
      skipCount++;
    }
  skipCount = 0;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    if(numbers[i] >= threshold) thresholdCounter++;
  }
  return thresholdCounter;
}

// Given a csv file, return the weighted average of the specified student
// or -1.0 if there is no such student.
// A blank cell is viewed as 0
double getGrade(char csvfile[], char first[], char last[])
{
    char *string, *found, line[300];
    int rowCounter = 0, totalrows = 0, runCounter = 0,skipCount = 0;
    int arrayLength = 0;
    double average = 0;
    int Q1count = 0, Q2count = 0, Q3count = 0, Q4count = 0, Q5count = 0, Q6count = 0, Q7count = 0, Q8count = 0, Q9count = 0, Q10count = 0, Q11count = 0;
    int L1count = 0, L2count = 0, L3count = 0, L4count = 0, L5count = 0, L6count = 0, L7count = 0, L8count = 0, L9count = 0, L10count = 0;
    int B1count = 0, B2count = 0, B3count = 0, B4count = 0, B5count = 0, B6count = 0, B7count = 0, B8count = 0, B9count = 0, B10count = 0;
    int P1count = 0, P2count = 0, P3count = 0, P4count = 0, P5count = 0, P6count = 0;
    int E1count = 0, E2count = 0, E3count = 0, E4count = 0, E5count = 0, E6count = 0, E7count = 0, E8count = 0;

    FILE *fp;
    fp = fopen (csvfile,"r");

    while (1)
    {
      string = fgets(line,300,fp);
      found = strsep(&string,",");
      if(found == NULL) break;
      ++totalrows;
    }
    fclose(fp);

    // Finds Student Name in The CSV File if it exists
    FILE *fileopen2;
    fileopen2 = fopen (csvfile,"r");
    string = fgets(line,300,fileopen2);

    while (1)
    {
      string = fgets(line,300,fileopen2);
      found = strsep(&string,",");
      if(found == NULL) break;
      rowCounter++;

      if(strcasecmp(found,first) == 0)
      {
        found = strsep(&string,",");
        if(strcasecmp(found,last) == 0)
        {
          runCounter++;
          break;
        }
      }
    }

    if(runCounter == 0)
    {
      return -1.0;
    }

    double Q1[totalrows], Q2[totalrows], Q3[totalrows], Q4[totalrows], Q5[totalrows], Q6[totalrows], Q7[totalrows], Q8[totalrows],
    Q9[totalrows], Q10[totalrows], Q11[totalrows];


    double L1[totalrows], L2[totalrows], L3[totalrows], L4[totalrows], L5[totalrows], L6[totalrows], L7[totalrows], L8[totalrows],
    L9[totalrows], L10[totalrows];

    double B1[totalrows], B2[totalrows], B3[totalrows], B4[totalrows], B5[totalrows], B6[totalrows], B7[totalrows], B8[totalrows],
    B9[totalrows], B10[totalrows];

    double P1[totalrows], P2[totalrows], P3[totalrows], P4[totalrows], P5[totalrows], P6[totalrows];

    double E1[totalrows], E2[totalrows], E3[totalrows], E4[totalrows], E5[totalrows], E6[totalrows], E7[totalrows], E8[totalrows];


    // Gets The Position of All Quiz columns
    Q1count = columnPosition(csvfile,"Q1");
    Q2count = columnPosition(csvfile,"Q2");
    Q3count = columnPosition(csvfile,"Q3");
    Q4count = columnPosition(csvfile,"Q4");
    Q5count = columnPosition(csvfile,"Q5");
    Q6count = columnPosition(csvfile,"Q6");
    Q7count = columnPosition(csvfile,"Q7");
    Q8count = columnPosition(csvfile,"Q8");
    Q9count = columnPosition(csvfile,"Q9");
    Q10count = columnPosition(csvfile,"Q10");
    Q11count = columnPosition(csvfile,"Q11");

    // Stores Q1 column in Q1 Array
    FILE *fq1;
    fq1 = fopen (csvfile,"r");
    string = fgets(line,300,fq1);

    while (1)
    {
      string = fgets(line,300,fq1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q1count)
        {
          Q1[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq1);

    // Stores Q2 column in Q2 Array
    FILE *fq2;
    fq2 = fopen (csvfile,"r");
    string = fgets(line,300,fq2);

    while (1)
    {
      string = fgets(line,300,fq2);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q2count)
        {
          Q2[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq2);

    // Stores Q3 column in Q3 Array
    FILE *fq3;
    fq3 = fopen (csvfile,"r");
    string = fgets(line,300,fq3);

    while (1)
    {
      string = fgets(line,300,fq3);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q3count)
        {
          Q3[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq3);

    // Stores Q4 column in Q4 Array
    FILE *fq4;
    fq4 = fopen (csvfile,"r");
    string = fgets(line,300,fq4);

    while (1)
    {
      string = fgets(line,300,fq4);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q4count)
        {
          Q4[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq4);

    // Stores Q5 column in Q5 Array
    FILE *fq5;
    fq5 = fopen (csvfile,"r");
    string = fgets(line,300,fq5);

    while (1)
    {
      string = fgets(line,300,fq5);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q5count)
        {
          Q5[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq5);

    // Stores Q6 column in Q6 Array
    FILE *fq6;
    fq6 = fopen (csvfile,"r");
    string = fgets(line,300,fq6);

    while (1)
    {
      string = fgets(line,300,fq6);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q6count)
        {
          Q6[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq6);

    // Stores Q7 in Q7 Array
    FILE *fq7;
    fq7 = fopen (csvfile,"r");
    string = fgets(line,300,fq7);

    while (1)
    {
      string = fgets(line,300,fq7);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q7count)
        {
          Q7[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq7);

    //Stores Q8 to Q8 Array
    FILE *fq8;
    fq8 = fopen (csvfile,"r");
    string = fgets(line,300,fq8);

    while (1)
    {
      string = fgets(line,300,fq8);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q8count)
        {
          Q8[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq8);

    //Stores Q9 in Q9 Array
    FILE *fq9;
    fq9 = fopen (csvfile,"r");
    string = fgets(line,300,fq9);

    while (1)
    {
      string = fgets(line,300,fq9);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q9count)
        {
          Q9[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq9);

    //Stores Q10 in Q10 Array
    FILE *fq10;
    fq10 = fopen (csvfile,"r");
    string = fgets(line,300,fq10);

    while (1)
    {
      string = fgets(line,300,fq10);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q10count)
        {
          Q10[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq10);

    //Stores Q11 in Q11 Array
    FILE *fq11;
    fq11 = fopen (csvfile,"r");
    string = fgets(line,300,fq11);

    while (1)
    {
      string = fgets(line,300,fq11);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == Q11count)
        {
          Q11[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fq11);

    // Gets the Position of All Lab columns
    L1count = columnPosition(csvfile,"L1");
    L2count = columnPosition(csvfile,"L2");
    L3count = columnPosition(csvfile,"L3");
    L4count = columnPosition(csvfile,"L4");
    L5count = columnPosition(csvfile,"L5");
    L6count = columnPosition(csvfile,"L6");
    L7count = columnPosition(csvfile,"L7");
    L8count = columnPosition(csvfile,"L8");
    L9count = columnPosition(csvfile,"L9");
    L10count = columnPosition(csvfile,"L10");

    // Stores Lab 1 in L1 Array
    FILE *fL1;
    fL1 = fopen (csvfile,"r");
    string = fgets(line,300,fL1);

    while (1)
    {
      string = fgets(line,300,fL1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L1count)
        {
          L1[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL1);

    // Stores Lab 2 in L2 Array
    FILE *fL2;
    fL2 = fopen (csvfile,"r");
    string = fgets(line,300,fL2);

    while (1)
    {
      string = fgets(line,300,fL2);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L2count)
        {
          L2[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL2);

    // Stores Lab 3 in L3 Array
    FILE *fL3;
    fL3 = fopen (csvfile,"r");
    string = fgets(line,300,fL3);

    while (1)
    {
      string = fgets(line,300,fL3);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L3count)
        {
          L3[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL3);

    // Stores Lab 4 in L4 Array
    FILE *fL4;
    fL4 = fopen (csvfile,"r");
    string = fgets(line,300,fL4);

    while (1)
    {
      string = fgets(line,300,fL4);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L4count)
        {
          L4[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL4);

    // Stores Lab 5 in L5 Array
    FILE *fL5;
    fL5 = fopen (csvfile,"r");
    string = fgets(line,300,fL5);

    while (1)
    {
      string = fgets(line,300,fL5);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L5count)
        {
          L5[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL5);

    // Stores Lab 6 in L6 Array
    FILE *fL6;
    fL6 = fopen (csvfile,"r");
    string = fgets(line,300,fL6);

    while (1)
    {
      string = fgets(line,300,fL6);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L6count)
        {
          L6[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL6);

    // Stores Lab 7 in L7 Array
    FILE *fL7;
    fL7 = fopen (csvfile,"r");
    string = fgets(line,300,fL7);

    while (1)
    {
      string = fgets(line,300,fL7);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L7count)
        {
          L7[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL7);

    // Stores Lab 8 in L8 Array
    FILE *fL8;
    fL8 = fopen (csvfile,"r");
    string = fgets(line,300,fL8);

    while (1)
    {
      string = fgets(line,300,fL8);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L8count)
        {
          L8[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL8);

    // Stores Lab 9 in L9 Array
    FILE *fL9;
    fL9 = fopen (csvfile,"r");
    string = fgets(line,300,fL9);

    while (1)
    {
      string = fgets(line,300,fL9);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L9count)
        {
          L9[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL9);

    // Stores Lab 10 in L10 Array
    FILE *fL10;
    fL10 = fopen (csvfile,"r");
    string = fgets(line,300,fL10);

    while (1)
    {
      string = fgets(line,300,fL10);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == L10count)
        {
          L10[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fL10);

    // Gets the Position of All Books Exercise columns
    B1count = columnPosition(csvfile,"B1");
    B2count = columnPosition(csvfile,"B2");
    B3count = columnPosition(csvfile,"B3");
    B4count = columnPosition(csvfile,"B4");
    B5count = columnPosition(csvfile,"B5");
    B6count = columnPosition(csvfile,"B6");
    B7count = columnPosition(csvfile,"B7");
    B8count = columnPosition(csvfile,"B8");
    B9count = columnPosition(csvfile,"B9");
    B10count = columnPosition(csvfile,"B10");

    // Stores Book 1 Grade Into Book 1 Array
    FILE *fB1;
    fB1 = fopen (csvfile,"r");
    string = fgets(line,300,fB1);

    while (1)
    {
      string = fgets(line,300,fB1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B1count)
        {
          B1[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB1);

    //Stores Book 2 Grade into Book 2 Array
    FILE *fB2;
    fB2 = fopen (csvfile,"r");
    string = fgets(line,300,fB2);

    while (1)
    {
      string = fgets(line,300,fB2);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B2count)
        {
          B2[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB2);

    // Stores Book 3 grade into book 3 array
    FILE *fB3;
    fB3 = fopen (csvfile,"r");
    string = fgets(line,300,fB3);

    while (1)
    {
      string = fgets(line,300,fB3);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B3count)
        {
          B3[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB3);

    // Stores Book 4 grade into book 4 array
    FILE *fB4;
    fB4 = fopen (csvfile,"r");
    string = fgets(line,300,fB4);

    while (1)
    {
      string = fgets(line,300,fB4);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B4count)
        {
          B4[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB4);

    // Stores Book 5 grade into Book 5 array
    FILE *fB5;
    fB5 = fopen (csvfile,"r");
    string = fgets(line,300,fB5);

    while (1)
    {
      string = fgets(line,300,fB5);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B5count)
        {
          B5[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB5);

    // Stores Book 6 grade into Book 6 array
    FILE *fB6;
    fB6 = fopen (csvfile,"r");
    string = fgets(line,300,fB6);

    while (1)
    {
      string = fgets(line,300,fB6);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B6count)
        {
          B6[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB6);

    // Stores Book 7 grade into Book 7 array
    FILE *fB7;
    fB7 = fopen (csvfile,"r");
    string = fgets(line,300,fB7);

    while (1)
    {
      string = fgets(line,300,fB7);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B7count)
        {
          B7[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB7);

    // Stores Book 8 grade into Book 8 array
    FILE *fB8;
    fB8 = fopen (csvfile,"r");
    string = fgets(line,300,fB8);

    while (1)
    {
      string = fgets(line,300,fB8);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B8count)
        {
          B8[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB8);

    // Stores Book 9 grade into Book 9 array
    FILE *fB9;
    fB9 = fopen (csvfile,"r");
    string = fgets(line,300,fB9);

    while (1)
    {
      string = fgets(line,300,fB9);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B9count)
        {
          B9[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB9);

    // Stores Book 10 grade into Book 10 Array
    FILE *fB10;
    fB10 = fopen (csvfile,"r");
    string = fgets(line,300,fB10);

    while (1)
    {
      string = fgets(line,300,fB10);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == B10count)
        {
          B10[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fB10);

    // Find the Location of All Project columns
    P1count = columnPosition(csvfile,"P1");
    P2count = columnPosition(csvfile,"P2");
    P3count = columnPosition(csvfile,"P3");
    P4count = columnPosition(csvfile,"P4");
    P5count = columnPosition(csvfile,"P5");
    P6count = columnPosition(csvfile,"P6");

    // Stores Project 1 grade into Project 1 Array
    FILE *fP1;
    fP1 = fopen (csvfile,"r");
    string = fgets(line,300,fP1);

    while (1)
    {
      string = fgets(line,300,fP1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P1count)
        {
          P1[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP1);

    // Stores Project 2 grade into Project 2 Array
    FILE *fP2;
    fP2 = fopen (csvfile,"r");
    string = fgets(line,300,fP2);

    while (1)
    {
      string = fgets(line,300,fP2);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P2count)
        {
          P2[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP2);

    // Stores Project 3 grade into Project 3 Array
    FILE *fP3;
    fP3 = fopen (csvfile,"r");
    string = fgets(line,300,fP3);

    while (1)
    {
      string = fgets(line,300,fP3);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P3count)
        {
          P3[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP3);

    // Stores Project 4 grade into Project 4 Array
    FILE *fP4;
    fP4 = fopen (csvfile,"r");
    string = fgets(line,300,fP4);

    while (1)
    {
      string = fgets(line,300,fP4);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P4count)
        {
          P4[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP4);

    // Stores Project 5 grade into Project 5 Array
    FILE *fP5;
    fP5 = fopen (csvfile,"r");
    string = fgets(line,300,fP5);

    while (1)
    {
      string = fgets(line,300,fP5);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P5count)
        {
          P5[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP5);

    // Stores Project 6 grade into Project 6 Array
    FILE *fP6;
    fP6 = fopen (csvfile,"r");
    string = fgets(line,300,fP6);

    while (1)
    {
      string = fgets(line,300,fP6);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == P6count)
        {
          P6[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fP6);

    // Finds the Location of Exam columns in CSV File
    E1count = columnPosition(csvfile,"E1");
    E2count = columnPosition(csvfile,"E2");
    E3count = columnPosition(csvfile,"E3");
    E4count = columnPosition(csvfile,"E4");
    E5count = columnPosition(csvfile,"E5");
    E6count = columnPosition(csvfile,"E6");
    E7count = columnPosition(csvfile,"E7");
    E8count = columnPosition(csvfile,"E8");

    // Stores Exam 1 column into Exam 1 Array
    FILE *fE1;
    fE1 = fopen (csvfile,"r");
    string = fgets(line,300,fE1);

    while (1)
    {
      string = fgets(line,300,fE1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E1count)
        {
          E1[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE1);

    // Stores Exam 2 column into Exam 2 array
    FILE *fE2;
    fE2 = fopen (csvfile,"r");
    string = fgets(line,300,fE2);

    while (1)
    {
      string = fgets(line,300,fE2);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E2count)
        {
          E2[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE2);

    // Stores Exam 3 column into Exam 3 array
    FILE *fE3;
    fE3 = fopen (csvfile,"r");
    string = fgets(line,300,fE3);

    while (1)
    {
      string = fgets(line,300,fE3);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E3count)
        {
          E3[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE3);

    // Stores Exam 4 column into Exam 4 array
    FILE *fE4;
    fE4 = fopen (csvfile,"r");
    string = fgets(line,300,fE4);

    while (1)
    {
      string = fgets(line,300,fE4);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E4count)
        {
          E4[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE4);

    // Stores Exam 5 column into Exam 5 array
    FILE *fE5;
    fE5 = fopen (csvfile,"r");
    string = fgets(line,300,fE5);

    while (1)
    {
      string = fgets(line,300,fE5);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E5count)
        {
          E5[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE5);

    // Stores Exam 6 column nto Exam 6 array
    FILE *fE6;
    fE6 = fopen (csvfile,"r");
    string = fgets(line,300,fE6);

    while (1)
    {
      string = fgets(line,300,fE1);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E6count)
        {
          E6[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE6);

    // Stores Exam 7 column into Exam 7 array
    FILE *fE7;
    fE7 = fopen (csvfile,"r");
    string = fgets(line,300,fE7);

    while (1)
    {
      string = fgets(line,300,fE7);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E7count)
        {
          E7[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE7);

    // Stores Exam 8 Column into Exam 8 array
    FILE *fE8;
    fE8 = fopen (csvfile,"r");
    string = fgets(line,300,fE8);

    while (1)
    {
      string = fgets(line,300,fE8);
      if(string == NULL) break;
      for (int i = 0; i < 47; i++)
      {
        found = strsep(&string,",");
        if(skipCount == E8count)
        {
          E8[arrayLength++] = atof(found);
          break;
        }
        skipCount++;
      }
    skipCount = 0;
    }
    arrayLength = 0;
    fclose(fE8);

    double quizGrades[11] = {Q1[rowCounter-1], Q2[rowCounter-1], Q3[rowCounter-1], Q4[rowCounter-1],
    Q5[rowCounter-1], Q6[rowCounter-1], Q7[rowCounter-1],
    Q8[rowCounter-1],Q9[rowCounter-1],Q10[rowCounter-1],Q11[rowCounter-1]};

    for (int i = 0; i < 11; i++)
	   {
		   for (int k = 0; k < 11; k++)
		    {
			    if (quizGrades[k] > quizGrades[i])
			    {
				    double tmp = quizGrades[i];
				    quizGrades[i] = quizGrades[k];
				    quizGrades[k] = tmp;
			    }
		    }
	   }

     double quizAvg = 0;
     for(int i = 1; i < 11; i++)
     {
       quizAvg += quizGrades[i];
     }
     quizAvg = (quizAvg * 10) * .01;

     double labGrades[10] = {L1[rowCounter-1], L2[rowCounter-1], L3[rowCounter-1], L4[rowCounter-1],
     L5[rowCounter-1], L6[rowCounter-1], L7[rowCounter-1],
     L8[rowCounter-1],L9[rowCounter-1],L10[rowCounter-1]};

     double labAvg = 0;
     for(int i = 0; i < 10; i++)
     {
       labAvg += labGrades[i];
     }
     labAvg = labAvg * .01;

     double bookGrades[10] = {B1[rowCounter-1], B2[rowCounter-1], B3[rowCounter-1], B4[rowCounter-1],
     B5[rowCounter-1], B6[rowCounter-1], B7[rowCounter-1],
     B8[rowCounter-1],B9[rowCounter-1],B10[rowCounter-1]};

     double bookAvg = 0;
     for(int i = 0; i < 10; i++)
     {
       bookAvg += bookGrades[i];
     }
     bookAvg = bookAvg * .01;

     double projectAvg = (.02*P1[rowCounter-1]) + ((P2[rowCounter-1] + P3[rowCounter-1]) * .04) + ((P4[rowCounter-1] + P5[rowCounter-1] + P6[rowCounter-1]) * .05);

     double examAvg = (((E1[rowCounter-1] + E2[rowCounter-1] + E3[rowCounter-1] + E4[rowCounter-1] + E5[rowCounter-1] + E6[rowCounter-1]) * 0.05) * 2) + (((E7[rowCounter-1] + E8[rowCounter-1]) * 4/3 ) * .075);

     // Calulations for grade
     average = labAvg + bookAvg + projectAvg + quizAvg + examAvg;

  return average;
}
