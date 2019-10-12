#include <bits/stdc++.h>
#define MAXN 500
#define int long long
using namespace std;

int n, a[MAXN+5][MAXN+5], b[MAXN+5], ans, sum;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) b[k] = 0;
    for (int j = i; j < n; j++) {
      sum = 0;
      for (int k = 0; k < n; k++) {
        b[k] += a[j][k];
        sum += b[k];
        if (sum < 0) sum = 0;
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
} 

