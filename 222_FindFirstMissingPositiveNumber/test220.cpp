#include <bits/stdc++.h>

using namespace std;

int MissingNumber(int *arr, int n);

int main() {
  int arr[] = {7, 2, 0, 1, 3, 5, 2, 4, -6};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << MissingNumber(arr, n) << "\n";
  return 0;
}

int MissingNumber(int *arr, int n) {
  int i, check = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == 1) {
      check++;
    }
    if (arr[i] <= 0) {
      arr[i] = 1;
    }
  }
  if (check == 0) {
    return 1;
  }
  int val;
  for (i = 0; i < n; i++) {
    val = abs(arr[i]) - 1;
    if ((val >= 0) && (val < n)) {
      arr[val] = -abs(arr[val]);
    }
  }
  for (i = 0; i < n; i++) {
    if (arr[i] > 0) {
      return i + 1;
    }
  }
  return n + 1;
}