#include <climits>
#include <iostream>

using namespace std;

int main() {
  int n, i, j;
  cout << "What is the half size of array: \n";
  cin >> n;

  int *arr = new int[2 * n];
  int *res = new int[2 * n];
  printf("Enter %d numbers for array: \n", 2 * n);
  for (i = 0; i < (2 * n); i++) {
    cin >> arr[i];
  }

  j = 0;
  for (i = 0; i < (2 * n); i++) {
    if ((i % 2) == 0) {
      res[i] = arr[j];
      j++;
    } else {
      res[i] = arr[n + j - 1];
    }
  }

  cout << "The response is: ";
  for (i = 0; i < (2 * n); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  delete arr;
  delete res;

  return 0;
}