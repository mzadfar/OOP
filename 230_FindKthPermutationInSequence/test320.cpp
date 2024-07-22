#include <bits/stdc++.h>
using namespace std;

// recursive function to generate all
// possible permutations of a string
void generate_permutations(string &str, int idx, vector<string> &result) {
  // base case
  if (idx == str.size()) {
    result.push_back(str);
    return;
  }

  // traverse string from idx to end
  for (int i = idx; i < str.size(); i++) {
    swap(str[i], str[idx]);
    generate_permutations(str, idx + 1, result);
    swap(str[i], str[idx]);
  }
}

// Function to find the
// kth permutation of n numbers
string findKthPermutation(int n, int k) {
  string str = "";
  vector<string> result;

  // Insert all natural number
  // upto n in string
  for (int i = 1; i <= n; i++) {
    str.push_back(i + '0');
  }

  generate_permutations(str, 0, result);
  // sort the generated permutations
  sort(result.begin(), result.end());

  // make k 0-based indexed to point to kth sequence
  return result[k - 1];
}

// Driver code
int main() {
  int n = 3, k = 4;

  // function call
  string kth_perm_seq = findKthPermutation(n, k);
  cout << kth_perm_seq << endl;

  return 0;
}
