#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  int n, i, sum = 0;
  cout << "What is the max number in array: \n";
  cin >> n;

  int *arr = new int[n];

  printf("Enter %d numbers for array: \n", n - 1);
  for (i = 0; i < n - 1; i++) {
    cin >> arr[i];
    sum = sum + arr[i];
  }

  printf("\nMissing number is: %d\n", ((n * (n + 1) / 2) - sum));

  delete arr;

  return 0;
}