#include <bits/stdc++.h>
#define MAXN 2000
#define pb push_back
using namespace std;

signed n, m, ans;
int a, b, cnt, tmp, k;
int vis[MAXN+5];
int low[MAXN+5];
int sze[MAXN+5];
bool graph[MAXN+5][MAXN+5];
vector <int> path[MAXN+5];

void BFS(int now) {
	queue <int> nxt;
	nxt.push(now);
	vis[now] = k;
	while (nxt.size()) {
		int s = nxt.front();
		nxt.pop();
		for (register int i = 1; i <= n; i++) {
			if (!graph[s][i]) continue;
			if (vis[i] != k) {
				path[s].pb(i), path[i].pb(s);
				graph[s][i] = graph[i][s] = 0;
				vis[i] = k;
				nxt.push(i);
			}
		}
	}
}

void DFS(int now, int par, int anc) {
	low[now] = vis[now] = ++cnt;
	sze[now] = 1;
	bool tf = 1;
	int kid = 0;
	for (int i : path[now]) {
		if (i == anc) continue;
		if (!vis[i]) {
			DFS(i, now, anc), kid++;
			if (low[i] >= vis[now]) tf = 0;
			low[now] = min(low[now], low[i]);
			sze[now] += sze[i];
		} else if (i != par) {
			low[now] = min(low[now], vis[i]);
		}
	}
	if (now == par && kid >= 2) tmp++;
	else if (now != par && !tf) tmp++;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}
	for (k = 1; k <= 3; k++) 
		for (int i = 1; i <= n; i++)
			if (vis[i] != k) BFS(i);
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		cnt = tmp = k = a = 0;
		for (int j : path[i]) if (!vis[j]) DFS(j, j, i), k++, a += sze[j]==1;
		if (k >= 2) ans += n-1-(a&&k==2);
		else ans += tmp;
	}
	cout << ans/2 << '\n';
	return 0;
}