#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Returns number of pairs in arr[0..n-1]
// with sum equal to 'sum'
void printPairs(int arr[], int n, int sum) {
  int count = 0; // Initialize result
  set<pair<int, int>> dup;
  // Consider all possible pairs and check
  // their sums
  cout << "Desired pairs are: \n";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == sum) {
        if (dup.find({arr[i], arr[j]}) == dup.end() &&
            dup.find({arr[j], arr[i]}) == dup.end()) {
          cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
          dup.insert({arr[i], arr[j]});
        }
      }
    }
  }
}

// Driver function to test the above function
int main() {
  int n, i, sum;
  cout << "What is the size of array: \n";
  cin >> n;

  int *arr = new int[n];
  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "What is the desired sum: \n";
  cin >> sum;

  printPairs(arr, n, sum);

  delete arr;
  return 0;
}