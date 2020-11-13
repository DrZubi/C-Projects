/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*
*  Homework #: Hw07
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30, SC289
*
*  Program Description: Given a data set that includes up to 25 non-negative integer values;
*  this program sorts the data set from least to alrgest.
*
***************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 25

void getOutput(int,int,int[],int[],int[],int,int);
int getInput(int[],int*);
void segData(int[],int,int);
void sortData(int[],int);
int getCheck(int[],int[],int);

int main(void)
{
//Local Declarations
  int inputAry[SIZE]; //A place to store the data set entered by the user
  int numSort; //The number of elements to sort 
  int dataSize; //The size of the data set

//Function Calls
  numSort = getInput(inputAry,&dataSize);
  segData(inputAry,numSort,dataSize);

//Return Statement
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the data set entered by the user
*    2. int* numCount, the dataSize of the data set
*
*  Function Description: This function will prompt the user for an input
*
***************************************************************************/
int getInput(int arry[], int* numCount)
{
//Local Declarations
  int i; //Count meter i for looping purposes
  int count = 0; //Number of iterations while looping
  int sort; //Elements to sort

//Input Statement for data set
  printf("Enter data set -> ");
  for (i = 0; i < SIZE; i++)
  {
    scanf("%d", &arry[i]);
    count++;
    if (arry[i] < 0)
    {
      i = SIZE + 30;
    }
  }

//Input statement for the number of elements to sort 
  do
  { 
    printf("Enter number of elements to sort -> ");
    scanf("%d",&sort);
    if(sort <= 0)
    {
      printf("\nError! Positive values only!\n\n");
    }
    if(sort > count - 1)
    {
      printf("\nError! Maximum number to sort is %d\n\n",count - 1);
    }  

  }while((sort <= 0) || (sort > count - 1));

//Storing the size of the data set
  if(count != 25)
  {
    *numCount = count - 1;
  }
  else
  {
    *numCount = count;
  }

//Return Statement
  return (sort);
} //End getInput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: segData
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the data set entered by the user
*    2. int numSort, the number of elements to sort
*    3. int dataSize, the data size of the data set
*
*  Function Description: This function segments the data set into two parts
*
***************************************************************************/
void segData(int arry[],int numSort, int dataSize)
{
//Local Declarations
  int segArryFirst[numSort]; //The first segmented array
  int segArryLast[numSort]; //The last segmented array
  int dummyArryLast[numSort]; //Dummy array to store the last data set for testing purposes
  int i; //Count meter i for looping purposes
  int value; //The value outcome of a test
  int count = 0; //to count the number of iterations in a loop 
  int initial = 0; //to determine if the first segmented data set is initially sorted
  int v; //Count meter v for looping purposes
  int final = 0; //to determine if the final segmented data set is initially sorted

//Segementing the given array to get the first n digits
  for(i = 0; i < numSort; i++)
  {
    value = arry[i];
    segArryFirst[i] = value;
    count++;
  }

//Sorting the first segmented data
  sortData(segArryFirst,numSort);

//Check if first segment was initially sorted
  initial = getCheck(segArryFirst,arry,numSort);

//Replacing the correct values into the initial array
  for(i = 0; i < numSort; i++)
  {
    value = segArryFirst[i];
    arry[i] = value;
  }

//Reinitialization of v
  v = 0;

//Segmenting the last parts of the updated array
  for(i = dataSize - numSort; i < dataSize; i++)
  {
    value = arry[i];
    segArryLast[v] = value;
    dummyArryLast[v] = value;
    v++;
  }

//Ordering the last arry bit
  sortData(segArryLast,numSort);

//Check if final segment was initially sorted
  final = getCheck(segArryLast,dummyArryLast,numSort);

//Reinitialization of count v;  
  v = 0;

//Replacing the correct values into the initial array
  for(i = dataSize - numSort; i < dataSize; i++)
  {
    value = segArryLast[v];
    arry[i] = value;
    v++;
  } 

//Getting the output of the data
  getOutput(initial,final,segArryFirst,segArryLast,arry,numSort,dataSize);

//Return Statement
  return;
} //End segData

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortData
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arry[], the data set enterd by the user
*    2. int dataSize, the data size of the data set
*
*  Function Description: This function sorts the data set using the bubble method,
*  Taken from the CS159 Note packet.
*
***************************************************************************/
void sortData (int arry[], int dataSize)
{
//Local Declarations
  int i; //Count meter i for looping purposes
  int lcv; //Local called variable of the dataset
  int temp; //Temporary place to store the data set value

//Sorting algorithim (Taken from the CS159 note packet)
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
} //End sortData

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int initial, to determine weather the first segmented array was sorted
*    2. int final, to determine weather the final segmented array was sorted
*    3. int segArryFirst[], the first segmented array being printed
*    4. int segArryLastp[], the last segmented array being printed
*    5. int arry[], the whole array updated and to be printed
*    6. int numSort, the number of elements sorted in the array
*    7. int dataSize, the dataSize of the data set
*
*  Function Description: This function prints out the desired output of the user. 
*
***************************************************************************/
void getOutput (int initial, int final, int segArryFirst[], int segArryLast[], int arry[], int numSort, int dataSize)
{
//Local Declarations
  int i; //Count meter i for looping
  
//Printing the status of the first elements
  printf("\nStatus of first %d elements: ", numSort);
  if(initial == 1)
  {
    printf("already sorted");
  }
  else
  {
    for(i = 0; i < numSort; i++)
    {
      printf("%d ",segArryFirst[i]);
    }
  }
  printf("\nStatus of final %d elements: ", numSort);
  if(final == 1)
  {
    printf("already sorted");
  }
  else
  {
    for(i = 0; i < numSort; i++)
    {
      printf("%d ",segArryLast[i]);
    }
  }
  
  printf("\nFinal array configuration: ");
  for(i = 0; i < dataSize; i++)
  {
    printf("%d ", arry[i]);
  }
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCheck
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int segArry[], the segmented array data list
*    2.int arry[], the dummy array being compared to the segmented array
*    3.int numSort, the data size of the data set being compared
*
*  Function Description: This function checks weather or not the segmented array was 
*  initially sorted.
*
***************************************************************************/
int getCheck(int segArry[], int arry[], int numSort)
{
//Local Declarations
  int check = 0; //To check if the array was arleady sorted
  int i; //Count meter i for looping purposes

//Check if array was already sorted
  for (i = 0; i < numSort; i++)
  { 
    if (segArry[i] != arry[i])
    {
      check = 0; //False
    }
    else
    {
      check = 1; //True
    }
  }
//Return Statement
  return(check);
} //End getCheck
