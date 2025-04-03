/**
 * @file test003.c
 * @author M. Z.
 * @brief Maximum value of all subarrays
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int MaximumSumSubarray(int *arr, int sizeArr);

int main(void) {
  int arr[] = {3, -2, 5, -1, 4};
  printf("Size of array is %d, and maximum vaue of all subarrays is %d\n",
         sizeof(arr) / sizeof(arr[0]),
         MaximumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])));
}

int MaximumSumSubarray(int *arr, int sizeArr) {
  int ret;

  if (sizeArr == 1) {
    return arr[0];
  }

  int i, m = sizeArr / 2;
  int leftMaxSumSubarr = MaximumSumSubarray(arr, m);
  int rightMaxSumSubarr = MaximumSumSubarray(arr + m, sizeArr - m);
  int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;

  for (i = m; i < sizeArr; i++) {
    sum += arr[i];
    rightSum = sum > rightSum ? sum : rightSum;
  }

  sum = 0;
  for (i = m - 1; i >= 0; i--) {
    sum += arr[i];
    leftSum = sum > leftSum ? sum : leftSum;
  }

  ret = leftMaxSumSubarr > rightMaxSumSubarr ? leftMaxSumSubarr
                                             : rightMaxSumSubarr;
  ret = ret > (leftSum + rightSum) ? ret : (leftSum + rightSum);

  return ret;
}