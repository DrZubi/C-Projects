/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. ozubi@purdue.edu
*  2. apilasze@purdue.edu
*  3. imesser@purdue.edu (delete line if no third partner)
*
*  Lab #: lab12
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The project we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description:
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 30

//Global Function Declaration
void getInput(int[]);
void getCalc(int[],int,int);
void sortArry(int, int[]);
int getSum(int, int[]);
void sortData(int[],int);
void getOutput(int[],int,int);

int main (void)
{
//Local Declarations
  int input[SIZE]; //Data set for the fences

//Function Call
  getInput(input);

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
*    1. int arry[], the data set
*
*  Function Description: The functions gets the input values from the user.
*
****************************************************************************/
void getInput (int arry[])
{
//Local Declarations
  int i; //Count meter i for looping purposes
  int segments; //Segment number
  int count; //To keep track of data set

//Input for the fence segment heights
  printf("\nEnter fence segment heights -> ");
  for (i = 0; i < SIZE; i++)
  {
    scanf("%d", &arry[i]);
    count++;
    if (arry[i] < 0)
    {
      i = SIZE + 100;
    }
  }

//Input for the desired number of segments to level
  do
  {
    printf("Enter desired number of segments to level -> ");
    scanf("%d", &segments);
    if (segments < 0) //Check for positive values
    {
      printf("\nError! Number must be positive!\n\n");
    }
    else if (segments > count) //Check if value is within rage of data set
    {
      printf("\nError! Number cannot exceed data set size!\n\n");
    }
  } while ((segments < 0) || (segments > count));

//Function Call
  getCalc(arry,segments,count);

//Return Statement
  return;
} //End getInput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCalc
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the dataset given to us by the user
*    2. int segments, the segment size
*    3. int dataSize, the dataSize of the dataset
*
*  Function Description: This function segments the dataset
*
***************************************************************************/
void getCalc (int arry[], int segments, int dataSize)
{
//Local Declarations
  int segArry[segments]; //Segmented array
  int materials; //Materials needed for the fence
  int i = 0; //Count meter i for looping purposes
  int v = 1; //Count meter v for looping purposes
  int segArryDum[segments]; //Dummy array for comparision purposes
  int value; //Value to store for the segmented array
  int valueDum; //Value to store for the dummy array

//Sort the data set
  sortArry(dataSize, arry);

//Segmenting the array
  do
  {
    for(i = 0; i < segments; i++)
    { 
      //For upper limit bound MAY BE CAUSING SEGMENTATION ISSUE CAUSE OF VALUE V
      valueDum = arry[v + 1];
      segArryDum[v] = valueDum;

      //For segmented part
      value = arry[v];
      segArry[i] = value;
      v++;
    }
  }while(getSum(segments, segArryDum) < getSum(segments, segArry));

//Getting materials
  materials = getSum(segments, segArry);

//Getting Output
  getOutput(segArry, materials, segments);

//Return Statement
  return;
} //End getCalc

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortArry
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dataSize, the size of the data set
*    2. int arry[], the data set given to us by the user
*
*  Function Description: This function sorts the data set from least to greatest.
*
***************************************************************************/
void sortArry(int dataSize, int arry[])
{
//Local Declarations  
  int i; //Count meter i for looping purposes
  int lcv; //located constant variable of the dataSet
  int temp; //Temp variable to store the data from dataset

//Sorting the array (TAKEN FROM THE CS159 NOTE PACKET)
  for (i = 1; i < dataSize; i++)
  {
    for(lcv = 0; lcv < dataSize - i; lcv++)
    {
      if(arry[lcv] > arry[lcv + 1])
      {
        temp = arry[lcv];
        arry[lcv] = arry[lcv + 1];
        arry[lcv + 1] = temp;
      }
    }
  }

//Return Statement
  return;
} //End sortArry

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSum
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int segments, the size of the segmented data set
*    2. int int segArry[], the data set segmented
*
*  Function Description: This function finds the sum of the segmented dataset. 
*
***************************************************************************/
int getSum(int segments, int segArry[])
{
//Local Declarations  
  int sum = 0; //To store the sum
  int i; //Count meter i for looping purposes

//Finding the sum of the segmented array
  for(i = 0; i < segments; i++)
  {
    sum += segArry[segments - 1] - segArry[i];
  }

//Return Statement
  return (sum);
} //End getSum

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the dataset given by the user
*    2. int materials, the materials needed
*    3. int segmentSize, the data size of the data set
*
*  Function Description: This function prints the output of the values given and calculated
*
***************************************************************************/
void getOutput(int arry[], int materials, int segmentSize)
{
//Local Declarations
  int i; //Count meter i for looping purposes

//Output Statements
  printf("\nMaterials required: %d", materials);
  if (materials != 0)
  {
    printf("\nSegments ending at same height: ");
    for (i = 0; i < segmentSize; i++)
    {
      printf("%d ", arry[i]);
    }
  }
  printf("\n");

//Return Statement
  return;
} //End getOutput
