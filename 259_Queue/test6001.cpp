#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int key) {
  int low = 0;
  int high = arr.size() - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> stack;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int j = 0; j < m; j++) {
      cin >> arr[j];
    }
    stack.push_back(vector<int>(arr.begin() + 1, arr.end()));
  }

  int q;
  cin >> q;
  vector<int> first_min = {stack[0][0]};
  for (int i = 1; i < stack[0].size(); i++) {
    first_min.push_back(min(first_min.back(), stack[0][i]));
  }

  for (int _ = 0; _ < q; _) {
    vector<int> inp;
    for (int i = 0; i < 3; i++) {
      int x;
      cin >> x;
      inp.push_back(x);
    }

    if (inp[0] == 0) {
      stack[inp[1] - 1].pop_back();
      if (inp[1] == 1) {
        first_min.pop_back();
      }
    } else if (inp[0] == 1) {
      stack[inp[1] - 1].push_back(inp[2]);
      if (inp[1] == 1) {
        first_min.push_back(min(first_min.back(), inp[2]));
      }
    } else {
      int chk = 0;
      if (stack[0].empty()) {
        cout << "NO" << endl;
        continue;
      }
      int key = first_min.back();
      for (int i = 1; i < n; i++) {
        if (stack[i].empty() || key > stack[i].back()) {
          chk = 1;
          break;
        }
        key = stack[i][binarySearch(stack[i], key)];
      }
      if (chk == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}