/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. boesk@purdue.edu
*  3. cook297@purdue.edu (delete line if no third partner)
*
*  Lab #:04
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, SC 289. 3:30 - 5:30
*
*  Program Description: With a given seed, this program generates a random value
*  and returns a letter grade associated with that letter value.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Global Declarations
#define AMIN 800 //define A minimum number of points
#define BMIN 675 //define B minimum number of points
#define CMIN 550 //define C minimum number of points
#define DMIN 425 //define D minimum number of points
#define MAXPOINTS 1000 //define maximum number of points
#define MINPOINTS 0 //define minimum number of points
int getSeed (void);
int getRandom (int); 
void displayPoints (int);
char gradeCalc (int);

int main (void)
{
//Local Declarations
  int seed; //given seed from user
  int points; //random point value between 0 and 1000
  int grade; //letter grade earned by student

//Executables
  seed = getSeed();
  points = getRandom(seed);

  displayPoints(points);
  grade = gradeCalc(points);
  printf("\n%c\n",grade);
  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): void
*  Function Description: This function gets the seed integer from user
*
***************************************************************************/

int getSeed (void)
{
//Local Declarations
  int input; //input number from user

//Statements 
  printf("Enter the seed value -> ");
  scanf("%d", &input);
  return input;
} //getSeed

/***************************************************************************
*
*  Function Information
*
*  Name of Function: random
*
*  Function Return Type: integer
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the seed entered by user
*
*  Function Description: This function takes in given seed value and
*  generates random value for points.
*
***************************************************************************/

int getRandom (int seed)
{
//Local Delarations
  int range; //range of possible points
  int randNo; //random number generated
//Statements
  srand(seed);
  range = (MAXPOINTS - MINPOINTS) + 1;
  randNo = rand() % range + MINPOINTS;
  
  return randNo;
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayPoints
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, points, random number of earned points
*
*  Function Description: This function displays the total number of points
*  earned by the student.
*
***************************************************************************/

void displayPoints (int points)
{
//Statements
  printf("\nTotal Points Earned: %d\n", points);

  return;
}

char gradeCalc (int points)
{
//Local Declarations
  char letterGrade; //earned letter grade
  int gradeFactor; //factor to determine letter grade
  
  gradeFactor = points / AMIN;
  gradeFactor += points / BMIN;
  gradeFactor += points / CMIN;
  gradeFactor += points / DMIN;
//Statements
  letterGrade = 'F' - gradeFactor;
  letterGrade -= points / DMIN;

  return (letterGrade);
}










