#include <bits/stdc++.h>
#define MAXN 1000000
#define MOD 1000000007
#define int long long
using namespace std;

int t, n, dp[MAXN+5];
int inv[MAXN+5], arr[MAXN/10+5];
int N;
inline int fmod(int v){
  return v >= MOD ? v % MOD : v;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> arr[i], N = max(N, arr[i]/2+1);
  }
  inv[1] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = fmod((MOD - MOD / i) * inv[MOD % i]);
  }
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] = fmod(dp[i-1] * (i*4-2));
    dp[i] = fmod(dp[i] * inv[i+1]);
  }
  for (int i = 0; i < t; i++) {
    cout << dp[(arr[i]>>1)] << '\n';
  }
  return 0;
}