// Underprogress
#include <iostream>
#include <unordered_set>

using namespace std;

int gen(int n, int row_count, unordered_set<int> col, unordered_set<int> d1,
        unordered_set<int> d2, int count) {
  if (row_count == n) {
    return count + 1;
  }
  for (int j = 0; j < n; ++j) {
    if (col.find(j) != col.end() || d1.find(row_count - j) != d1.end() ||
        d2.find(row_count + j) != d2.end()) {
      continue;
    }
    col.insert(j);
    d1.insert(row_count - j);
    d2.insert(row_count + j);
    count = gen(n, row_count + 1, col, d1, d2, count);
    d2.erase(row_count + j);
    d1.erase(row_count - j);
    col.erase(j);
  }
  return count;
}

int main() {
  int n;

  cin >> n;

  cout << gen(n, 0, unordered_set<int>(), unordered_set<int>(),
              unordered_set<int>(), 0)
       << endl;
  return 0;
}