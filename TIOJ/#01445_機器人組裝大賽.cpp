#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define ff first
#define ss second
#define pb push_back
#define MAXN 1000
#define INF (int)1e18
using namespace std;
 
int n, m, k, p;
int c1, c2;
int a, b, tmp;
pair <int, pair<int,int> > edg[MAXN*MAXN+5];
pair <int, pair<int,int> > arr[MAXN*MAXN+5];
vector < pair<int,int> > path[MAXN+5];
int dsu[MAXN+5];
int vis[MAXN+5];
int ac[15][MAXN+5];
int mx[15][MAXN+5];
pair <int, int> dfs[MAXN+5];

int finding(int a) {
	if (dsu[a] != a) dsu[a] = finding(dsu[a]);
	return dsu[a];
}

void DFS(int now) {
	vis[now] = 1;
	dfs[now].ff = k++;
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i].ff]) {
			ac[0][path[now][i].ff] = now;
			mx[0][path[now][i].ff] = path[now][i].ss;
			DFS(path[now][i].ff);
		}
	}
	dfs[now].ss = k++;
	return;
}

bool ancestor(int a, int b) {
	if (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss) return 1;
	return 0;
}

int max_edge(int a, int b) {
	if (ancestor(a, b)) return 0;
	int t = 0;
	for (int i = 13; i >= 0; i--) {
		if (!ancestor(ac[i][a], b)) {
			t = max(t, mx[i][a]);
			a = ac[i][a];
		}
	}
	return max(t, mx[0][a]);
}

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> edg[i].ss.ff >> edg[i].ss.ss >> edg[i].ff;
	}
	sort(edg, edg+m);
	for (int i = 0; i < m; i++) {
		if (finding(edg[i].ss.ff) == finding(edg[i].ss.ss)) {
			arr[p++] = edg[i];
			continue;
		}
		//cout << edg[i].ss.ff << " " << edg[i].ss.ss << endl;
		path[edg[i].ss.ff].pb({edg[i].ss.ss, edg[i].ff});
		path[edg[i].ss.ss].pb({edg[i].ss.ff, edg[i].ff});
		dsu[finding(edg[i].ss.ff)] = finding(edg[i].ss.ss);
		c1 += edg[i].ff, k++;
	}
	if (k != n-1) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	ac[0][1] = 1;
	k = 0, DFS(1);
	for (int i = 1; i <= 13; i++) {
		for (int j = 1; j <= n; j++) {
			mx[i][j] = max(mx[i-1][j], mx[i-1][ac[i-1][j]]);
			ac[i][j] = ac[i-1][ac[i-1][j]];
		}
	}
	c2 = INF;
	for (int i = 0; i < p; i++) {
		a = arr[i].ss.ff, b = arr[i].ss.ss;
		tmp = c1 - max(max_edge(a, b), max_edge(b, a)) + arr[i].ff;
		if (tmp >= c1) c2 = min(c2, tmp);
	}
	if (c2 == INF) cout << c1 << " " << -1 << endl;
	else cout << c1 << " " << c2 << endl;
	return 0;
}