#include <stdio.h>
#include <math.h>
#include "../get_fn.h"

int main()
{
  int step;
  float xaverage, bottom_limit, top_limit, epsilon, x;
  float *fn = get_fn();

  printf("Bottom Limit : ");
  scanf("%f", &bottom_limit);
  printf("Top Limit : ");
  scanf("%f", &top_limit);
  printf("Epsilon : ");
  scanf("%f", &epsilon);

  if (f(bottom_limit, fn) * f(top_limit, fn) > 0)
  {
    printf("Equation root could not found in [%f,%f]", bottom_limit, top_limit);
  }
  else
  {
    printf("\nCalculating... \n\n");
    step = 0;

    do
    {
      xaverage = (top_limit * f(bottom_limit, fn) - bottom_limit * f(top_limit, fn)) / (f(bottom_limit, fn) - f(top_limit, fn));
      printf("%d. step\n", step);
      printf("bottom limit : %f\n", bottom_limit);
      printf("f(bottom_limit) = %f\n", f(bottom_limit, fn));
      printf("top limit : %f\n", top_limit);
      printf("f(top_limit) = %f\n", f(top_limit, fn));
      printf("xaverage : %f\n", xaverage);
      printf("f(xaverage) : %f\n\n", f(xaverage, fn));

      if (f(bottom_limit, fn) * f(xaverage, fn) < 0)
      {
        top_limit = xaverage;
      }
      else
      {
        bottom_limit = xaverage;
      }
      step++;
    } while (fabs(f(xaverage, fn)) > epsilon && step < 1000); // fabs() fn return absolute value of a float

    if (step < 100)
    {
      printf("Equation solved in %d. step. \nRoot X = %f", step, xaverage);
    }
    else
    {
      printf("Iteration increased more than 1000 times");
    }
  }

  return 0;
}
