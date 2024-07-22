#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

int BulbSwitch(int numberOfBulbs, int numberOfVariousSwitch);

int main() {
  int numberOfBulbs = 100;
  int numberOfVariousSwitch = 4;
  cout << BulbSwitch(numberOfBulbs, numberOfVariousSwitch) << "\n";
  return 0;
}

int BulbSwitch(int numberOfBulbs, int numberOfVariousSwitch) {
  int res;
  if (numberOfBulbs == 1) {
    res = 2;
  }
  if (numberOfBulbs == 2) {
    if (numberOfVariousSwitch == 1) {
      res = 3;
    } else {
      res = 4;
    }
  }
  if (numberOfBulbs >= 2) {
    if (numberOfVariousSwitch == 1) {
      res = 4;
    } else if (numberOfVariousSwitch == 2) {
      res = 7;
    } else {
      res = 8;
    }
  }
  return res;
}
