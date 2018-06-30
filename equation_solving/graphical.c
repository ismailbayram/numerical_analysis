#include <stdio.h>
#include <math.h>
#include "../get_fn.h"

int main()
{
  float *fn = get_fn();
  float result, x0, delta, epsilon;
  int step = 0;

  printf("x0 : ");
  scanf("%f", &x0);
  printf("delta : ");
  scanf("%f", &delta);
  printf("epsilon : ");
  scanf("%f", &epsilon);

  do
  {
    if (f(x0, fn) * f(x0 + delta, fn) > 0)
    {
      x0 += delta;
    }
    else
    {
      delta = delta / 2;
    }
    step++;
  } while (fabs(f(x0, fn)) > epsilon && step < 1000); // fabs() fn return absolute value of a float

  if (step < 100)
  {
    printf("Equation solved in %d. step. \nRoot X = %f", step, x0);
  }
  else
  {
    printf("Iteration increased more than 1000 times");
  }

  return 0;
}