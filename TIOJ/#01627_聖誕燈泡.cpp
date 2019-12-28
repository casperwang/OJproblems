#include <bits/stdc++.h>
#define MAXN 5000000
using namespace std;
 
int n, T, q, tmp;
int t[MAXN+5];
int a[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> T >> q) {
    for (int i = 0; i <= T; i++)
      t[i] = a[i] = 0;
    for (int i = 0; i < n; i++)
      cin >> tmp, t[tmp]++;
    for (int i = 1; i <= T; i++) {
      for (int j = 0, k = 1; j < T; j += i, k = -k) {
        a[j] += k*t[i];
      }
    }
    for (int i = 1; i <= T; i++)
      a[i] += a[i-1];
    for (int i = 0; i < q; i++)
      cin >> tmp, cout << a[tmp] << '\n';
    cout << '\n';
  }
}