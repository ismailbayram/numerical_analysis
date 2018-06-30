#include <stdio.h>

int main()
{
  int i, j, m;
  float static matrix[50][50], unit[50][50];
  float current_element, current_row;

  printf("Dimension of Matrix : ");
  scanf("%d", &m);

  // create unit matrix
  for(i = 0; i < m; i++) {
    unit[i][i] = 1;
  }
  
  // input matrix
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      printf("matrix[%d][%d] : ", i, j);
      scanf("%f", &matrix[i][j]);
    }
  }

  // transactions
  for(i = 0; i < m; i++) {
    current_element = matrix[i][i];

    for(j = 0; j < m; j++) {
      matrix[i][j] = matrix[i][j] / current_element;
      unit[i][j] = unit[i][j] / current_element;
    }

    for(int k = 0; k < m; k++) {
      if(k != i) {
        current_row = matrix[k][i];
        for(j = 0; j < m; j++) {
          matrix[k][j] = matrix[k][j] - (matrix[i][j] * current_row);
          unit[k][j] = unit[k][j] - (unit[i][j] * current_row);
        }
      }
    }
  }

  // print matrixes
  printf("\n\nMATRIX :\n");
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      printf("%.3f  ",matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n\nUNIT MATRIX(INVERSE OF FIRST MATRIX) : \n");
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      printf("%.3f  ",unit[i][j]);
    }
    printf("\n");
  }


  return 0;
}
