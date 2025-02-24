/**
 * @file test2.cpp
 * @author M. Z.
 * @brief Intersection of 3 sorted arrays: Input: 3 sorted arrays
 Output: a sorted array of common elements among 3 input arrays
 * @version 0.1
 * @date 2024-08-03
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n1, n2, n3, i;
  cout << "What is the lenngth of arr1: \n";
  cin >> n1;
  cout << "What is the lenngth of arr2: \n";
  cin >> n2;
  cout << "What is the lenngth of arr3: \n";
  cin >> n3;

  int *arr1 = new int[n1];
  int *arr2 = new int[n2];
  int *arr3 = new int[n3];

  printf("Enter %d numbers for arr1: \n", n1);
  for (i = 0; i < n1; i++) {
    cin >> arr1[i];
  }
  printf("Enter %d numbers for arr2: \n", n2);
  for (i = 0; i < n2; i++) {
    cin >> arr2[i];
  }
  printf("Enter %d numbers for arr3: \n", n3);
  for (i = 0; i < n3; i++) {
    cin >> arr3[i];
  }

  printf("\nYou entered %d numbers for arr1: \n", n1);
  for (i = 0; i < n1; i++) {
    cout << arr1[i] << " ";
  }

  printf("\nYou entered %d numbers for arr2: \n", n2);
  for (i = 0; i < n1; i++) {
    cout << arr2[i] << " ";
  }

  printf("\nYou entered %d numbers for arr3: \n", n3);
  for (i = 0; i < n1; i++) {
    cout << arr3[i] << " ";
  }

  int x, x1 = 0;
  int y, y1 = 0;
  int z, z1 = 0;
  int arr[n1];
  i = 0;

  while ((x1 != n1) && (y1 != n2) && (z1 != n3)) {
    x = arr1[x1];
    y = arr2[y1];
    z = arr3[z1];

    if ((x == y) && (y == z)) {
      arr[i] = x;
      i++;
      x1++;
      y1++;
      z1++;
    } else if ((x <= y) && (x <= z)) {
      x1++;
    } else if ((y <= x) && (y <= z)) {
      y1++;
    } else {
      z1++;
    }
  }

  printf("\nResult is: \n");
  for (int j = 0; j < i; j++) {
    cout << arr[j] << " ";
  }
  cout << "\n";

  delete arr1;
  delete arr2;
  delete arr3;

  return 0;
}