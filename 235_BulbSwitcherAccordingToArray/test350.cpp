#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

int BulbSwitch(int numberOfBulbs, int *arr);

int main() {
  int numberOfBulbs = 5;
  int arr[] = {2, 1, 4, 3, 5};
  cout << BulbSwitch(numberOfBulbs, arr) << "\n";
  return 0;
}

int BulbSwitch(int numberOfBulbs, int *arr) {
  int res = 0, maxOn = 0;
  for (int i = 0; i < numberOfBulbs; i++) {
    maxOn = max(maxOn, arr[i]);
    if ((i + 1) == maxOn) {
      res++;
    }
  }
  return res;
}
