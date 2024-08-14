#include <stdio.h>
#include <stdlib.h>

int *spiralMatrix(int **A, int rows, int cols, int *returnSize) {
  int *spiralOrder = (int *)malloc(rows * cols * sizeof(int));
  int maxCol = cols - 1;
  int maxRow = rows - 1;
  int minCol = 0;
  int minRow = 0;

  int stateRight = 0;
  int stateLeft = 1;
  int stateDown = 2;
  int stateUp = 3;

  int i = 0;
  int j = 0;

  int currentState = stateRight;

  int totalTerms = (maxCol + 1) * (maxRow + 1);
  *returnSize = 0;

  while (*returnSize < totalTerms) {
    if (currentState == stateRight) {
      if (j < maxCol) {
        spiralOrder[(*returnSize)++] = A[i][j];
        j++;
      } else if (minCol >= maxCol) {
        spiralOrder[(*returnSize)++] = A[i][j];
      } else {
        currentState = stateDown;
        minRow++;
        // j--; // Adjust j back to the last valid position
      }
    } else if (currentState == stateDown) {
      if (i < maxRow) {
        spiralOrder[(*returnSize)++] = A[i][j];
        i++;
      } else {
        currentState = stateLeft;
        maxCol--;
        // i--; // Adjust i back to the last valid position
      }
    } else if (currentState == stateLeft) {
      if (j > minCol) {
        spiralOrder[(*returnSize)++] = A[i][j];
        j--;
      } else {
        currentState = stateUp;
        maxRow--;
        // j++; // Adjust j back to the last valid position
      }
    } else if (currentState == stateUp) {
      if (i > minRow) {
        spiralOrder[(*returnSize)++] = A[i][j];
        i--;
      } else {
        currentState = stateRight;
        minCol++;
        // i++; // Adjust i back to the last valid position
      }
    }
  }

  return spiralOrder;
}

int main() {
  int rows = 5, cols = 4;
  int **C = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    C[i] = (int *)malloc(cols * sizeof(int));
  }
  /*
    int data[4][5] = {{1, 2, 3, 4, 5},
                      {14, 15, 16, 17, 6},
                      {13, 20, 19, 18, 7},
                      {12, 11, 10, 9, 8}};
  */
  int data[5][4] = {{1, 2, 3, 4},
                    {14, 15, 16, 5},
                    {13, 20, 17, 6},
                    {12, 19, 18, 7},
                    {11, 10, 9, 8}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      C[i][j] = data[i][j];
    }
  }

  int returnSize;
  int *result = spiralMatrix(C, rows, cols, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);
  for (int i = 0; i < rows; i++) {
    free(C[i]);
  }
  free(C);

  return 0;
}
