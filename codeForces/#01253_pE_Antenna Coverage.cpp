#include <bits/stdc++.h>
#define MAXN 80
#define MAXM 100000
using namespace std;

int n, m, p;
int x[MAXN+5], s[MAXN+5];
int dp[MAXM+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> s[i];
	}
	for (int i = m; i >= 1; i--) {
		dp[i] = dp[i+1]+1;
		for (int j = 1; j <= n; j++) {
			if (x[j]+s[j] < i) continue;
			p = max(0, x[j]-s[j]-i);
			dp[i] = min(dp[i], dp[min(m+1, x[j]+s[j]+p+1)]+p);
		}
		//cout << dp[i] << '\n';
	}
	cout << dp[1] << '\n';
	return 0;
}