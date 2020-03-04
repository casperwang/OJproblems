#include <bits/stdc++.h>
#pragma GCC optimize("O1,O2,Os,Ofast,O3,unroll-loops")
#define max(a,b) (a>b?a:b)
using namespace std;

const int MAXN = 2000;
int t, n, m;
int now, tmp;
bool tf;
int w[MAXN+1];
int s[MAXN+1];
int dp[2][MAXN+1];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		tf = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		for (int i = 1; i <= m; i++)
			cin >> s[i];
		for (int i = 1; i <= n; i++)
			dp[0][i] = dp[1][i] = i;
		for (int i = 1; i <= m && !tf; i++) {
			for (int j = n; j >= 1; j--) {
				now = dp[(i+1)&1][j], tmp = s[i];
				while (now < n && tmp >= w[now+1])
					tmp -= w[++now];
				dp[i&1][j] = max(dp[i&1][j], now);
				now = j, tmp = s[i];
				while (now > 1 && tmp >= w[now-1])
					tmp -= w[--now];
				dp[i&1][now] = max(dp[i&1][now], dp[(i+1)&1][j]);
			}
			if (dp[i&1][1] == n) tf = 1;
		}
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
}