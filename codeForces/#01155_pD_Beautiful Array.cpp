#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

long long int n, x, num[MAXN+5], ans;
long long int bef_dp[MAXN+5], now_dp[MAXN+5], aft_dp[MAXN+5];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  bef_dp[0] = max(num[0], (long long)0);
  now_dp[0] = max(x * num[0], (long long)0);
  aft_dp[0] = max(num[0], (long long)0);
  ans = max(max(ans, bef_dp[0]), max(now_dp[0], aft_dp[0]));
  for (int i = 1; i < n; i++) {
    bef_dp[i] = max(num[i]+bef_dp[i-1], num[i]);
    bef_dp[i] = max(bef_dp[i], (long long)0);
    now_dp[i] = max(max(bef_dp[i-1]+num[i]*x, now_dp[i-1]+num[i]*x), num[i]*x);
    now_dp[i] = max(now_dp[i], (long long)0);
    aft_dp[i] = max(now_dp[i-1]+num[i], aft_dp[i-1]+num[i]);
    aft_dp[i] = max(aft_dp[i], (long long)0);
    ans = max(max(ans, bef_dp[i]), max(now_dp[i], aft_dp[i]));
  }
  cout << ans << endl;
  return 0;
}
