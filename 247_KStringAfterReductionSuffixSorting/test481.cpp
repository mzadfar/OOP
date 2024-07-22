#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(char *arr[], int p, int q, int r);
void mergeSort(char *arr[], int l, int r);

int main() {
  int num;
  char str[25];
  char *suffix[25];
  cout << "Insert a string and with an space afterward : \n";
  scanf("%s", str);
  char *s;
  s = str;
  int l = strlen(str);
  cout << "With an space distance insert a number smaller than number of "
          "letter in the "
          "string : \n";
  scanf("%d", &num);
  for (int i = 0; i < l; i++) {
    suffix[i] = s;
    s += 1;
  }

  mergeSort(suffix, 0, l - 1);
  printf("String %s is located at position %d \n", suffix[num - 1], num);
  return 0;
}

// Merge two subarrays L and M into arr
void merge(char *arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  char *L[n1];
  char *M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(char *arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}