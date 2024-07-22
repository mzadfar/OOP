/*Linked list: Balanced parantheses using stack*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, i, j, k = 0;
  cout << "What is the size of array: \n";
  cin >> n;

  int *arr = new int[n];
  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (i = 0; i < (n - 1); i++) {
    for (j = (i + 1); j < n; j++) {
      if (arr[i] == arr[j]) {
        k++;
      }
    }
  }

  cout << "Good pairs: " << k << "\n";
  delete arr;
}
