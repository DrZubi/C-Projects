/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: Hw03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30-5:20, SC 289
*
*  Program Description: This program computes the radius, volume, and surface
*  area of three spheres (large, medium, and small) that make up a snowman.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Global Declarations
int getRadius(void);
void getRadii(double, double*, double*, double*);
void getCircumferences(double, double, double, double*, double*, double*);
double getSurfaceAreas(double, double, double, double*, double*, double*);
double getVolumes(double, double, double, double*, double*, double*);
void displayOutputs(double, double, double, double, double, double, double, double, double, double, double, double, double, double);

//Function Main
int main(void)
{
//Local Declarations
  double radiusInput; //Given radius by user
  double radiusOne; //Radius of the bottom sphere
  double radiusTwo; //Radius of the second sphere
  double radiusThree; //Radius of the top sphere
  double circumferenceOne; //Circumference of the bottom sphere
  double circumferenceTwo; //Circumference of the middle sphere
  double circumferenceThree; //Circumference of the top sphere
  double surfaceAreaOne; //Surface area of the bottom sphere
  double surfaceAreaTwo; //Surface area of the middle sphere
  double surfaceAreaThree; //Surface area of the top sphere
  double volumeOne; //Volume of the bottom sphere
  double volumeTwo; //Volume of the middle sphere
  double volumeThree; //Volume of the top sphere
  double totalVolume; //Total volume of all three spheres
  double totalSurfaceArea; //Total surface area of all three spheres

//User Input Statment
  radiusInput = getRadius();
  getRadii(radiusInput, &radiusOne, &radiusTwo, &radiusThree);

//Statements
  totalSurfaceArea = getSurfaceAreas(radiusOne, radiusTwo, radiusThree, &surfaceAreaOne, &surfaceAreaTwo, &surfaceAreaThree);
  totalVolume = getVolumes(radiusOne, radiusTwo, radiusThree, &volumeOne, &volumeTwo, &volumeThree);
  getCircumferences(radiusOne, radiusTwo, radiusThree, &circumferenceOne, &circumferenceTwo, &circumferenceThree);

//Output Statements
  displayOutputs(radiusOne, radiusTwo, radiusThree, circumferenceOne, circumferenceTwo, circumferenceThree, surfaceAreaOne, surfaceAreaTwo, surfaceAreaThree, volumeOne, volumeTwo, volumeThree, totalSurfaceArea, totalVolume);

//Return Statements
  return(0);
} //End Main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getRadius
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets the radius interger from user
*
***************************************************************************/
int getRadius (void)
{
//Local Declarations
  int input; //input number from user
  
//Statements
  printf("\nPlease enter the value of the largest radius -> ");
  scanf("%d", &input);

//Return Satement
  return (input);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getRadii
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, inputRadius, the input radius given by the user
*    2. double*, radiusOne, the address of the first radius 
*    3. double*, radiusTwo, the address of the second radius
*    4. double*, radiusThree, the address of the third radius
*
*  Function Description: This function calculates the diffrent radii of the
*  spheres when given the user input radius.
*
***************************************************************************/
void getRadii (double inputRadius, double* radiusOne, double* radiusTwo, double* radiusThree) 
{
//Local Delcarations
  *radiusOne = inputRadius;
  *radiusTwo = inputRadius / 2.0;
  *radiusThree = inputRadius / 4.0;

//Return Statement
  return;
} //End of function getRadii

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCircumferences
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, radiusOne, the value of the first sphere's radius
*    2. double, radiusTwo, the value of the second sphere's radius
*    3. double, radiusThree, the value of the third sphere's radius
*    4. double*, circumferenceOne, the address of circumferenceOne
*    5. double*, circumferenceTwo, the address of circumferenceTwo
*    6. double*, circumferenceThree, the address of circumferenceThree
*
*  Function Description: This function calculates the circumferences of all
*  three spheres when given the values of all three spheres' radius.
*
**************************************************************************/
void getCircumferences (double radiusOne, double radiusTwo, double radiusThree, double* circumferenceOne, double* circumferenceTwo, double* circumferenceThree)
{
//Statements
  *circumferenceOne = 2.0 * M_PI * radiusOne;
  *circumferenceTwo = 2.0 * M_PI * radiusTwo;
  *circumferenceThree = 2.0 * M_PI * radiusThree;

//Return Statement
  return;
} //End of function getCircumferences

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSurfaceAreas
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, radiusOne, the value of the first sphere's radius
*    2. double, radiusTwo, the value of the second Sphere's radius
*    3. double, radiusThree, the value of the third sphere's radius
*    4. double*, surfaceAreaOne, the address of surfaceAreaOne
*    5. double*, surfaceAreaTwo, the address of surfaceAreaTwo
*    6. double*, surfaceAreaThree, the address of surfaceAreaThree
*
*  Function Description: This function calculates the surface areas of all
*  three spheres when given the spheres' surface areas.
*
**************************************************************************/
double getSurfaceAreas (double radiusOne, double radiusTwo, double radiusThree, double* surfaceAreaOne, double* surfaceAreaTwo, double* surfaceAreaThree)
{
//Local Declarations
  double calcSurfaceArea = 0; //Calculated total surface area of all three spheres

//Statements
  *surfaceAreaOne = 4.0 * M_PI * pow(radiusOne, 2);
  *surfaceAreaTwo = 4.0 * M_PI * pow(radiusTwo, 2);
  *surfaceAreaThree = 4.0 * M_PI * pow(radiusThree, 2);
  calcSurfaceArea = *surfaceAreaOne + *surfaceAreaTwo + *surfaceAreaThree;

//Return Statement
  return(calcSurfaceArea);
} //End of function getSurfaceArea

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getVolumes
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, radiusOne, the value of the first sphere's radius
*    2. double, radiusTwo, the value of the second sphere's radius
*    3. double, radiusThree, the value of the third sphere's radius
*    4. double*, volumeOne, the address of volumeOne
*    5. double*, volumeTwo, the address of volumeTwo
*    6. double*, volumeThree, the address of volumeThree
*   
*  Function Description: This function calculates the volume of the three
*  spheres when given the spheres' radii. 
*
***************************************************************************/
double getVolumes (double radiusOne, double radiusTwo, double radiusThree, double* volumeOne, double* volumeTwo, double* volumeThree)
{
//Local Declarations
  double calcVolume = 0; //Calculation for the total volume of all three spheres

//Statements
  *volumeOne = (4.0 / 3.0) * M_PI * pow(radiusOne,3);
  *volumeTwo = (4.0 / 3.0) * M_PI * pow(radiusTwo,3);
  *volumeThree = (4.0 / 3.0) * M_PI * pow(radiusThree,3);
  calcVolume = *volumeOne + *volumeTwo + *volumeThree;

//Return Statement
  return(calcVolume);
} //End of function getVolumes

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayOutputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, radiusOne, radius of sphere one 
*    2. double, radiusTwo, radius of sphere two 
*    3. double, radiusThree, radius of sphere three 
*    4. double, circumferenceOne, circumference of sphere one
*    5. double, circumferenceTwo, circumference of sphere two
*    6. double, circumferenceThree, circumference of sphere three
*    7. double, surfaceAreaOne, surface area of sphere one
*    8. double, surfaceAreaTwo, surface area of sphere two
*    9. double, surfaceAreaThree, surface area of sphere three
*    10. double, volumeOne, volume of sphere one
*    11. double, volumeTwo, volume of sphere two
*    12. double, volumeThree, volume of sphere three
*    13. double, totalSurfaceArea, total surface area of all three spheres
*    14. double, totalVolume, total volume of all three spheres
*
*  Function Description: This function displays the output of the radii,
*  circumferences, surface areas, and volumes of all three spheres. 
*
***************************************************************************/
void displayOutputs (double radiusOne, double radiusTwo, double radiusThree, double circumferenceOne, double circumferenceTwo, double circumferenceThree, double surfaceAreaOne, double surfaceAreaTwo, double surfaceAreaThree, double volumeOne, double volumeTwo, double volumeThree, double totalSurfaceArea, double totalVolume)
{
//Output statements
  printf("\nRadius #1 is:%16.2lf",radiusOne);
  printf("\nCircumference #1 is:%9.2lf",circumferenceOne);
  printf("\nSurface Area #1 is:%10.2lf",surfaceAreaOne);
  printf("\nVolume #1 is:%16.2lf",volumeOne);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nRadius #2 is:%16.2lf",radiusTwo);
  printf("\nCircumference #2 is:%9.2lf",circumferenceTwo);
  printf("\nSurface Area #2 is:%10.2lf",surfaceAreaTwo);
  printf("\nVolume #2 is:%16.2lf",volumeTwo);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nRadius #3 is:%16.2lf",radiusThree);
  printf("\nCircumference #3 is:%9.2lf",circumferenceThree);
  printf("\nSurface Area #3 is:%10.2lf",surfaceAreaThree);
  printf("\nVolume #3 is:%16.2lf",volumeThree);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nTotal Volume:%16.2lf",totalVolume);
  printf("\nTotal Surface Area:%10.2lf",totalSurfaceArea);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

//Return Statement
  return; 
} //End of function displayOutputs
