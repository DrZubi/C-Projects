/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: Hw02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: Given the data size, the complexity category, and the
*  coefficient, this program calculates the runtime for two algorithms and then
*  identifies the faster algorithm and the time diffrence between the two.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void)
{

//local Declarations
  int dataSize; //Size of the data set to sort
  int complexityOne; //Complexity option for algorithm one
  int complexityTwo; //Complexity option for algorithm two
  double coefficientOne; //Coefficient of algorithm one
  double coefficientTwo; //Coefficient of algorithm two 
  int fastestAlg; //The fastest algorithm of the two calculated
  double difference; //The time difference of both algorithms
  int factor1; //Factor one used for logic operations
  int factor2; //Factor two used for logic operations
  int factor3; //Factor three used for logic operations
  double resultOne; //Result of algorithim one
  double resultTwo; //Result of algorithim two
  double equationOne; //Complexity equation one
  double equationTwo; //Complexity equation two
  double equationThree; //Complexity equation three
  int factorOne; //Check for the algorithm to be the same
  int factorTwo; //Check for the algorithm to be the same

//Print Statements
  printf("\n-=- Algorithm Complexity Options -=-\n");
  printf("\n1. Linear time [n]\n");
  printf("2. Logarithmic time [nlog(n)]\n");
  printf("3. Exponential time [n^2]\n");

//Input Statements
  printf("\nEnter the size of the data set to sort -> ");
  scanf("%d", &dataSize);
  printf("Select complexity option #1 -> ");
  scanf("%d", &complexityOne);
  printf("Enter the coefficient of algorithm #1 -> ");
  scanf("%lf", &coefficientOne);
  printf("Select complexity option #2 -> ");
  scanf("%d", &complexityTwo);
  printf("Enter the coefficient of algorithm #2 -> ");
  scanf("%lf", &coefficientTwo);

//Complexity Equations
  equationOne = dataSize;
  equationTwo = dataSize * log2(dataSize);
  equationThree = pow(dataSize,2);
  
//Logic for determining the complexity of algorithm one
  factor1 = 1 / complexityOne;
  factor3 = (complexityOne / 3);
  factor2 = (complexityOne / 2) - (factor3);

//Result of algorithm one
  resultOne = coefficientOne * ((factor1 * equationOne) + (factor2 * equationTwo) + (factor3 * equationThree));

//Logic for determining the complexity of algorithm two
  factor1 = 1 / complexityTwo;
  factor3 = (complexityTwo / 3);
  factor2 = (complexityTwo / 2) - (factor3);
 
//Result of algorithim two
  resultTwo = coefficientTwo * ((factor1 * equationOne) + (factor2 * equationTwo) + (factor3 * equationThree));

//Calculation for the diffrence of the two algorithms
  difference = resultTwo - resultOne;
  difference = pow(difference,2);
  difference = sqrt(difference);

//Logic for testing which algorithm runs fastest    
  factor1 = resultOne / resultTwo;   // 10 10, 3 4 , 6 5
  factor2 = resultTwo / resultOne;
  factorOne = factor1;
  factorTwo = factor2;
  factor1 = (factor1 + 1) % (factor1 + 2);  
  factor2 = (factor2 + 1) % (factor2 + 2);  
  fastestAlg = factor1 * 2 + factor2 * 1;  
  fastestAlg = fastestAlg / (factor1 + factor2);
  fastestAlg = fastestAlg * (1 + (factor1 * factor2));

//Output Statements
  printf("\nTime for algorithm #1 in seconds: %0.3lf", resultOne);
  printf("\nTime for algorithm #2 in seconds: %0.3lf", resultTwo);
  printf("\nFaster algorithm #: %d", fastestAlg);
  printf("\nTime difference (seconds): %0.3lf\n", difference);

//Return Statement
  return 0;
} //Main
