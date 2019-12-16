#include <bits/stdc++.h>
#define MAXN 10000
#define pb push_back
using namespace std;

int t, n, m;
int a, b, cnt;
int vis[MAXN+5];
int low[MAXN+5];
vector <int> path[MAXN+5];
vector <int> ans;

void DFS(int now, int par) {
	low[now] = vis[now] = ++cnt;
	bool tf = 0;
	int kids = 0;
	for (int i : path[now]) {
		if (!vis[i]) {
			DFS(i, now), kids++;
			if (low[i] >= vis[now]) tf = 1;
			low[now] = min(low[now], low[i]);
		} else if (i != par) {
			low[now] = min(low[now], vis[i]);
		}
	}
	if (!par && kids >= 2) ans.pb(now);
	if ( par && tf) ans.pb(now);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) path[i].clear();
		ans.clear();
		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			path[a].pb(b);
			path[b].pb(a);
		}
		DFS(1, 0);
		cout << ans.size() << '\n';
		if (!ans.size()) cout << 0 << '\n';
		sort(ans.begin(), ans.end());
		for (int j = 0; j < ans.size(); j++)
			cout << ans[j] << " \n"[j==ans.size()-1];
	}
}