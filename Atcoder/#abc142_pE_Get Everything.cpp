#include <bits/stdc++.h>
#define MAXN (1<<12)
#define INF 1e18
#define int long long
using namespace std;

int n, m;
int a, b, c, t[20];
int dp[MAXN+5];
bool tf;

signed main() {
	cin >> n >> m;
	for (int i = 1; i < (1<<n); i++) dp[i] = INF;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		memset(t, 0, sizeof(t));
		for (int j = 0; j < b; j++)
			cin >> c, t[c-1] = 1;
		for (int j = 1; j < (1<<n); j++) {
			tf = 1;
			for (int k = 0; k < n; k++) {
				if (((1<<k)&j) && !t[k]) {
					tf = 0;
					break;
				}
			}
			if (tf) dp[j] = min(dp[j], a);
		}
	}
	for (int i = 1; i < (1<<n); i++) {
		for (int j = 0; j <= i; j++) {
			dp[i] = min(dp[i], dp[j&i]+dp[(i-(j&i))&i]);
		}
	}
	if (dp[(1<<n)-1] == INF) cout << -1 << '\n';
	else cout << dp[(1<<n)-1] << '\n';
}