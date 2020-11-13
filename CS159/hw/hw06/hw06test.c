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

//int * getInput (void);
void getInput(int*);
double getAverage (int ary[]);
void getOutput (int ary[], double, double);
double getMeanDev (int ary[], double);
int getRange(int ary[], int);

int main (void)
{
//Local Declarations
  double average;
  double meanDev;
  int i;
  int inputValues[20];

//Function Calls
//  for(i=0;i<20;i++){
    getInput(&inputValues);
//  }


//testing
for(i=0;i<20;i++){
    printf("\n%d", inputValues[i]);
  }


  average = getAverage(inputValues);
  meanDev = getMeanDev(inputValues, average);
  getOutput(inputValues, average, meanDev);

//Return Statement
  return(0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/
void getInput (int *input)
{
//Local Declarations
  int i;

//Input Statement
  printf("\nEnter 20 integer values -> ");
  for(i = 0; i < 20; i++)
  {
    scanf ("%d", input[i]);
  }

//TESTING
  for(i=0;i<20;i++){
    printf("%d", input[i]);
  }

//Return statement
  return;
} //End getinput

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/
double getAverage (int ary[])
{
//Local Declarations
  int sum = 0;
  int i = 0;

//TESTING
  for(i=0;i<20;i++){
    printf("%d", ary[i]);
  }

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
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/
void getOutput (int ary[], double average, double meanDev)
{
//Local Declarations
  int i;

//Output Statements
  printf("\nData set as entered: ");
  for (i = 0; i < 20; i++){
    printf("%d", ary[i]);
    
    if (i != 19)
    {
      printf(", ");
    }
  }
  
  printf("\nMean: %0.2lf", average);
  printf("\nMean Deviation: %0.2lf", meanDev);
  printf("\nRange of values:");
  printf("\n");

//Return Statement
  return;
} //Eng getOutput
 
/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/
double getMeanDev (int ary[], double average)
{
//Local Declarations
  double meanDev = 0;
  int i;

//Calculations
  for(i = 0; i < 20; i++)
    meanDev += ary[i] - average;

//Return Statement
  return (meanDev / 20.0);
} //End getMeanDev

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/
int getRange (int number[], int amount)
{
//Local Declarations  
  int i;
  int min;
  int max;
  min = number[0];
  max = number[0];

//Check for min and max range
  for (i=1; i < 20; i++)
    {
      if (number[i] < min)
        min = number[i];
      if (max < number[i])
        max = number[i];
    }

//Return Statement
  return(min);
}

