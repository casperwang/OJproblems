#include <bits/stdc++.h>
#define MAXN 200
#define pb push_back
using namespace std;

int n, k;
int a, b, t;
int ans;
int v[MAXN+5];
int dp[MAXN+5][MAXN+5];
int vis[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now) {
	vis[now] = ++t;
	dp[now][0] = v[now];
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i]]) {
			DFS(path[now][i]);
			dp[now][0] += dp[path[now][i]][k];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < path[now].size(); j++) {
			if (vis[now] > vis[path[now][j]]) continue;
			int tmp = dp[path[now][j]][i-1];
			for (int p = 0; p < path[now].size(); p++) {
				if (vis[now] > vis[path[now][p]] || j == p) continue;
				tmp += dp[path[now][p]][max(k-i, i-1)];
			}
			dp[now][i] = max(dp[now][i], tmp);
		}
	}
	for (int i = k-1; i >= 0; i--) {
		dp[now][i] = max(dp[now][i], dp[now][i+1]);
	}
	return;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <  n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	DFS(n);
	cout << dp[n][0] << endl;
	return 0;
}