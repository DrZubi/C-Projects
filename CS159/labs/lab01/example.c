/* This program calculates and prints the sum of three numbers input by the user at the keyboard.
Written By: Omar Zu'bi
Date: 1/15/2019 
*/
#include <stdio.h>

int main (void)
 {
   //local declaration
   int a; 
   int b;
   int c;
   int sum;

   //statements
   printf("Welcome. This program adds three numbers.\n");
   printf("Enter the first number -> ");
   scanf("%d", &a);
   printf("Enter the second number -> ");
   scanf("%d", &b);
   printf("Enter the third number -> ");
   scanf("%d", &c);

   // Numbers are now in a, b , c. Add them.
   sum = a + b + c;

   printf("\nThe total is: %d\n\n" , sum);

   printf("Thank you. Have a good day.\n");
   return 0;

 } //main
