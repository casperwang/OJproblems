#include <bits/stdc++.h>
#define int long long
#define MOD 1000000009
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
 
int i, n, ans, k;

pii exgcd(int a, int b) {
	if (!b) return pii(1, 0);
	pii t = exgcd(b, a % b);
	return pii(t.ss, t.ff - t.ss * (a / b));
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  k = (exgcd(2, MOD).ff + MOD) % MOD;
  cin >> n;
  for (i = 1; i*i <= n; i++) {
  	ans += (((n%(n/i)+n%(n/(i+1)+1))%MOD)*((n/i-n/(i+1))%MOD))%MOD*k;
  	ans %= MOD;
  }
  for (i = n/i; i >= 1; i--) {
  	ans += n % i;
  	ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}