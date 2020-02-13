#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 10000;
int n, m;
int a, b, s, k;
bool vis[MAXN*2+5];
int ans[MAXN+5];
vector <int> path[MAXN*2+5];
vector <int> repath[MAXN*2+5];
vector <set<int>> arr;
stack <int> dfs;

void DFS(int now) {
	vis[now] = 1;
	for (int i : path[now]) {
		if (!vis[i]) DFS(i);
	}
	dfs.push(now);
}

void DFS2(int now, int k) {
	vis[now] = 1;
	arr[k].insert(now > n ? now-n : now);
	if (now > n) ans[now - n] = k;
	for (int i : repath[now]) {
		if (!vis[i]) DFS2(i, k);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> s;
		if (s == 0) {
			path[a].pb(b), repath[b].pb(a);
			path[n+b].pb(n+a), repath[n+a].pb(n+b);
		} else if (s == 1) {
			path[a].pb(n+b), repath[n+b].pb(a);
			path[n+b].pb(a), repath[a].pb(n+b);
		}
	}
	for (int i = 1; i <= 2*n; i++) {
		if (!vis[i]) DFS(i);
	}
	memset(vis, 0, sizeof(vis));
	while (dfs.size()) {
		arr.pb(set<int>());
		DFS2(dfs.top(), k++);
		while (dfs.size() && vis[dfs.top()])
			dfs.pop();
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[ans[i]].size()-1 << "\n";
	}
 	return 0;
}