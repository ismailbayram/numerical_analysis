#include <stdio.h>

int main()
{
  int i, j, m;
  float static matrix[50][50], results[50];
  float current_row;

  printf("Dimension of Matrix : ");
  scanf("%d", &m);
  
  // input matrix
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      printf("matrix[%d][%d] : ", i, j);
      scanf("%f", &matrix[i][j]);
    }
  }

  // input results
  for(i = 0; i < m; i++) {
    printf("results[%d] : ", i);
    scanf("%f", &results[i]);
  }


  // transactions
  for(i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      matrix[i][j] = matrix[i][j] / matrix[i][i];
    }
    results[i] = results[i] / matrix[i][i];
  }

  printf("\n\nMATRIX :\n");
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      printf("%.3f  ",matrix[i][j]);
    }
    printf("| %f\n", results[i]);
  }


  return 0;
}
