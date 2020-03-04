#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
using namespace std;

const int MAXN = 1000;
const int INF = 1e9;
int t, n, m, a;
int ans;
int c[MAXN+5];
int dis[MAXN+5];
int deg[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now, int par) {
	for (int i : path[now]) {
		if (i == par) continue;
		dis[i] = max(dis[i], dis[now] + c[i]);
		deg[i]--;
		if (!deg[i]) DFS(i, now);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			dis[i] = deg[i] = 0;
			path[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> c[i] >> m;
			for (int j = 0; j < m; j++) {
				cin >> a;
				path[i].pb(a);
				deg[a]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!deg[i] && !dis[i])
				dis[i] = c[i], DFS(i, 0);
		}
		for (int i = 1; i <= n; i++)
			ans = max(ans, dis[i]);
		cout << ans << "\n";
	}
	return 0;
}