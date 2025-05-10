#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

void shuffle(int array[], int length);

int main() {
  int cards[DECK_SIZE];

  for (int i = 0; i < DECK_SIZE; i++) {
    cards[i] = i + 1;
  }

  shuffle(cards, DECK_SIZE);

  for (int i = 0; i < DECK_SIZE; i++) {
    printf("cards[%d] = %d\n", i, cards[i]);
  }
  return 0;
}

void shuffle(int array[], int length) {
  srand(time(NULL));

  for (int i = 0; i < length; i++) {
    int swapIndex = rand() % length;
    int temp = array[i];
    array[i] = array[swapIndex];
    array[swapIndex] = temp;
  }
}