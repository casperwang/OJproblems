#include <bits/stdc++.h>
#define MAXN 5000
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, m, k;
int a, b;
int ans;
int deg[MAXN+5];
int dsu[MAXN+5];
int sze[MAXN+5];
bool vis[MAXN+5];
vector <int> path[MAXN+5];
vector <pii> p[MAXN+5];

void dfs(int now, int k) {
	vis[now] = 1;
	for (int i : path[now]) {
		deg[i]--;
		if (!vis[i]) p[k-1].pb(pii(now, i));
		if (!vis[i] && deg[i] < k) {
			dfs(i, k);
		}
	}
}

int Find(int now) {
	if (dsu[now] != now) dsu[now] = Find(dsu[now]);
	return dsu[now];
}

void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	sze[Find(a)] += sze[Find(b)];
	dsu[dsu[b]] = dsu[a];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		sze[i] = 1, dsu[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		deg[a]++, deg[b]++;
		path[a].pb(b), path[b].pb(a);
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && deg[j] < i) dfs(j, i);
		}
		if (p[i-1].size()) k = i-1;
	}
	for (int i = k; i >= 0; i--) {
		for (pii e : p[i])
			Union(e.ff, e.ss);
		for (int j = 1; j <= n; j++) {
			if (sze[Find(j)] > 1) {
				ans = max(ans, sze[dsu[j]]*i);
			}
		}
	}
	cout << ans << '\n';
}