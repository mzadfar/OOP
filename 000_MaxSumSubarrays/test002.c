/**
 * @file test002.c
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
  int ret = arr[0], sum = 0, i;

  for (i = 0; i < sizeArr; i++) {
    ret = ret > arr[i] ? ret : arr[i];
  }

  if (ret < 0) {
    return ret;
  }

  ret = 0;

  for (i = 0; i < sizeArr; i++) {
    if ((sum + arr[i]) > 0) {
      sum += arr[i];
    } else {
      sum = 0;
    }
    ret = ret > sum ? ret : sum;
  }
  return ret;
}