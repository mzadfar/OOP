#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, i, j;
  cout << "What is the size of array: \n";
  cin >> n;

  int *arr = new int[n];
  int *res = new int[n];
  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    res[i] = 1;
  }

  for (i = 0; i < (n - 1); i++) {
    for (j = (i + 1); j < n; j++) {
      if (arr[i] == arr[j]) {
        if (res[j] != -1) {
          res[i]++;
          res[j] = -1;
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (res[i] != -1) {
      cout << res[i] << " ";
    }
  }

  cout << "\n";

  delete arr;
  delete res;
}
