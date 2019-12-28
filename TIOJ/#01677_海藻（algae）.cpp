#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
 
int t;
int n, k;
int dp[100+5];

signed f(int n, int k) {
  if (k > dp[n]) return -1;
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (k <= dp[n-2]) {
    return f(n-2, k);
  } else {
    return f(n-1, k-dp[n-2]);
  }
}
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  dp[1] = 1;
  for (int i = 2; i <= 100; i++)
    dp[i] = dp[i-1] + dp[i-2];
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << f(n, k) << '\n';
  }
  return 0;
}