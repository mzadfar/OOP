#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n;
  cout << "Enter the length of array: \n";
  cin >> n;
  cout << "Enter " << n << " elements of array: \n";
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {

    cin >> arr[i];
  }

  vector<int> x(n, 0);

  vector<int> y(n, 0);

  stack<pair<int, int>> stack;

  cout << "The response is: \n";
  for (int i = n - 1; i >= 0; --i) {
    while (!stack.empty() && stack.top().first <= arr[i]) {
      stack.pop();
    }
    if (!stack.empty()) {
      y[i] = stack.top().second + 1;
    } else {
      y[i] = -1;
    }
    stack.push({arr[i], i});
  }
  stack = ::stack<pair<int, int>>();

  for (int i = 0; i < n; ++i) {
    while (!stack.empty() && stack.top().first <= arr[i]) {
      stack.pop();
    }
    if (!stack.empty()) {
      x[i] = stack.top().second + 1;
    } else {
      x[i] = -1;
    }
    stack.push({arr[i], i});

    cout << x[i] + y[i] << " ";
  }
  cout << endl;

  return 0;
}