/**
 * @file test02.cpp
 * @author M. Z.
 * @brief Maximum value of all subarrays:Time complexity O(n^2)
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <queue>

using namespace std;

int MaximumSumSubarray(int *arr, int n);

int main() {
  int arr[] = {3, -2, 5, -1, 4};
  cout << MaximumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
  return 0;
}

int MaximumSumSubarray(int *arr, int n) {
  int ans = arr[0], sum = 0, i;

  for (i = 1; i < n; i++) {
    ans = max(ans, arr[i]);
  }

  if (ans < 0) {
    return ans;
  }

  ans = 0;

  for (i = 0; i < n; i++) {
    if ((sum + arr[i]) > 0) {
      sum += arr[i];
    } else {
      sum = 0;
    }
    ans = max(ans, sum);
  }
  return ans;
}