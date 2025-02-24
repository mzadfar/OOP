/**
 * @file test10.c
 * @author M. Z.
 * @brief Sort an array by splitting it into 2 arrays, and merge it back into 1
 * @version 0.1
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int *leftArr, int leftArrSize, int *rightArr,
           int rightArrSize);
void MergeSort(int *arr, int arrSize);

int main() {
  int arr[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};

  int numberOfElement = sizeof(arr) / sizeof(arr[0]);

  MergeSort(arr, numberOfElement);
  printf("Sorted array: ");
  for (int i = 0; i < numberOfElement; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void Merge(int *arr, int *leftArr, int leftArrSize, int *rightArr,
           int rightArrSize) {
  int i = 0, j = 0, k = 0;
  while ((i < leftArrSize) && (j < rightArrSize)) {
    if (leftArr[i] < rightArr[j]) {
      arr[k++] = leftArr[i++];
    } else {
      arr[k++] = rightArr[j++];
    }
  }
  while (i < leftArrSize) {
    arr[k++] = leftArr[i++];
  }
  while (j < rightArrSize) {
    arr[k++] = rightArr[j++];
  }
}

void MergeSort(int *arr, int arrSize) {
  int arrMidSize, *leftArr, *rightArr;
  if (arrSize < 2) {
    return;
  }

  arrMidSize = arrSize / 2;

  leftArr = (int *)malloc(arrMidSize * sizeof(int));
  rightArr = (int *)malloc((arrSize - arrMidSize) * sizeof(int));

  for (int i = 0; i < arrMidSize; i++) {
    leftArr[i] = arr[i];
  }
  for (int i = 0; i < (arrSize - arrMidSize); i++) {
    rightArr[i] = arr[i + arrMidSize];
  }

  MergeSort(leftArr, arrMidSize);
  MergeSort(rightArr, arrSize - arrMidSize);
  Merge(arr, leftArr, arrMidSize, rightArr, arrSize - arrMidSize);
  free(leftArr);
  free(rightArr);
}