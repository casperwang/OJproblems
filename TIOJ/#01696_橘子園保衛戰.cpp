#include <bits/stdc++.h>
#define MAXN 100000
#define pb push_back
using namespace std;

int n;
int a, b;
int t, r;
int k[MAXN+5];
int sze[MAXN+5];
int ans[MAXN+5];
bool vis[MAXN+5];
vector <vector<int>> dis;
vector <int> path[MAXN+5];

void treeCenter(int now, int par, int s) {
	sze[now] = 1;
	int mx = 0;
	for (int i : path[now]) {
		if (!vis[i] && i != par) {
			treeCenter(i, now, s);
			sze[now] += sze[i];
			mx = max(mx, sze[i]);
		}
	}
	mx = max(mx, s-sze[now]);
	if (mx < t) t = mx, r = now;
}

void dfs(int now, int par, int d, int c) {
	sze[now] = 1;
	if (dis[c].size() < d+1) dis[c].pb({1});
	else dis[c][d]++;
	if (dis[0].size() < d+1) dis[0].pb({1});
	else dis[0][d]++;
	for (int i : path[now]) {
		if (!vis[i] && i != par) {
			dfs(i, now, d+1, c);
			sze[now] += sze[i];
		}
	}
}

void get_ans(int now, int par, int d, int c) {
	if (k[now]-d >= 0) {
		ans[now] += dis[0][min(k[now]-d, (int)dis[0].size()-1)];
		ans[now] -= dis[c][min(k[now]-d, (int)dis[c].size()-1)];
	}
	for (int i : path[now]) {
		if (!vis[i] && i != par)
			get_ans(i, now, d+1, c);
	}
}

void DFS(int now, int s) {
	t = s+5, r = -1;
	treeCenter(now, 0, s);
	int root = r, cnt = 0;
	vis[root] = 1;
	dis.clear(), dis.pb(vector<int>({1}));
	for (int i : path[root]) {
		if (!vis[i]) {
			dis.pb(vector<int>({0}));
			dfs(i, 0, 1, ++cnt);
		}
	}
	for (vector <int> &p : dis) {
		for (int i = 1; i < p.size(); i++)
			p[i] += p[i-1];
	}
	ans[root] += dis[0][min(k[root], (int)dis[0].size()-1)];
	cnt = 0;
	for (int i : path[root]) {
		if (!vis[i]) get_ans(i, 0, 1, ++cnt);
	}
	for (int i : path[root]) {
		if (!vis[i]) DFS(i, sze[i]);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 1; i <= n; i++) {
			path[i].clear();
			ans[i] = vis[i] = sze[i] = 0;
			cin >> k[i];
		}
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			path[a].pb(b);
			path[b].pb(a);
		}
		DFS(1, n);
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << '\n';
		}
	}
}