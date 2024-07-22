#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> a;

  for (int i = 0; i < n; i++) {
    a.push_back(make_pair(arr[i], i));
  }

  for (int j = 0; j < x; j++) {
    pair<int, int> m = {-1, -1};
    int p = -1;
    vector<pair<int, int>> new_list;
    for (int i = 0; i < min(x, static_cast<int>(a.size())); i++) {
      pair<int, int> y = a[0];
      a.erase(a.begin());
      if (m.first < y.first) {
        m.first = y.first;
        m.second = y.second;
        p = i;
      }
      y.first = max(y.first - 1, 0);
      new_list.push_back(y);
    }
    cout << m.second + 1 << " ";
    new_list.erase(new_list.begin() + p);
    a.insert(a.end(), new_list.begin(), new_list.end());
  }
  cout << endl;
  return 0;
}
/*
n,x = map(int, raw_input().split())
arr = map(int, raw_input().split())
a=[]

for i in range(n):
  a.append([arr[i],i])

for _ in range(x):
  m = [-1,-1]
  p=-1
  new=[]
  for i in range(min(x,len(a))):
    y = a.pop(0)
    if m[0] < y[0]:
      m[0],m[1]=y[0],y[1]
      p=i
    y[0]=max(y[0]-1,0)
    new.append(y)
  print (m[1]+1),
  new.pop(p)
  a=a+new
  */