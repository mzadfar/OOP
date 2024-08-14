#include <stdio.h>

void mysubstr(char str[], int low, int high) {
  if (low <= high) {
    printf("%c", str[low]);
    mysubstr(str, low + 1, high);
  }
}

void mysubstrPtr(char str[], int low, int high) {
  printf("\nUsing Pointer: %.*s\n", high - low + 1, (str + low));
}

int main() {
  char str[] = "geeksforgeeks";
  printf("Using Pointer:");
  mysubstr(str, 1, 3);

  mysubstrPtr(str, 1, 3);
  return 0;
}
