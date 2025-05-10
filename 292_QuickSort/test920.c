#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
int partition(int *array, int low, int high) {
  int pivotIndex = low + (rand() % (high - low));
  if (pivotIndex != high)
    swap(&array[pivotIndex], &array[high]);

  int pivotValue = array[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (array[j] <= pivotValue) {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);
  return i;
}

void quickSortRecursion(int *array, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(array, low, high);
    quickSortRecursion(array, low, pivotIndex - 1);
    quickSortRecursion(array, pivotIndex + 1, high);
  }
}
void quickSort(int *array, int length) {
  srand(time(NULL));
  quickSortRecursion(array, 0, length - 1);
}

int main() {
  int a[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
  int length = 13;

  quickSort(a, length);

  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\t", i, a[i]);
  printf("\n");
  return 0;
}