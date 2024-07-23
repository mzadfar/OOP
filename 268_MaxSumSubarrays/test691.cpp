#include <iostream>
#include <vector>

using namespace std;

int max_subarray(int n, vector<int> arr) {
  int max = arr[0];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (max < sum) {
      max = sum;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  return max;
}

int main() {
  int n;
  cout << "Enter the length of array: \n";
  cin >> n;

  cout << "Enter " << n << "elements of array: \n";
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  // vector<int> arr = {3, 4, -8, 1, 2, 5, -1, 7, -20, 9};
  // int n = arr.size();

  cout << "The response is: " << max_subarray(n, arr) << endl;
  return 0;
}
