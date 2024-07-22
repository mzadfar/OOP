#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(char *arr[], int p, int q, int r);
void mergeSort(char *array[], int const begin, int const end);

int main() {
  int num;
  char str[25];
  char *suffix[25];
  scanf("%s", str);
  char *s;
  s = str;
  int l = strlen(str);
  scanf("%d", &num);
  for (int i = 0; i < l; i++) {
    suffix[i] = s;
    s += 1;
    cout << suffix[i] << endl;
  }
  cout << endl;
  mergeSort(suffix, 0, l - 1);
  for (int i = 0; i < l; i++) {
    cout << suffix[i] << endl;
  }
  printf("%s\n", suffix[num - 1]);

  return 0;
}

void merge(char *array[], int const left, int const mid, int const right) {
  auto const subArrayOne = mid - left + 1;
  auto const subArrayTwo = right - mid;

  // Create temp arrays
  auto *leftArray = new char *[subArrayOne],
       *rightArray = new char *[subArrayTwo];

  // Copy data to temp arrays leftArray[]
  // and rightArray[]
  for (auto i = 0; i < subArrayOne; i++)
    leftArray[i] = array[left + i];
  for (auto j = 0; j < subArrayTwo; j++)
    rightArray[j] = array[mid + 1 + j];

  // Initial index of first sub-array
  // Initial index of second sub-array
  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;

  // Initial index of merged array
  int indexOfMergedArray = left;

  // Merge the temp arrays back into
  // array[left..right]
  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }

  // Copy the remaining elements of
  // left[], if there are any
  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }

  // Copy the remaining elements of
  // right[], if there are any
  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(char *array[], int const begin, int const end) {
  // Returns recursively
  if (begin >= end)
    return;

  auto mid = begin + (end - begin) / 2;
  mergeSort(array, begin, mid);
  mergeSort(array, mid + 1, end);
  merge(array, begin, mid, end);
}