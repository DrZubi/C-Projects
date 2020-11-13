
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. ozubi@purdue.edu
*  
*
*  Homework #:Hw01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The project I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 3:30pm , sc289
*
*  Program Description: This program calculates Amdahl's speedup and runtime with the
*  given number of cores, runtime and the percent of the program that can be 
*  parallelized.
*
***************************************************************************/
#include <stdio.h>

int main (void)
{

// Local Declarations
  double base_runtime; // User given base runtime
  double parallelized; // User given number of program parallelized
  int cores; // User given number of cores
  double speedup; // Calculated speedup time with given cores
  double infinite; // Calculated speedup with infinite cores
  double diffrence; // Diffrence between runtimes
  double runtime; // Calculated runtime with given cores
  double inf_runtime; // Calculated infinite core runtime

// User input print statements
  printf("\nEnter the runtime of the program (seconds) -> ");
  scanf("%lf", &base_runtime);
  printf("Enter the percent of the program that can be parallelized -> ");
  scanf("%lf", &parallelized);
  printf("Enter the number of cores -> ");
  scanf("%d", &cores);
 
// Calculations with given user inputs
  speedup = 1 / ((1 - (parallelized / 100)) + ((parallelized / 100) / cores)); //Equation to calculate the speedup
  infinite = 1 / ((1 - (parallelized / 100))); //Equation to calculate speedup with infinite cores
  runtime = base_runtime / speedup; //equation to calculate runtime
  inf_runtime = base_runtime / infinite; //equation to calculate runtime with infinite cores
  diffrence = runtime - inf_runtime; //Diffrence between runtimes 
    
// Print statements feedback
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nBase runtime: %0.3lf seconds",base_runtime);
  printf("\nAmdahl's speedup with %d cores: %0.3lf",cores,speedup);
  printf("\nRuntime with %d cores: %0.3lf seconds",cores,runtime);
  printf("\nAmdahl's speedup with infinite cores: %0.3lf",infinite);
  printf("\nRuntime with infinite cores: %0.3lf seconds",inf_runtime);
  printf("\nRuntime improvement difference: %0.3lf seconds",diffrence);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
// Return statement
  return 0; //main
}
