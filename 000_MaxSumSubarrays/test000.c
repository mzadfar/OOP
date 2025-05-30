/**
 * @file test000.c
 * @author M. Z.
 * @brief Maximum value of all subarrays:Time complexity O(n^2)
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
  int ret = INT_MIN, sum, startIndex, subArrSize;

  for (subArrSize = 1; subArrSize <= sizeArr; subArrSize++) {
    for (startIndex = 0; startIndex < sizeArr; startIndex++) {
      if ((startIndex + subArrSize) > sizeArr) {
        break;
      }
      sum = 0;
      for (int i = 0; i < (startIndex + subArrSize); i++) {
        sum += arr[i];
      }
      ret = sum > ret ? sum : ret;
    }
  }
  return ret;
}