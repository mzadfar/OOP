/**
 * @file test003.cpp
 * @author M. Z.
 * @brief Maximum value of all subarrays
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <climits>
#include <iostream>

using namespace std;

int MaximumSumSubarray(int *arr, int n);

int main() {
  int arr[] = {3, -2, 5, -1, 4};
  cout << MaximumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
  return 0;
}

int MaximumSumSubarray(int *arr, int n) {
  if (n == 1) {
    return arr[0];
  }
  int i, m = n / 2;
  int leftMSS = MaximumSumSubarray(arr, m);
  int rightMSS = MaximumSumSubarray(arr + m, n - m);
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