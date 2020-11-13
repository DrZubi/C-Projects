/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. boesk@purdue.edu
*  3. cook297@purdue.edu
*
*  Lab #: Lab03
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30 PM, SC289
*
*  Program Description: This program calculates and displays both the
*  advertised and actual values for bytes and bits of different model hard drives.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

#define TERA 12 //defined value raised to the power of ten to get Tera
#define MEGA 6 //defined value raised to the power of ten to get Mega
#define GIGA 9 //defined value raised to the power of ten to get Giga
#define BIT_BYTE 8 //defined conversion unit from bits to bytes
#define ACTUAL 1024 //defined conversion of kilobytes to bytes 

int main (void)
{
//Local Declarations
  char prefix; //Prefix of the unit
  char unit; //The unit character (bit or byte)
  double capacity; //Capacity of the hard disk
  double adBits; //Advertised bits
  double adBytes; //Advertised bytes
  double percentage; //Calculated percentage of actual capacity
  double conversion; //The conversion of the advertised capacity to actual capacity
  int factor1; //Factor one for logic to determine the prefix and unit
  int factor2; //Factor two for logic to determine the prefix and unit
  int factor3; //Factor three for logic to determine the prefix and unit
  long adPrefix; //The result of the prefix value that the user entered
  int resultUnit; //The unit value result that the user entered
  long actualPrefix; //Calculation to determine the actual prefix input using 1024 constant
  double binaryBits; //The actual bits for the hard disk
  double binaryBytes; //The actual bytes for the hard disk

//Input statements
  printf("\nEnter the advertised capacity -> ");
  scanf("%lf", &capacity);
  printf("Enter the given prefix -> ");
  scanf(" %c", &prefix);
  printf("Enter the coding unit -> ");
  scanf(" %c", &unit);

//Logic to determine if unit is byte or bit
  factor1 = (66 / unit);
  factor2 = (unit / 98);
  resultUnit = factor1 * BIT_BYTE + factor2;
  
//Logic to determine if prefix is Tera, Mega, or Giga
  factor1 = (prefix / 84);
  factor2 = (71 / prefix);
  factor3 = (77 / prefix + 2) % (prefix / 77 + 1);
  adPrefix = factor1 * pow(10, TERA) + factor2 * pow(10, GIGA) + factor3 * pow(10, MEGA);

//Calculations for advertised bits and advertised bytes
  adBits = adPrefix * resultUnit * capacity; 
  adBytes = adBits / BIT_BYTE;

//Calculations for actual binary bits and binary bytes
  actualPrefix = factor1 * pow(ACTUAL,TERA / 3) + factor2 * pow(ACTUAL,GIGA / 3) + factor3 * pow(ACTUAL,MEGA / 3);
  binaryBits = actualPrefix * resultUnit * capacity;
  binaryBytes = binaryBits / BIT_BYTE;

//Calculations for percentage of storage expected and binary unit conversion
  percentage = adBits / binaryBits;
  conversion = capacity * percentage;
  percentage = percentage * 100;

//Output Statements
  printf("\nDevice as advertised:%11.2f %c%c",capacity,prefix,unit);
  printf("\nAdvertised bits:%16.0lf",adBits);
  printf("\nAdvertised bytes:%15.0lf",adBytes);
  printf("\nBinary unit conversion:%9.2f %c%c",conversion,prefix,unit);
  printf("\nBinary bits:%20.0lf",binaryBits);
  printf("\nBinary bytes:%19.0lf",binaryBytes);
  printf("\nPercentage of storage expected: %0.2lf%%\n",percentage);

//Return Statment
  return (0);
} //Main
