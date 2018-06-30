// GET FUNCTION HEADER FILE
#include <stdio.h>
#include <math.h>

float f(float x, float *fn)
{
  int i, d = (int)*(fn + 19);
  float result = 0;
  for (i = 0; i <= d; i++)
  {
    result += *(fn + i) * pow(x, d - i);
  }
  return result;
}

float fderivate(float x, float *fn)
{
  int i, d = (int)*(fn + 19);
  float result = 0;
  for (i = 0; i < d; i++)
  {
    result += (d - i) * *(fn + i) * pow(x, d - i - 1);
  }
  return result;
}

float *get_fn()
{
  int i, degree;
  static float fn[20];
  float x, result;

  // get function
  printf("Function degree : ");
  scanf("%d", &degree);
  fn[19] = degree;

  for (i = 0; i <= degree; i++)
  {
    printf("Multiple of %d. degree : ", degree - i);
    scanf("%f", &fn[i]);
  }

  return &fn[0];
}
