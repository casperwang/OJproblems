#include <bits/stdc++.h>
#define MAXN 10000
#define int long long
using namespace std;

int n, m, a;
int dp[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	dp[0] = 1;
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		for (int i = 1; i <= m; i++) dp[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int j = a; j <= m; j++) {
				dp[j] += dp[j-a];
			}
		}
		cout << dp[m] << '\n';
	}
	return 0;
}