/**
 * @file test000.cpp
 * @author M. Z.
 * @brief Maximum value of all possible subarrays; Time complexity O(n^2)
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
  cout << "Maximum vaue of all subarrays is "
       << MaximumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
  return 0;
}

int MaximumSumSubarray(int *arr, int n) {
  int ans = INT_MIN, startIndex, subArraySize;

  for (subArraySize = 1; subArraySize <= n; subArraySize++) {
    for (startIndex = 0; startIndex < n; startIndex++) {
      if ((startIndex + subArraySize) > n) {
        break;
      }
      int sum = 0;
      for (int i = 0; i < (startIndex + subArraySize); i++) {
        sum += arr[i];
      }
      ans = max(ans, sum);
    }
  }
  return ans;
}