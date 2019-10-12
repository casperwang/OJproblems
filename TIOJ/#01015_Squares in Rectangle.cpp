#include <bits/stdc++.h>
#define int long long
using namespace std;

int m, n, ans;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> m >> n) {
    if (!m && !n) return 0;
    if (m > n) swap(n, m);
    // m*n +(m-1)*(n-1) + (m-2)*(n-2)...
    cout << m*n*m - (m+n)*(m-1)*m/2 + (m-1)*m*(2*m-1)/6 << endl;
  }
  return 0;
}