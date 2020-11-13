/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. apilasze@purdue.edu
*  3. imesser@purdue.edu (delete line if no third partner)
*
*  Lab #: lab11
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC 289
*
*  Program Description: This program finds and calculates a whole average number given the data
*  set from the user.
*
***************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//Global Constants
#define SIZE 20

//Global Function Declarations
int getInput(int[]);
int getDigit(int[], int);
void getDataSet(int[],int);
void getAverage(int[],int, int);

int main (void)
{
//Local Declarations
  int integers[SIZE]; //Data set to store the user given values
  int count; //Data set size
  int value; //Value added to to the data set to complete average calculation

//Function Calls
  count = getInput(integers);
  value = getDigit(integers, count);

//Check if value is within to correct range
  if (value > 0)
  {
    getDataSet(integers, value);
    getAverage(integers, value, count);
  }

//Return Statement
  return (0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the data set to enter the user values
*
*  Function Description: This function ask and stores the user given data set.
*
***************************************************************************/
int getInput(int arry[])
{
//Local Declarations
  int i; //Count meter for the looping
  int count; //Dataset Size

//Input Statement
  printf("Enter data set -> ");

//Storing the user given values into an array
  for (i = 0; i < 20; i++)
  {
    scanf("%d",&arry[i]);
    count += 1;
    if ((arry[i] == -1))
    {
      i = 30;
      count -= 1;
    }
  } 

//Output Statement
  printf("\nSize of data set: %d\n", count);

//Return Statement
  return (count);
} //End getInput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getDigit
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the data set given by the user
*    2. int count, the data set size
*
*  Function Description: This function computes the number that is needed
*  to add to the data set.
*
***************************************************************************/
int getDigit(int arry[], int count)
{
//Local Declarations
  int i; //Count meter for looping
  int total = 0; //Total sum of the data set
  int number = -1; //Number computed to add to data set

//Finding total
  for (i = 0; i < count; i++)
  {
    total += arry[i];
  }

//Check for condition that the number is valid and within the range of data set
  for (i = arry[0] + 1; i < arry[count - 1]; i++)
  {
    if ((number == -1) && ((total + i) % (count + 1) == 0))
    {
      number = i;
    }
  }

//Check if number exists to add to data set
  if (number == -1)
  {
    printf("Digit to add to set: no such value\n");
  }

  else
  {
    printf("Digit to add to set: %d\n", number);
  }

//Return Statement
  return (number);
} //End getDigit

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getDataSet
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the dataset given by the user
*    2. int number, the number computed to add to the data set
*
*  Function Description: This function checks for the data index of the number
*  computed to add to the data set.
*
***************************************************************************/
void getDataSet (int arry[], int number)
{
//Local Declarations
  int i = 0; //Count meter for looping

//Check for data index
  while ((number > arry[i + 1]))
  {
    i++;
  } //End while

//Output Statement
  printf("Number found between index: %d, %d\n", i, i + 1); 

//Return Statement
  return;
} //End getDataSet

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getAverage
*
*  Function Return Type: Void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the dataset given by the user
*    2. int number, the number found to add to the data set
*    3. int count, the number of dataset given by the user
*
*  Function Description: This Function computes the average of the dataset
*
***************************************************************************/
void getAverage (int arry[], int number, int count)
{
//Local Declarations
  int i; //Count meter
  int sum = 0; //Sum of data set
  int total; //Total of sum and number to add to data set
  int average; //Computed average

//Calculation for the sum of the dataset
  for ( i = 0; i < count; i++)
  {
    sum += arry[i];
  }

//Calculations for the average
  total = sum + number;
  average = total / (count + 1);

//Output Statement
  printf("Average with new digit: %d / %d = %d.0\n", total, count + 1, average);

//Return Statement
  return;
} //End getAverage
