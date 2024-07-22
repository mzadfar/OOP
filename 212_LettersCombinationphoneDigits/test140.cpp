#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void letterCombinations(const int number[], int n);
vector<string> letterCombinationsUtil(const int number[], int n,
                                      const string table[]);

int main() {
  int n, i, j;
  cout << "What is the size of array: \n";
  cin >> n;

  int *number = new int[n];
  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> number[i];
  }

  // Function call
  letterCombinations(number, n);
  cout << "\n";
}

// Function to return a vector that contains
// all the generated letter combinations
vector<string> letterCombinationsUtil(const int number[], int n,
                                      const string table[]) {
  // To store the generated letter combinations
  vector<string> list;

  queue<string> q;
  q.push("");

  while (!q.empty()) {
    string s = q.front();
    q.pop();

    // If complete word is generated
    // push it in the list
    if (s.length() == n)
      list.push_back(s);
    else

      // Try all possible letters for current digit
      // in number[]
      for (auto letter : table[number[s.length()]])
        q.push(s + letter);
  }

  // Return the generated list
  return list;
}

// Function that creates the mapping and
// calls letterCombinationsUtil
void letterCombinations(const int number[], int n) {

  // table[i] stores all characters that
  // corresponds to ith digit in phone
  string table[10] = {"0",   "1",   "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

  vector<string> list = letterCombinationsUtil(number, n, table);

  // Print the contents of the vector
  for (auto word : list)
    cout << word << " ";

  return;
}
