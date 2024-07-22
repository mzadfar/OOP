#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

static int GoldenChar(string goldenExp, string targetExp);
int main() {
  string goldenExp, targetExp;
  cout << "Enter golden letters: ";
  cin >> goldenExp;

  cout << "Enter target expression: ";
  cin >> targetExp;

  cout << "The result is: " << GoldenChar(goldenExp, targetExp) << "\n";
}

static int GoldenChar(string goldenExp, string targetExp) {
  int result = 0;
  // Convert the strings into sets of characters
  unordered_set<char> set1(goldenExp.begin(), goldenExp.end());

  // Find the intersection of the sets
  for (char c : set1) {
    result += count(targetExp.begin(), targetExp.end(), c);
  }
  return result;
}