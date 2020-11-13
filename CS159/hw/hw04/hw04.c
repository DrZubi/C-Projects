/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: hw04 
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: This program generates a game from a random seed given by the user
*  The program simulates five spins of the routllete wheel, and displays the result of each game
*  and the players total score.
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayResults(char, int); //Displays the results of the user input
void getValues(char*, char*, char*, int*); //Function that asks the values from the user
void getRandom(int, int*, int*, int*, int*, int*); //Function that calculates the game random numbers
int getScore(char, int); //Function that computes scores of each game

int main (void)
{
//Local declarations
  char choiceOne; //First choice of the user
  char choiceTwo; //Second choice of the user
  char choiceThree; //Third choice of the user

  int seed; //Seed given by the user
  int tossOne; //Outcome of toss one
  int tossTwo; //Outcome of toss two
  int tossThree; //Outcome of toss three
  int tossFour; //Outcome of toss four
  int tossFive; //Outcome of toss five
  int scoreOne; //Score of game one
  int scoreTwo; //Score of game two
  int scoreThree; //Score of game three
  int totalScore; //Calculated total score

//Program description
  printf("\nPossible Choices\n");
  printf("\n'1', '2', or '3' for the 1st, 2nd, or 3rd Dozen 2 Points");
  printf("\n'R' (Red)  or 'B' (Black)                       1 Point");
  printf("\n'E' (Even) or 'O' (Odd)                         1 Point");
  printf("\n'L' (Low)  or 'H' (High)                        1 Point");
  printf("\n-=-=-=-\n");

//Input statements
  getValues(&choiceOne, &choiceTwo, &choiceThree, &seed);
  srand(seed);
  getRandom(seed, &tossOne, &tossTwo, &tossThree, &tossFour, &tossFive);
  
//Calculations for game scores
  scoreOne = getScore(choiceOne, tossOne) + getScore(choiceOne, tossTwo) + getScore(choiceOne, tossThree) + getScore(choiceOne, tossFour) + getScore (choiceOne, tossFive);

  scoreTwo = getScore(choiceTwo, tossOne) + getScore(choiceTwo, tossTwo) + getScore(choiceTwo, tossThree) + getScore(choiceTwo, tossFour) + getScore (choiceTwo, tossFive);

  scoreThree = getScore(choiceThree, tossOne) + getScore(choiceThree, tossTwo) + getScore(choiceThree, tossThree) + getScore(choiceThree, tossFour) + getScore (choiceThree, tossFive);

  totalScore = scoreOne + scoreTwo + scoreThree;

//Output print statement
  printf("Game           Score");
  printf("\n1:");
  displayResults(choiceOne, scoreOne);
  printf("\n2:");
  displayResults(choiceTwo, scoreTwo);
  printf("\n3:");
  displayResults(choiceThree, scoreThree);
  printf("\nTotal Score:%6d\n",totalScore);

//Return statement
  return (0);
} //End main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. char*, choiceOne, address of the first choice given by the user
*    2. char*, choiceTwo, address of the second choice given by the user
*    3. char*, choiceThree, address of the third choice given by the user
*    4. int*, seeed, address of the seed given by the user
*
*  Function Description: This function asks the user for the three choices they would
*  like to select and the seed of the game. 
*
***************************************************************************/
void getValues (char* choiceOne, char* choiceTwo, char* choiceThree, int* seed) //Function that asks the input values from the user
{
//Input statements
  printf("Enter three choices -> ");
  scanf("%c %c %c", choiceOne, choiceTwo, choiceThree);
  printf("Enter the seed -> ");
  scanf("%d", seed);
  printf("-=-=-=-");

//Return Statement
  return; 
} //End getValues

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getRandom
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, seed, the input seed by the user
*    2. int*, tossOne, the address of the outcome of toss one
*    3. int*, tossTwo, the address of the outcome of toss two
*    4. int*, tossThree, the address of the outcome of toss three
*    5. int*, tossFour, the address of the outcome of toss four
*    6. int*, tossFive, the address of the outcome of toss Five
*
*  Function Description: This function takes the seed (given by the user) and generates
*  the random outcomes of five random tosses.
*
***************************************************************************/
void getRandom(int seed, int* tossOne, int* tossTwo, int* tossThree, int* tossFour, int* tossFive) //Function that generates random tosses
{
//Local declarations
  int randomNumberOne; //Random outcome of toss one
  int randomNumberTwo; //Random outcome of toss two
  int randomNumberThree; //Random outcome of toss three
  int randomNumberFour; //Random outcome of toss four
  int randomNumberFive; //Random outcome of toss five

//Random number generator for the five outcomes
  randomNumberOne = rand() % 37;
  randomNumberTwo = rand() % 37;
  randomNumberThree = rand() % 37;
  randomNumberFour = rand() % 37;
  randomNumberFive = rand() % 37;

  *tossOne = randomNumberOne;
  *tossTwo = randomNumberTwo;
  *tossThree = randomNumberThree;
  *tossFour = randomNumberFour;
  *tossFive = randomNumberFive;

//Output statements
  printf("\nThe Ball Landed On: %d %d %d %d %d\n", randomNumberOne, randomNumberTwo, randomNumberThree, randomNumberFour, randomNumberFive);
  printf("-=-=-=-\n");

//Return statement
  return;
} //End getRandom

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getScore
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. char, selection, the game selection input of the user
*    2. int, outcome, the game outcome
*
*  Function Description: This function calculates the outcome of the game
*  selected by the user.
*
***************************************************************************/
int getScore(char selection, int outcome)
{
//Local declarations
  int score = 0; //Initialization of the points scored a the game
                                          
//Switch Statement
  if((selection == 'R') && ((outcome == 1) || (outcome == 3) || (outcome == 5) || (outcome == 7) || (outcome == 9) || (outcome == 12) || (outcome == 14) || (outcome == 16) || (outcome == 18) || (outcome == 19) || (outcome == 21) || (outcome == 23) || (outcome == 25) || (outcome == 27) || (outcome == 30) || (outcome == 32) || (outcome == 34) || (outcome == 36))) 
  {
    ++score;
  }
  else if((selection == 'B') && ((outcome == 2) || (outcome == 4) || (outcome == 6) || (outcome == 8) || (outcome == 10) || (outcome == 11) || (outcome == 13) || (outcome == 15) || (outcome == 17) || (outcome == 20) || (outcome == 22) || (outcome == 24) || (outcome == 26) || (outcome == 28) || (outcome == 29) || (outcome == 31) || (outcome == 33) || (outcome == 35))) 
  {
    ++score;
  }
  else if((selection == 'E') && (outcome % 2 == 0) && (outcome != 0))
  {
    ++score;
  }
  else if((selection == 'O') && (outcome % 2 != 0))
  {
    ++score;
  }
  else if((selection == 'L') && (((outcome >= 1)) && ((outcome <= 18))))
  {
    ++score;
  }
  else if((selection == 'H') && (((outcome >= 19)) && ((outcome <= 36))))
  {
    ++score;
  }
  else if((selection == '1') && (((outcome >= 1) && (outcome <= 12))))
  {
    ++score;
    ++score;
  }
  else if((selection == '2') && ((outcome >= 13) && (outcome <= 24)))
  {
    ++score;
    ++score;
  }
  else if((selection == '3') && ((outcome >= 25) && (outcome <= 36)))
  {
    ++score;
    ++score;
  }

//Return Statement
  return (score);
} //End getScore

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. char, input, the input character from the user
*    2. int, score, the score of the game selected
*
*  Function Description: This function displays the results of the user inputs.
*
***************************************************************************/
void displayResults(char input, int score)
{
//Switch
  switch(input)
  {
    case 'R':  printf(" Red%12d",score);
               break;
    case 'B':  printf(" Black%10d",score);
               break;
    case 'E':  printf(" Even%11d",score);
               break;
    case 'O':  printf(" Odd%12d",score);
               break;
    case 'L':  printf(" Low%12d",score);
               break;
    case 'H':  printf(" High%11d",score);
               break;
    case '1':  printf(" 1st Dozen%6d",score);
               break;
    case '2':  printf(" 2nd Dozen%6d",score);
               break;
    case '3':  printf(" 3rd Dozen%6d",score);
               break;
  }

//Return statement
  return;
} //End displayResults
