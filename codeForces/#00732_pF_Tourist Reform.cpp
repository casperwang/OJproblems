#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define pb push_back
#define MAXN 400000
#define ff first
#define ss second
using namespace std;

int n, m, k, t;
int a, b;
vector <pair<int,int> > path[MAXN+5];
pair <int, int> anss[MAXN+5];
int dfs[MAXN+5];
int par[MAXN+5];
int low[MAXN+5];
bool vis[MAXN+5];
set <pair<int,int> > bridges;
vector <int> BCCs[MAXN+5];

void DFS(int now) {
	dfs[now] = low[now] = ++k;
	vis[now] = 1;
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i].ff]) 
			par[path[now][i].ff] = now, DFS(path[now][i].ff);
		if (path[now][i].ff != par[now])
			low[now] = min(low[now], low[path[now][i].ff]);
	}
	for (int i = 0; i < path[now].size(); i++) {
		if (path[now][i].ff == par[now] && low[path[now][i].ff] < low[now])
			bridges.insert({now, path[now][i].ff});
	}
}

void BCC(int now, int k) {
	vis[now] = 1;
	BCCs[k].pb(now);
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i].ff] && !bridges.count({now, path[now][i].ff}) && !bridges.count({path[now][i].ff, now})) {
			BCC(path[now][i].ff, k);
		}
	}
}

void reDFS(int now) {
	vis[now] = 1;
	for (int i = 0; i < path[now].size(); i++) {
		anss[path[now][i].ss] = {now, path[now][i].ff};
		if (!vis[path[now][i].ff]) reDFS(path[now][i].ff);
	}
}

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		path[a].pb({b,i}), path[b].pb({a,i});
	}
	DFS(1);
	k = 0;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]) BCC(i, ++k);
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if ((int)BCCs[i].size() > ans) t = i;
		ans = max(ans, (int)BCCs[i].size());
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) vis[i] = 0;
	reDFS(BCCs[t][0]);
	for (int i = 0; i < m; i++) {
		cout << anss[i].ff << " " << anss[i].ss << endl;
	}
	return 0;
}