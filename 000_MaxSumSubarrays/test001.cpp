/**
 * @file test001.cpp
 * @author M. Z.
 * @brief Maximum value of all possible subarrays
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

  for (startIndex = 0; startIndex < n; startIndex++) {
    int sum = 0;
    for (subArraySize = 1; subArraySize <= n; subArraySize++) {
      if ((startIndex + subArraySize) > n) {
        break;
      }
      sum += arr[startIndex + subArraySize - 1];
      ans = max(ans, sum);
    }
  }
  return ans;
}