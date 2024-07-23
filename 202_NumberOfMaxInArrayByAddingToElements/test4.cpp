#include <climits>
#include <iostream>

using namespace std;

int main() {
  int n, m, i, max = INT_MIN;
  cout << "What is the max number in array: \n";
  cin >> n;

  int *arr = new int[n];
  int *res = new int[n];

  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  cout << "What is the exra number to spread in array: \n";
  cin >> m;

  for (i = 0; i < n; i++) {
    if ((arr[i] + m) >= max) {
      res[i] = 1;
    } else {
      res[i] = 0;
    }
  }

  cout << "The response is: ";
  for (i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  delete arr;
  delete res;

  return 0;
}