#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, i, j;
  cout << "What is the size of array: \n";
  cin >> n;

  int *arr = new int[n];
  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<int, int> mp;

  for (i = 0; i < n; i++)
    mp[arr[i]]++;

  // for (auto it = mp.begin(); it != mp.end(); it++) {
  //   cout << it->first << " occurs " << it->second << " times\n";
  // }

  cout << "Frequency of number is: ";
  for (i = 0; i < mp.size(); i++) {
    cout << mp[arr[i]] << " ";
  }

  cout << "\n";

  delete arr;
}
