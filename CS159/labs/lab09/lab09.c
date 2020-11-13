/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. apilasze@purdue.edu
*  3. imesser@purdue.edu (delete line if no third partner)
*
*  Lab #:lab09
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC 289
*
*  Program Description: This program computes the averages and standard deviation
*  of consecuative seeds that generate random numbers when given the datasize. 
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void getOutput (int,int,double,double);
double calcAverage (int,int);
double calcStd (int,int,double);
int main (void)
{
//Local Declarations
  int dataSize = 0; //Datasize value entered by the user
  int seed; //seed entered by the user
  int numberTest = 0; //Number of tests that will occur
  int count = 0; //Count meter to run the number of tests
  int set = 0; //The display set number for each test
  double std; //The standard deviation calculated
  double average; //The average value calculated

//Input Statements
  printf("\nEnter starting seed value -> ");
  scanf("%d", &seed);
  srand(seed);

//Check for valid input for number seeds
  while ((numberTest < 1 || numberTest > 10))
  {
    printf("Enter number of seeds to test -> ");
    scanf("%d", &numberTest);
    if(numberTest < 1 || numberTest > 10)
    {
      printf("\nError! Number of seeds must be 1 - 10\n\n");
    }
  }

//Check for valid input for data set size
  while ((dataSize < 1) || (dataSize > 10000))
  {
    printf("Enter the data set size -> ");
    scanf("%d", &dataSize);
    if(dataSize < 1 || dataSize > 10000)
    {
      printf("\nError! Data set size must be 1 - 10000\n\n");
    }   
  }

//Output Statment
  printf("\n           Seed   Average   Std Dev");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  
//Determination for number of rows to print with their respected values
  while (count != numberTest)
  {
    ++count;
    ++set;
    average = calcAverage(seed,dataSize);
    std = calcStd(seed, dataSize, average);
    getOutput(set,seed,average,std);
    ++seed;
  }
  printf("\n\n");
  
//Return Statement
  return (0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, setNumber, the number of iterations of the function
*    2. int, seed, the seed incremented
*    3. double, average, the calculated average for the given seed
*    4. double, deviation, the calculated standard deviation 
*
*  Function Description: This function prints the output
*
***************************************************************************/
void getOutput (int setNumber, int seed, double average, double deviation)
{
//Output Statement
  printf("\nSet # %d:%7d%10.1lf%10.1lf",setNumber,seed,average,deviation);

//Return Statement
  return;
} //End getOutput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcAverage
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the seed value entered by the user
*    2. int, dataSize, the data size entered by the user
*
*  Function Description: This function computes the average value of the given seed
*
***************************************************************************/
double calcAverage (int seed, int dataSize)
{
//Local Declarations
  double count = 1.0; //Count meter to run the number of random number generations
  double average = 0.0; //Initialization of the average value

  srand(seed);
  for (count = 0; count < dataSize; count++)
  {
    average += rand() % 1001 * 1.0 / dataSize;
  }

//Return Statemnt
  return (average);
} //End calcAverage

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcStd
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the seed entered by the user
*    2. int, dataSize, the value of the datasize entered by the user
*    3. double, average, the average value calculated
*
*  Function Description: This function calculates the standard deviation
*
***************************************************************************/
double calcStd (int seed, int dataSize, double average)
{
//Local Declarations
  double std = 0; //Initialization of the standard deviation
  int count = 0; //The count meter for the number of tests to run

//Calculation for standard deviation
  srand(seed);
  for (count = 0; count < dataSize; count++)
  {
    std += pow(rand() % 1001 - average, 2.0);
  }

  std = sqrt(std / (dataSize - 1));

//Return Statment
  return (std);
} //End calcStd
