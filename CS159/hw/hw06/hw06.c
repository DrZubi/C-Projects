/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: hw06
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: This program computes the mean, standard deviation, and range
*  of values when given 20 integer inputs from the user.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DATASIZE 20

//Global Function Declarations
double getAverage (int[]);
void getOutput (int[], double, double, int, int);
double getMeanDev(int[], double);
int getMin(int[]);
int getMax(int[]);

int main (void)
{
//Local Declarations
  double average; //Average value computed
  double meanDev; //Mean Deviation Computed
  int i;  //Count meter i
  int min;  //Min range value
  int max;  //Max range value
  int inputValues [DATASIZE]; //Array to store input values

//Input Statements (TRY TO PUT THIS INTO A FUNCTION)
  printf("\nEnter 20 integer values -> ");
  for(i = 0; i < 20; i++)
  {
    scanf ("%d", &inputValues[i]);
  }

//Function Calls
  max = getMax(inputValues);
  min = getMin(inputValues);
  average = getAverage(inputValues);
  meanDev = getMeanDev(inputValues, average);
  getOutput(inputValues, average, meanDev, min, max);

//Return Statement
  return(0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getAverage
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int ary [], the twenty values entered by the user
*
*  Function Description: This function computes the average of the values entered
*  by the user
*
***************************************************************************/
double getAverage (int ary[])
{
//Local Declarations
  int sum = 0; // Sum initalization
  int i = 0; //Count meter i

//Calculation
  for (i = 0; i < 20; i++)
  { 
    sum += ary[i];
  }

//Return Statement
  return (sum / 20.0);
} //End getAverage

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int ary [], the values entered by the user
*    2. double average, the average value computed
*    3. int min, the min range value
*    4. int max, the max range value
*
*  Function Description: This function displays the output of the values computed
*
***************************************************************************/
void getOutput (int ary[], double average, double meanDev, int min, int max)
{
//Local Declarations
  int i; //Count meter i

//Output Statements
  printf("\nData set as entered: ");
  for (i = 0; i < 20; i++)
  {
    printf("%d", ary[i]);
    if (i != 19)
    {
      printf(", ");
    }
  } 
  printf("\nMean: %0.2lf", average);
  printf("\nMean Deviation: %0.2lf", meanDev);
  printf("\nRange of values: %d, %d", min, max);
  printf("\n");

//Return Statement
  return;
} //End getOutput
 
/***************************************************************************
*
*  Function Information
*
*  Name of Function: getMeanDev
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int ary [], the values entered by the user
*    2. double average, the average value computed
*
*  Function Description: This function calculates the mean deviation
*
***************************************************************************/
double getMeanDev (int ary[], double average)
{
//Local Declarations
  double meanDev = 0; //Mean deviation initialization
  int i; //Count meter i

//Calculations
  for(i = 0; i < 20; i++)
  {
    meanDev += fabs(ary[i] - average);
  }

//Return Statement
  return (meanDev / 20.0);
} //End getMeanDev

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getMax
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int ary [], the values entered by the user
*
*  Function Description: This function finds the max range value of the values
*  entered by the user.
*
***************************************************************************/
int getMax (int ary[])
{
//Local Declarations  
  int i; //Count meter i
  int max = ary[0]; //Initalization of max range

//Check for max range
  for (i = 1; i < 20; i++)
  {
    if (max < ary[i])
    {
      max = ary[i];
    }
  }

//Return Statement
  return(max);
} //End getMax

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type: getMin
*
*  Parameters (list data type, name, and comment one per line):
*    1. int ary [], the values entered by the user
*
*  Function Description: This function finds the min range value of the
*  values entered by the user.
*
***************************************************************************/
int getMin(int ary[])
{
//Local Declarations 
  int i; //Count meter i
  int min = ary[0]; //Initalization of min range

//Check for lowest range
  for (i = 0; i < 20; i++)
  {
    if (min > ary[i])
    {
      min = ary[i];
    }
  }

//Return Statement
  return (min);
} //End getMin
