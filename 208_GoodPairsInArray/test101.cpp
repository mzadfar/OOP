#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

/*
Basic std::map Member Functions

Some basic functions associated with std::map are:

    begin() – Returns an iterator to the first element in the map.
    end() – Returns an iterator to the theoretical element that follows the last
element in the map. size() – Returns the number of elements in the map.
    max_size() – Returns the maximum number of elements that the map can hold.
    empty() – Returns whether the map is empty.
    pair insert(keyvalue, mapvalue) – Adds a new element to the map.
    erase(iterator position) – Removes the element at the position pointed by
the iterator. erase(const g)– Removes the key-value ‘g’ from the map. clear() –
Removes all the elements from the map.
*/
using namespace std;

int main() {
  int n, i, j, k = 0;
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

  for (i = 0; i < mp.size(); i++) {
    k += mp[arr[i]] * (mp[arr[i]] - 1) / 2;
  }

  cout << "Good pairs: " << k << "\n";

  delete arr;
}
