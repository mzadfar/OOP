#include <stdio.h>
#include <string.h>

int convert(char *string);

int main() {
  char s1[] = "10101";
  int val1 = convert(s1);
  printf("%s binary is converted to %d\n", s1, val1);

  return 0;
}

int convert(char *string) {
  int slen = strlen(string);
  int total = 0, decval = 1;
  for (int i = (slen - 1); i >= 0; i--) {
    if (string[i] == '1') {
      total += decval;
    }
    decval *= 2;
  }
  return total;
}