#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 2000;
int n, m;
int h, c;
int dp[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> h >> c;
		for (int j = c; j <= m; j++)
			dp[j] = max(dp[j], dp[j-c] + h);
	}
	cout << dp[m] << "\n";
	return 0;
}