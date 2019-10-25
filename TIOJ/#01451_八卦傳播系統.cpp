#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define ff first
#define ss second
#define MAXN 100000
#define pb push_back
using namespace std;
 
int n, m;
int a, b, k, ans;
bool vis[MAXN+5];
int dfs[MAXN+5];
int SCC[MAXN+5];
int cnt[MAXN+5];
vector <int> path1[MAXN+5], path2[MAXN+5];

void DFS1(int now) {
	vis[now] = 1;
	for (int i = 0; i < path1[now].size(); i++) {
		if (!vis[path1[now][i]]) DFS1(path1[now][i]);
	}
	dfs[++k] = now;
}

void DFS2(int now, int k) {
	vis[now] = 1;
	SCC[now] = k;
	for (int i = 0; i < path2[now].size(); i++) {
		if (!vis[path2[now][i]]) DFS2(path2[now][i], k);
	}
}

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		path1[a].pb(b);
		path2[b].pb(a);
	}
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) DFS1(i);
	k = 0;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = n; i >= 1; i--) 
		if (!vis[dfs[i]]) DFS2(dfs[i], ++k);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < path2[i].size(); j++) {
			if (SCC[path2[i][j]] != SCC[i]) cnt[SCC[i]] = 1;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (!cnt[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}