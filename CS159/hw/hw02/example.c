#include <stdio.h>
#include <math.h> 
int main (void)
{

int factor1;
int factor2;
double result1;
double result2;
int fast;
int test;
int fast2;

printf("\nNum1 ");
scanf("%lf",&result1);
printf("Num2 ");
scanf("%lf",&result2);

//result 10 //result 10

factor1 = result1 / result2;
printf("\nfactor1 %d",factor1);

factor2 = result2 / result1;
printf("\nfactor2 %d",factor2);

factor1 = (factor1 + 1) % (factor1 + 2);
printf("\nfactor1 %d",factor1);

factor2 = (factor2 + 1) % (factor2 + 2);
printf("\nfactor2 %d",factor2);

fast = factor1 * 2 + factor2 * 1;
printf("\nfast %d", fast);

fast2 = factor2 * 2 + factor1 * 1;

fast = (fast * 2) / fast2;

//fast = fast / (factor1 + factor2);
printf("\nfastnew %d\n", fast);

test = 1 % 2;
printf("\n test: %d", test);


return (0);
}
