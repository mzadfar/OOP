#include <stdio.h>

int main() {
  int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
  int length = sizeof(a) / sizeof(a[0]);

  for (int i = 0; i < length - 1; i++) {
    int minPos = i;
    for (int j = i + 1; j < length; j++) {
      if (a[j] < a[minPos])
        minPos = j;
    }
    if (minPos != i) {
      int temp = a[i];
      a[i] = a[minPos];
      a[minPos] = temp;
    }
  }

  for (int i = 0; i < length - 1; i++)
    printf("a[%d] = %d\n", i, a[i]);
  return 0;
}