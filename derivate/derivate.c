#include <stdio.h>
#include "../get_fn.h"

int main()
{
  int i;
  float deltaX, x, fd, bd, cd, *fn = get_fn();

  printf("deltaX : ");
  scanf("%f", &deltaX);
  printf("x : ");
  scanf("%f", &x);

  // forward derivation
  fd = (f(x + deltaX, fn) - f(x, fn)) / deltaX;
  printf("Forward Derivation : %f\n", fd);

  // backward derivation
  bd = (f(x, fn) - f(x - deltaX, fn)) / deltaX;
  printf("Backward Derivation : %f\n", bd);

  // central derivation
  cd = (fd + bd) / 2;
  printf("Central Derivation : %f", cd);


  return 0;
}
