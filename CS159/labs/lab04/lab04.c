/**************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. boesk@purdue.edu
*  3. cook297@purdue.edu (delete line if no third partner)
*
*  Lab #: 04
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, SC 289, 3:50 - 5:30
*
*  Program Description: With a given seed, this program generates a random point value
*  between 0 and 1000 and returns a letter grade. When the amount of poitns is 0,
*  it returns an N with the F letter grade.
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Global Declarations
#define AMIN 800 //define A minimum number of points
#define BMIN 675 //defin B minimum number of points
#define CMIN 550 //define C minimum number of points
#define DMIN 425 //define D minimum number of points
#define MAXPOINTS 1000 //define maximum number of points
#define MINPOINTS 0 //define minimum number of points
  
int getSeed (void);
int getRandom (int);
void displayPoints (int);
char gradeCalc (int);
void displayGrade (char,int);
  
int main (void)
{
//Local Declarations
  int seed; //given seed from user
  int points; //random point value between 0 and 1000
  int grade; //letter grade earned by student
            
//User Input Statements
  seed = getSeed();
  points = getRandom(seed);
                  
//Grade Output Statements
  displayPoints(points);
  grade = gradeCalc(points);
  displayGrade(grade, points);
                          
//Return Statement
  return (0);
} //End Main
  
/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): void
*
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
                
//Return Statement
  return (input);
} //end getSeed
  
/***************************************************************************
*
*  Function Information
*
*  Name of Function: random
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the seed entered by user
*
*  Function Description: This function takes in given seed value and
*  generates random value for points between 0 and 1000.
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
                  
//Return Statement
  return (randNo);
} //End getRandom
  
/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayPoints
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, points, random number of earned points (0 to 1000)
*
*  Function Description: This function displays the total number of points
*  earned by the student.
*
***************************************************************************/
  
void displayPoints (int points)
{
//Statements
  printf("\nTotal Points Earned: %d\n", points);
        
//Return Statement
  return;
} //End displayPoints
  
/***************************************************************************
*
*  Function Information
*
*  Name of Function: gradeCalc
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, points, number of points earned by student (0 to 1000)
*
*  Function Description: This function calculates the letter grade
*  earned by the student using given minimum letter grade requirements.
*
****************************************************************************/
  
char gradeCalc (int points)
{
//Local Declarations
  char letterGrade; //earned letter grade
  int gradeFactor; //factor to determine letter grade
  int gradeFactorD; //factors in when points is greater than 950
            
//Statements
  gradeFactor = points / AMIN;
  gradeFactor += points / BMIN;
  gradeFactor += points / CMIN;
                    
  gradeFactorD = points / DMIN;
  gradeFactorD = (gradeFactorD + 2) % (gradeFactorD + 1);
  gradeFactor += gradeFactorD;
                          
  letterGrade = 'F' - gradeFactor;
  letterGrade -= gradeFactorD;
                              
//Return Statement
  return (letterGrade);
} //End gradeCalc
  
/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayGrade
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. char, grade, letter grade earned by student
*    2. int, points, points earned by student (0 to 1000)
*
*  Function Description: This function displays the letter grade earned
*  by the student and displays an N next to the F when the student earns
*  0 points.
*
****************************************************************************/
  
void displayGrade (char grade, int points)
{
//Local Declarations
  int factorN; //factor to get all points greater than 0 equal to 1
  char finalN; //final factor to display N next to F when 0, or a space when not 0
          
//Statements
  factorN = (points + 2) % (points + 1);
  finalN = 'N' - factorN * 46;
  printf("Course Grade Earned: %c%c\n",grade,finalN);
                  
//Return Statement
  return;
} //End displayGrade
