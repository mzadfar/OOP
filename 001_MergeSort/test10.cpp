/* Merge 2 arrays and sort the result */
#include <iostream>
#include <queue>

using namespace std;

void Merge(int *arr, int *arr1, int leftCount, int *arr2, int rightCount);
void MergeSort(int *arr, int n);

int main() {
  int arr[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
  int numberOfElement;

  numberOfElement = sizeof(arr) / sizeof(arr[0]);

  MergeSort(arr, numberOfElement);

  for (int i = 0; i < numberOfElement; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void Merge(int *arr, int *arr1, int leftCount, int *arr2, int rightCount) {
  int i, j, k;
  i = j = k = 0;
  while ((i < leftCount) && (j < rightCount)) {
    if (arr1[i] < arr2[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }
  while (i < leftCount) {
    arr[k++] = arr1[i++];
  }
  while (j < rightCount) {
    arr[k++] = arr2[j++];
  }
}

void MergeSort(int *arr, int n) {
  int mid, *arr1, *arr2;
  if (n < 2) {
    return;
  }

  mid = n / 2;

  arr1 = new int[mid];
  arr2 = new int[n - mid];

  for (int i = 0; i < mid; i++) {
    arr1[i] = arr[i];
  }
  for (int i = mid; i < n; i++) {
    arr2[i - mid] = arr[i];
  }

  MergeSort(arr1, mid);
  MergeSort(arr2, n - mid);
  Merge(arr, arr1, mid, arr2, n - mid);
  delete arr1;
  delete arr2;
}