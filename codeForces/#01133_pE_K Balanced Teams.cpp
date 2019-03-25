#include <bits/stdc++.h>
#define MAXN 5000+5
using namespace std;

int n, k, ans;
int num[MAXN], pre[MAXN];
int dp[MAXN][MAXN];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  sort(num+1, num+n+1);
  for (int i = 1; i <= n; i++) {
    int pos = i;
    while (pos && num[i] - num[pos] <= 5) pos--;
    pre[i] = pos;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[j][i] = max(dp[pre[j]][i-1] + (j - pre[j]), dp[j-1][i]);
      ans = max(ans, dp[j][i]);
    }
  }
  cout << ans << endl;
} 
