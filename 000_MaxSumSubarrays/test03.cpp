/* Maimum value of all possible subarrays*/
#include <climits>
#include <iostream>

using namespace std;

int MaimumSumSubarray(int *arr, int n);

int main() {
  int arr[] = {3, -2, 5, -1};
  cout << MaimumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
  return 0;
}

int MaimumSumSubarray(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  }
  int i, m = n / 2;
  int leftMSS = MaimumSumSubarray(arr, m);
  int rightMSS = MaimumSumSubarray(arr + m, n - m);
  int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
  for (i = m; i < n; i++) {
    sum += arr[i];
    rightSum = max(rightSum, sum);
  }
  sum = 0;
  for (i = m - 1; i >= 0; i--) {
    sum += arr[i];
    leftSum = max(leftSum, sum);
  }
  int ans = max(leftMSS, rightMSS);
  return max(ans, leftSum + rightSum);
}