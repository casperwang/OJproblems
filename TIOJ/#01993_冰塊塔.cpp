#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
using namespace std;

int t, n, h, ans, s;
int arr[MAXN+5][3];
bool dp[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> h;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, ans = s = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
      sort(arr[i], arr[i]+3);
      s += arr[i][0];
      arr[i][1] -= arr[i][0];
      arr[i][2] -= arr[i][0];
    }
    h -= s;
    if (h < 0) {
      cout << "no solution\n";
      continue;
    }
    for (int j = 0; j < n; j++) {
      for (int i = h; i >= 0; i--) {
        if (!dp[i]) continue;
        if (i+arr[j][1] <= h) dp[i+arr[j][1]] = 1;
        if (i+arr[j][2] <= h) dp[i+arr[j][2]] = 1;
      }
    }
    for (int i = h; i >= 0; i--) {
      ans = max(ans, dp[i]*i);
    }
    cout << ans+s << '\n';
  }
}