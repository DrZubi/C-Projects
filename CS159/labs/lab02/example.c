#include<stdio.h>

int main(void)
{
  //Local Declarations
  //char int2;
  int int1;
  //float int3;
  //Statements
  printf("Enter an integer: ");
  scanf("%d", &int1);
  int2 = int1;
  printf("The number as a character: %c\n",int1);
  printf("The number as a decimal  : %d\n",int1);
  //(double) int1;
  printf("The number as a float    : %f\n",int1);
  return 0;
}  
