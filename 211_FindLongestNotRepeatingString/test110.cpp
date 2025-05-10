#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

static int LongestString(string targetExp);
int main() {
  string targetExp;
  cout << "Enter target expression: ";
  cin >> targetExp;

  cout << "The result is: " << LongestString(targetExp) << "\n";
}

static int LongestString(string targetExp) {
  // Creating a set to store the last positions
  // of occurrence
  map<char, int> seen;
  int maximum_length = 0;

  // Starting the initial point of window to index 0
  int start = 0;

  for (int end = 0; end < targetExp.length(); end++) {

    // Checking if we have already seen the element or
    // not
    if (seen.find(targetExp[end]) != seen.end()) {

      // If we have seen the number, move the start
      // pointer to position after the last occurrence
      start = max(start, seen[targetExp[end]] + 1);
    }

    // Updating the last seen value of the character
    seen[targetExp[end]] = end;
    maximum_length = max(maximum_length, end - start + 1);
  }
  return maximum_length;
}