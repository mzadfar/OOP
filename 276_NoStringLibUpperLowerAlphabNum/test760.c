#include <stdio.h>
#include <stdlib.h>

void to_upper(char *message) {
  while (*message) {
    if (*message >= 'a' && *message <= 'z')
      *message = *message - 'a' + 'A';
    message++;
  }
}

void to_lower(char *message) {
  while (*message) {
    if (*message >= 'A' && *message <= 'Z')
      *message = *message - 'A' + 'a';
    message++;
  }
}

void just_alphabet(char *message) {
  for (int i = 0, j; message[i] != '\0'; ++i) {

    // enter the loop if the character is not an alphabet
    // and not the null character
    while (!(message[i] >= 'a' && message[i] <= 'z') &&
           !(message[i] >= 'A' && message[i] <= 'Z') && !(message[i] == '\0')) {
      for (j = i; message[j] != '\0'; ++j) {

        // if jth element of line is not an alphabet,
        // assign the value of (j+1)th element to the jth element
        message[j] = message[j + 1];
      }
      message[j] = '\0';
    }
  }
}

void just_number(char *message) {
  for (int i = 0, j; message[i] != '\0'; ++i) {

    // enter the loop if the character is not an alphabet
    // and not the null character
    while (!(message[i] >= '0' && message[i] <= '9') && !(message[i] == '\0')) {
      for (j = i; message[j] != '\0'; ++j) {

        // if jth element of line is not an alphabet,
        // assign the value of (j+1)th element to the jth element
        message[j] = message[j + 1];
      }
      message[j] = '\0';
    }
  }
}

char *copy(const char *s) {
  int len = printf("You entered: %s\n", s) - 1;
  char *a = malloc(len + 1);
  if (a == NULL) {
    perror("malloc failed");
    return NULL;
  }

  char *c = a;
  while (*s != '\0') {
    *c = *s;
    s++;
    c++;
  }

  *c = '\0';
  return a;
}

int main() {
  char *m;

  printf("input string : ");
  scanf("%s", m);

  char *c = copy(m);

  to_lower(m);
  printf("To lower case: %s\n", m);

  to_upper(m);
  printf("To upper case: %s\n", m);

  just_alphabet(m);
  printf("To alphabet case: %s\n", m);

  just_number(c);
  printf("To number case: %s\n", c);

  return 0;
}