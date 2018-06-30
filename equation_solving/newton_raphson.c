#include <stdio.h>
#include <math.h>
#include "../get_fn.h"

int main()
{
  int step = 0;
  float epsilon, x;
  float *fn = get_fn();

  printf("x0 : ");
  scanf("%f", &x);
  printf("Epsilon : ");
  scanf("%f", &epsilon);

  printf("\nCalculating... \n\n");

  do
  {
    x = x - (f(x, fn) / fderivate(x, fn));
    step++;
  } while (fabs(f(x, fn)) > epsilon && step < 1000); // fabs() fn return absolute value of a float

  if (step < 100)
  {
    printf("Equation solved in %d. step. \nRoot X = %f", step, x);
  }
  else
  {
    printf("Iteration increased more than 1000 times");
  }

  return 0;
}
