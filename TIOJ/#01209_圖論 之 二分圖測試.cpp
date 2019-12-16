#include <bits/stdc++.h>
#define MAXN 40000
#define pb push_back
using namespace std;

int n, m;
int a, b;
bool tf;
bool vis[MAXN+5];
bool v[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now) {
	vis[now] = 1;
	for (int i : path[now]) {
		if (!vis[i]) {
			v[i] = !v[now];
			DFS(i);
		} else if (v[i] == v[now]) {
			tf = 0;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		for (int i = 1; i <= n; i++) {
			v[i] = vis[i] = 0;
			path[i].clear();
		}
		tf = 1;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			path[a].pb(b);
			path[b].pb(a);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i]) DFS(i);
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
}