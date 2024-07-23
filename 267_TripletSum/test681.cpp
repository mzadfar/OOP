#include <iostream>
#include <map>
#include <vector>

using namespace std;

int countTriplets(int n, vector<int> arr, int sum) {
  map<int, int> d;
  for (int i = 0; i < n; i++) {
    d[sum - arr[i]] = i;
  }

  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((d.find(arr[i] + arr[j]) != d.end()) && d[arr[i] + arr[j]] != i &&
          d[arr[i] + arr[j]] != j) {
        count++;
        // auto itr = d.find(arr[i] + arr[j]);
        // printf("Triplet is %d, %d, %d\n", arr[i], arr[j], sum - itr->first);
      }
    }
  }

  count = count / 3; // why 3?? why repeating 3 times
  return count;
}

int main() {
  int n;
  cout << "Enter the length of the array: \n";
  cin >> n;
  cout << "Enter the " << n << " elements of the array: \n";
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int sum = 0;
  cout << "Enter the desired sum value for triplet subarray: \n";
  cin >> sum;

  cout << "Number of triplet is: " << countTriplets(n, arr, sum) << endl;

  return 0;
}
