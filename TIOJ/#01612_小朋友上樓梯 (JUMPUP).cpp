#include <bits/stdc++.h>
#define MAXN 3000
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, k, x, d;
int ans;
int dp[MAXN+5][2];
pii arr[MAXN+5];
deque <pii> dq;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> x >> d;
  for (int i = 0; i < n; i++)
    cin >> arr[i].ff >> arr[i].ss;
  sort(arr, arr+n);
  for (int i = 0; i < n; i++)
    dp[i][1] = arr[i].ss;
  for (int i = 2; i <= k; i++) {
    while (dq.size()) dq.pop_back();
    dq.push_back(pii(dp[i-2][!(i%2)], i-2));
    for (int j = i-1; j < n; j++) {
      while (arr[j].ff - arr[dq.front().ss].ff > d)
        dq.pop_front();
      dp[j][i%2] = dq.front().ff + arr[j].ss;
      while (dq.size() && dp[j][!(i%2)] >= dq.back().ff)
        dq.pop_back();
      dq.push_back(pii(dp[j][!(i%2)], j));
    }
  }
  for (int i = 0; i < n; i++)
    ans = max(ans, dp[i][k%2]);
  cout << ans << "\n";
}