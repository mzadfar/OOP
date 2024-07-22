#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int nCr(int n, int r) {
  if (r > n - r) {
    r = n - r;
  }
  int result = 1;
  for (int i = 0; i < r; ++i) {
    result *= (n - i);
    result /= (i + 1);
  }
  return result;
}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int sb = 0;
    vector<int> pv(30, 0);
    vector<int> vis(30, 0);

    for (int i = 0; i < n; ++i) {
      string b = bitset<32>(arr[i]).to_string();
      int x = b.find('1');
      int j = x;
      while (j >= 0) {
        pv[x - j] += (b[j] - '0') * pow(2, x - j);
        if (b[j] == '1') {
          sb += vis[x - j];
          vis[x - j] = 0;
        }
        j--;
      }
    }

    if (sb < l) {
      cout << "-1" << endl;
      continue;
    }

    sort(pv.rbegin(), pv.rend());

    int res = 1;
    for (int i = 0; i < sb; ++i) {
      if (l <= 0) {
        break;
      }
      if (pv[i] != pv[i + 1]) {
        l--;
      } else {
        int count = 0;
        while (i != sb - 1 && pv[i] == pv[i + 1]) {
          count++;
          i++;
        }
        count++;
        if (l < count) {
          res *= nCr(count, l);
          break;
        }
        l -= count;
      }
    }

    cout << res << endl;
  }

  return 0;
}

for _ in range(input()):
  n,l = map(int, raw_input().split())
  arr = map(int, raw_input().split())
  sb = 0
  pv = [0 for i in range(30)]
  vis = [0 for i in range(30)]
  for i in range(n):
    b = format(arr[i], "b")
    x = len(b)
    j =x-1
    while j>=0
      pv[x-j-1] +=int(b[j])*pow(2,x-j-1)
      if int(b[j]) ==1;
        sb+=vis[x-j-1]
        vis[x-j-1] = 0
      j-=1
  if sb< l:
    print "-1"
    continue
  pv.sort(reverse = True)
  res=1
  for i in range(sb):
    if l<= 0:
      break
    if pv[i] !=pv[i+1]:
      l-=1
    else:
      count=0
      while i!=sb-1 and pv[i]==pv[i+1]:
        count+=1
        i+=1
      count +=1
      if l<count:
        res *=ncr (count,l)
        break
      l-=count
  print res
