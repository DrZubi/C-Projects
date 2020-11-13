
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. boesk@purdue.edu
*  3. cook297@purdue.edu (delete line if no third partner)
*
*  Lab #: Lab01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30-5:20, SC289
*
*  Program Description: This program calculates the circumfrence and volume of three snowballs forming a snowman. 
*
*
***************************************************************************/
#include<stdio.h>
#define PI 3.1416 //declaration of the constant PI

int main (void)
{
//local declarations
  float radius1; //radius of the lowest sphere of the snowman
  float radius2; //radius of the second sphere of the snowman
  float radius3; //radius of the third sphere of the snowman
  float circ1; //Circumfrence of the lowest sphere
  float circ2; //Circumfrence of the middle sphere
  float circ3; //Circumfrence of the top sphere
  float vol1; // Volume of the lowest sphere
  float vol2; // Volume of the middle sphere
  float vol3; // Volume of the top sphere

//Initial Statment asking for user input
  printf("Please enter the value of the largest radius -> ");
  scanf("%f", &radius1);

//calculations for volume and circumference of the spheres
  radius2 = radius1 / 2;  
  radius3 = radius2 / 2;
  circ1 = 2 * PI * radius1; //Equation for circumfrence of a circle
  circ2 = 2 * PI * radius2;
  circ3 = 2 * PI * radius3;
  vol1 = (4.0 / 3) * PI * (radius1 * radius1 * radius1); //Equation for the volume of a sphere
  vol2 = (4.0 / 3) * PI * (radius2 * radius2 * radius2);
  vol3 = (4.0 / 3) * PI * (radius3 * radius3 * radius3);

//Output print statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nRadius #1 is:%16.2f",radius1);
  printf("\nRadius #2 is:%16.2f",radius2);
  printf("\nRadius #3 is:%16.2f",radius3);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nCircumference #1 is:%9.2f",circ1);
  printf("\nCircumference #2 is:%9.2f",circ2);
  printf("\nCircumference #3 is:%9.2f",circ3);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nVolume #1 is:%16.2f",vol1);
  printf("\nVolume #2 is:%16.2f",vol2);
  printf("\nVolume #3 is:%16.2f\n",vol3);

//Return statement
  return 0;
} //main
