#include <bits/stdc++.h>
#define MAXN 1048577
using namespace std;

int n, x;
int k = 1, m, p;
int ans[MAXN+5];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) k *= 2;
  if (x >= k) {
    cout << k-1 << endl;
    for (int i = 1; i <= k-1; i++) {
      m = 1;
      while (!(i & m)) m*=2;
      ans[i] = m*2-1;
      cout << ans[i] << " ";
    }
    cout << endl; 
  } else {
    k /= 2;
    p = 1;
    while (!(x & p)) p*=2;
    cout << k-1 << endl;
    for (int i = 1; i <= k-1; i++) {
      m = 1;
      while (!(i & m)) m*=2;
      ans[i] = (m*2-1);
      if (ans[i] & p) {
        ans[i] ^= p;
        ans[i] ^= k;
      }
      cout << ans[i] << " ";
    }
    cout << endl; 
  }
}
