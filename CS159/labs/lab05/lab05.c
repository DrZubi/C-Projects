/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. mtolkacz@purdue.edu
*  3. elkins15@purdue.edu (delete line if no third partner)
*
*  Lab #: Lab 05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: This program computes the generated force, normal force,
*  force of kinetic friction, and acceleration when given a seed by the user.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fenv.h>

//Global Declarations
int getSeed(void);
int getRandom(void);
void displayOutput(int, int*, int, double*);

int main(void)
{
//Local Declarations
  int seed; //Seed given by the user
  int numAttempt = 1; //Initial attempt number
  int range = 90; //Range values
  int randomForce;  //Random force generated by the seed
  double offsetNumber = 0; //Offset Number

//Input Statements
  seed = getSeed();
  srand(seed);
  randomForce = getRandom();
  
//Range Alternations
  range = range + offsetNumber;

//Output Statements
  displayOutput(range, &numAttempt, randomForce, &offsetNumber);
  range = 90;
  range = range + trunc(offsetNumber);
  randomForce = getRandom();
  displayOutput(range, &numAttempt, randomForce, &offsetNumber);
  range = 90;
  range = range + trunc(offsetNumber);
  randomForce = getRandom();
  displayOutput(range, &numAttempt, randomForce, &offsetNumber);
  
//Return Statement
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function recieves the seed input from the user
*
***************************************************************************/
int getSeed(void)
{
//Local Declarations
  int inputSeed; //Input seed from the user

//Statements
  printf("\nEnter seed value for random number generator -> ");
  scanf("%d", &inputSeed);

//Return Statement
  return(inputSeed);
} //End of getSeed

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getRandom
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the seed value that was inputted by the user
*
*  Function Description: This value generates a random number from the seed
*  given by the user. This is used to compute random force. 
*
***************************************************************************/
int getRandom (void)
{
//Local Declarations
  int randomNumber; //Random Number generated by the seed

//Statements
  randomNumber = rand() % 11;

//Return Statement
  return (randomNumber);
} //End of getRandom

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, bottomRange, the bottom range of the attempt
*    2. int*, numAttempt, the attempt that the output is displaying 
*    3. int, inputForce, the force generated by the random varaible
*    4. double*, offsetNumber, the offset number of the previous example to compute range
*
*  Function Description: This function displays the outputs of the generated forces
*
***************************************************************************/
void displayOutput(int bottomRange, int* numAttempt, int inputForce, double* offsetNumber)
{
//Local Declarations
  int generatedForce; //Calculated generated force
  double normalForce; //Calculated normal force
  double frictionKinetic; //Calculated frictionKinetic
  double acceleration;  //Calculated acceleration

//Calculations
  generatedForce = bottomRange + inputForce;
  normalForce = (20 * 9.8) - (generatedForce * sin(30 * (M_PI / 180)));
  frictionKinetic = 0.5 * normalForce;
  acceleration = ((generatedForce * cos(30 * (M_PI / 180)) - frictionKinetic) / 20);
  *offsetNumber = trunc(*offsetNumber) + (20 * (0.5 - acceleration));
  
  fesetround(FE_UPWARD); //Changing rounding to upward instead of the default setting of rouding for even numbers. 

//Print Statements
  printf("\nAttempt #: %d Range [%d, %d]", *numAttempt, bottomRange, (bottomRange + 10));
  printf("\nGenerated Force: %d", generatedForce);
  printf("\nNormal Force: %0.1lf", normalForce);
  printf("\nForce of Kinetic Friction: %0.1lf", frictionKinetic);
  printf("\nAcceleration: %0.2lf", acceleration);
  printf("\nOffset for next attempt: %.0lf\n", trunc(*offsetNumber));
  (*numAttempt)++;

//Return Statement
  return;
}
