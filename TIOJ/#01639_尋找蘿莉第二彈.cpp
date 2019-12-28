#include <bits/stdc++.h>
#define MAXN 4000
#define int long long
#define INF 1e18
using namespace std;
 
int n;
int p[MAXN+5];
int pre[MAXN+5];
int dp[MAXN+5][MAXN+5];
signed t[MAXN+5][MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i], pre[i] = (i?pre[i-1]:0) + p[i];
  for (int i = n-1; i >= 0; i--) {
    for (int j = i+1; j <= n; j++) {
      if (i+1 == j) dp[i][j] = 0, t[i][j] = i;
      else {
        dp[i][j] = INF;
        for (int k = t[i][j-1]; k <= t[i+1][j]; k++) {
          if (dp[i][k]+dp[k][j] < dp[i][j]) {
            t[i][j] = k;
            dp[i][j] = dp[i][k]+dp[k][j];
          }
        }
        dp[i][j] += pre[j-1]-pre[i-1];
      }
    }
  }
  cout << dp[0][n] << "\n";
}