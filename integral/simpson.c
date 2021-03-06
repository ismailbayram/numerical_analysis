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
    if (i % 2 == 1) {
      result += 4 * f(bottom_limit + i * h, fn);
    } else {
      result += 2 * f(bottom_limit + i * h, fn);
    }
  }

  result += f(bottom_limit, fn) + f(top_limit, fn);

  result = result * h / 3;

  printf("Result : %f", result);

  return 0;
}
