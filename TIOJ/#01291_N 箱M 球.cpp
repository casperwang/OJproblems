#include <bits/stdc++.h>
#define MAXN 200
#define MOD 1000000
#define int long long
using namespace std;

int n, m, ans;
int arr[MAXN+5][MAXN+5];

signed main() {
  while (cin >> n >> m) {
    if (!n && !m) return 0;
    for (int i = 1; i <= max(n, m); i++) {
      arr[i][1] = 1;
    }
    ans = 1;
    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        arr[i][j] = (arr[i-1][j]*j + arr[i-1][j-1]) % MOD;
        if (i == m) ans = (ans + arr[i][j]) % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}