
/*Problem Details:
This problem was asked by Nest.
Create a basic sentence checker that takes in a stream of characters and
determines whether they form valid sentences. If a sentence is valid, the
program should print it out. We can consider a sentence valid if it conforms to
the following rules: The sentence must start with a capital letter, followed by
a lowercase letter or a space. All other characters must be lowercase letters,
separators (,,;,:) or terminal marks (.,?,!,‽). There must be a single space
between each word. The sentence must end with a terminal mark immediately
following a word.

Solution:
STATES
0: Begin  1: Uppercase    2: Lowercase    3: Space    4: Separator
import string
*/
#include <stdio.h>
#include <string.h>

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define SPACE ' '
#define SEP ",;:"
#define TERM ".?!‽"

void check_sentences(const char *stream) {
  int state = 0;      // init state
  char sentence[256]; // assuming max sentence length
  int index = 0;

  while (*stream) {
    char char_current = *stream++;
    sentence[index++] = char_current;
    sentence[index] = '\0'; // null-terminate the string

    if (strchr(UPPER, char_current) && state == 0) {
      state = 1;
    } else if (strchr(LOWER, char_current) &&
               (state == 1 || state == 2 || state == 3)) {
      state = 2;
    } else if (char_current == SPACE &&
               (state == 1 || state == 2 || state == 4)) {
      state = 3;
    } else if (strchr(SEP, char_current) && state == 2) {
      state = 4;
    } else if (strchr(TERM, char_current) && state == 2) {
      printf("%s\n", sentence);
      state = 0;
      index = 0; // reset index for the next sentence
    } else {
      index = 0; // reset index for the next sentence
    }
  }
}

int main() {
  const char *stream = "Amin Hasanzadeh!";
  check_sentences(stream);
  return 0;
}
