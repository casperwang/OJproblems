#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
using namespace std;
  
int t, n, x;
int d, h, a, b;
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> x;
    a = -INF;
    b = 0;
    for (int j = 0; j < n; j++) {
      cin >> d >> h;
      a = max(a, d-h);
      b = max(b, d);
    }
    if (x-b <= 0) cout << 1 << endl;
    else if (a > 0) cout << (x-b+a-1)/a+1 << endl;
    else cout << -1 << endl;
  }
} 
