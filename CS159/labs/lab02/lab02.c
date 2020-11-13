
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. boesk@purdue.edu
*  3. cook297@purdue.edu
*
*  Lab #: Lab02
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC 289
*
*  Program Description: The program generates a number from a sign value,
*  exponent value, and mantissa value given by the user. 
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

int main (void)
{

//Local Declarations
  int signBinary; //sign value (0 or 1)
  int expoGiven; //exponent value given
  double mantissa; //given mantissa value
  int signVal; //calculated sign from binary digit
  double calcMantissa; //calculated mantissa (1 + mantissa)  
  int expoCalc;  //calculated exponent value
  double result; //calculated result from the given values
  int precision; //precision of the final result

//Input Statements
  printf("Enter the sign value -> ");
  scanf("%d", &signBinary);
  printf("Enter the exponent value -> ");
  scanf("%d", &expoGiven);
  printf("Enter the mantissa value -> ");
  scanf("%lf", &mantissa);

//Calculations
  signVal = pow(-1, signBinary); //calculation for the binary value
  expoCalc = expoGiven - 127; //calculation for the exponent value
  calcMantissa = 1 + mantissa; //calculation for the mantissa value
  result = signVal * pow(2, expoCalc) * calcMantissa; //calculation of the result value
  precision = (expoCalc / 3.0) + 2; //calculation for the percision of result value

//Output Statements
  printf("\n           Sign Exponent   Mantissa\n");
  printf("Input: %7d %7d %12.2f\n", signBinary, expoGiven, mantissa);
  printf("Equation: %4d * 2 ^  %d * %9.2f\n", signVal, expoCalc, calcMantissa);
  printf("Result: %27.*f\n",precision, result);

//Return Statement
  return 0;

} //Main
