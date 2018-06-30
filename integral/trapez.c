#include <stdio.h>
#include "../get_fn.h"

int main()
{
  int i;
  float bottom_limit, top_limit, x, h, n, result, *fn = get_fn();

  printf("top limit : ");
  scanf("%f", &top_limit);
  printf("bottom limit : ");
  scanf("%f", &bottom_limit);
  printf("n : ");
  scanf("%f", &n);

  h = (top_limit - bottom_limit) / n;

  for (i = 1; i < n; i++){
    result += f(bottom_limit + i * h, fn);
  }

  result += (f(bottom_limit, fn) + f(top_limit, fn)) / 2;

  result = result * h;

  printf("Result : %f", result);

  return 0;
}
