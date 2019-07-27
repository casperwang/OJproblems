#include <bits/stdc++.h>
#define int long long
#define MAXN 500
#define MOD 998244353
using namespace std;

int n, m;
int num[MAXN+5];
int dp[MAXN+5][MAXN+5];

int f(int l, int r) {
  if (dp[l][r]) return dp[l][r];
  if (l >= r) return 1;
  int ans = 1, m = MAXN+5, k = 0;
  for (int i = l; i <= r; i++) {
    if (num[i] < m) {
      m = num[i];
      k = i;
    }
  }
  int L = f(l, k-1), R = f(k+1, r);
  for (int i = l; i < k; i++) {
    L += f(l, i-1) * f(i, k-1);
    L %= MOD;
  }
  for (int i = k+1; i <= r; i++) {
    R += f(k+1, i) * f(i+1, r);
    R %= MOD;
  }
  //cout << l << ", " << r << " : " << L*R << endl;
  dp[l][r] = (L*R) % MOD;
  return (L*R) % MOD;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  cout << f(1, n) << endl;
  return 0;
}
