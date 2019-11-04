#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAXN 200
#define INF 1e9
using namespace std;

int t, n, m;
int a[MAXN+2];
int dp[MAXN+2][MAXN+2];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dp[i][i] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int l = 0, r = i; r < n; l++, r++) {
        dp[l][r] = INF;
        for (int k = l; k < r; k++) {
          dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]-(a[l]==a[r]));
        }
      }
    }
    cout << dp[0][n-1] << '\n';
  }
  return 0;
}