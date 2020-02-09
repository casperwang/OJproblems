#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pdd pair<double,double>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100;
const int MOD = 1000000009;
int t, n;
int dp[MAXN+5], pre[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	dp[1] = pre[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i] = (dp[i] + (i-j)*2*dp[j]) % MOD;
		}
		pre[i] = (pre[i-1] + dp[i]) % MOD;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << pre[n] << "\n";
	}
	return 0;
}