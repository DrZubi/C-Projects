/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: Hw05
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: This program presents the user with two options from which 
*  they can select and perform tests on the random number generator.
*
***************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void getInput(void);
int getRandom(int);

int main(void)
{
//Welcome Statement
  printf("\nRandom Number Testing Options");
  printf("\n1. Find a seed");
  printf("\n2. Find a number\n");

//Output Statements
  getInput();

//Return Statement
  return (0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function displays the input of the user value
*  and their outcomes. 
*
***************************************************************************/
void getInput(void)
{
//Local Declarations
  int option = 0; //Initialization of option choice
  int inputSeed = 0; //Initialization of seed input 
  int inputDesired = -1; //Initialization of desired input
  int outputSeed; //Output seed value
  int randomNumber; //Random number generated from random number generator
  int count = 1; //Initialization of counts

//Check for valid option inputs
  while(option != 1 && option != 2)
  {
    printf("Enter option -> ");
    scanf("%d",&option);
    if (option != 2 && option != 1)
    {
      printf("\nError - Invalid option! Please try again!\n\n");
    }
  } 

//Check for valid seed inputs
  while (inputSeed <= 0 || inputSeed > 100000)
  {
    printf("Enter starting seed value -> ");
    scanf("%d", &inputSeed);
    if (inputSeed <= 0 || inputSeed > 100000)
    {
      printf("\nError - Enter a value from 1 to 100000\n\n");
    }
  }

//Check for valid desired inputs
  while (inputDesired < 0 || inputDesired > 100000)
  {
    printf("Enter desired integer number -> ");
    scanf("%d", &inputDesired);
    if (inputDesired < 0 || inputDesired > 100000)
    {
      printf("\nError - Enter a value from 0 to 100000\n\n");
    }
  }

//Initialization of random numbers
  outputSeed = inputSeed;
  randomNumber = getRandom(outputSeed);

//Calculations for each options
  if (option == 2)
  {
    while (randomNumber != inputDesired)
    {
      ++count;
      randomNumber = (rand() % 100001); 
    }
  }
  else
  {
    while (randomNumber != inputDesired)
    {
      ++outputSeed;
      randomNumber = getRandom(outputSeed);
    }
  }
  
//Output Statments
  printf("\nGiven starting seed [%d] and desired number [%d]", inputSeed, inputDesired);
  
  switch(option)
  {
    case 1:
      printf("\nSeed that generates desired number first: %d\n", outputSeed);
      break;
    case 2:
      printf("\nCount of number generations until desired found: %d\n", count);
  }

//Return Statement
  return;
} //End getInput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getRandom
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, inputSeed, the seed value input given by the user
*
*  Function Description: This function creates a random number when given a seed
*
***************************************************************************/
int getRandom (int inputSeed)
{
//Local Declarations
  int value; //To store the random generated value

//Random value generator
  srand(inputSeed);
  value = rand() % 100001;

//Return Statement;
  return (value);
}
