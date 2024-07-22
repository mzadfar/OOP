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

  for (int i = 0; i < goldenExp.length(); i++) {
    result += count(targetExp.begin(), targetExp.end(), goldenExp[i]);
  }
  return result;
}