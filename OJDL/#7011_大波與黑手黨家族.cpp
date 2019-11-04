#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 200000
#define L (int)__lg(MAXN)
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, q;
int cnt;
int a, b;
int ac[MAXN+2][L+2];
pair <int,int> dfs[MAXN+2];
vector <int> path[MAXN+2];

void DFS(int now) {
	dfs[now].ff = ++cnt;
	for (auto i : path[now]) {
		if (!dfs[i].ff) DFS(i), ac[i][0] = now;
	}
	dfs[now].ss = ++cnt;
}

bool ancestor(int a, int b) {
	if (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss) return 1;
	else return 0;
}

int LCA(int a, int b) {
	if (ancestor(a, b)) return a;
	for (int i = L; i >= 0; i--) {
		if (!ancestor(ac[a][i], b)) a = ac[a][i];
	}
	return ac[a][0];
}

signed main() {
	Hina;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	DFS(1);
	ac[1][0] = 1;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= n; j++) {
			ac[j][i] = ac[ac[j][i-1]][i-1];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}