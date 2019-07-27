#include <bits/stdc++.h>
#define int long long
#define MAXN 200000
#define MOD 998244353
using namespace std;

int n, a, b;
int degree[MAXN+5];
int num[MAXN+5];
int ans;

signed main() {
  cin >> n;
  num[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    degree[a]++;
    degree[b]++;
    num[i] = (num[i-1]*i) % MOD; 
  }
  ans = n;
  for (int i = 1; i <= n; i++) {
    ans = (ans*num[degree[i]]) % MOD;
  }
  cout << ans << endl;
  return 0;
}
