/**
 * @file test010.cpp
 * @author M. Z.
 * @brief Sort an array by splitting it into 2 arrays, and merge it back into 1
 * array
 * @version 0.1
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

void Merge(int *arr, int *leftArr, int leftArrSize, int *rightArr,
           int rightArrSize);
void MergeSort(int *arr, int arrSize);

int main() {
  int arr[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};

  int numberOfElement = sizeof(arr) / sizeof(arr[0]);

  MergeSort(arr, numberOfElement);
  cout << "Sorted array: ";
  for (int i = 0; i < numberOfElement; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void Merge(int *arr, int *leftArr, int leftArrSize, int *rightArr,
           int rightArrSize) {
  int i, j, k;
  i = j = k = 0;
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

  leftArr = new int[arrMidSize];
  rightArr = new int[arrSize - arrMidSize];

  for (int i = 0; i < arrMidSize; i++) {
    leftArr[i] = arr[i];
  }
  for (int i = arrMidSize; i < arrSize; i++) {
    rightArr[i - arrMidSize] = arr[i];
  }

  MergeSort(leftArr, arrMidSize);
  MergeSort(rightArr, arrSize - arrMidSize);
  Merge(arr, leftArr, arrMidSize, rightArr, arrSize - arrMidSize);
  delete leftArr;
  delete rightArr;
}