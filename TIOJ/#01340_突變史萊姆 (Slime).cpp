#include <bits/stdc++.h>
#define MAXN 100000
#define L __lg(MAXN)+1
#define INF 1e9
#define pii pair<int,int>
#define pip pair<int,pii>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n, m, q, cnt;
int a, b, v;
int dsu[MAXN+5];
pip edges[MAXN*22+5];
vector <pii> path[MAXN+5];
pii dfs[MAXN+5];
int ac[MAXN+5][L+5];
int mx[MAXN+5][L+5];

int fnd(int a) {
	if (dsu[a] != a) dsu[a] = fnd(dsu[a]);
	return dsu[a];
}

void DFS(int now, int par) {
	dfs[now].ff = ++cnt;
	for (pii i : path[now]) {
		if (i.ff != par) {
			DFS(i.ff, now);
			ac[i.ff][0] = now;
			mx[i.ff][0] = i.ss;
			//cout << now << " " << i.ff << '\n';
		}
	}
	dfs[now].ss = ++cnt;
}

bool ancestor(int a, int b) {
	if (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss) return 1;
	return 0;
}

int LCA(int a, int b) {
	if (ancestor(a, b)) return a;
	for (int i = L; i >= 0; i--) {
		if (!ancestor(ac[a][i], b)) a = ac[a][i];
	}
	return ac[a][0];
}

int min_edge(int a, int anc) {
	if (a == anc) return INF;
	int tmp = INF;
	for (int i = L; i >= 0; i--) {
		if (!ancestor(ac[a][i], anc)) {
			tmp = min(tmp, mx[a][i]);
			a = ac[a][i];
		}
	}
	return min(mx[a][0], tmp);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j+=i) {
			if (j != i) edges[cnt++] = pip(i,pii(j,j-i));
			if (j+i <= n) edges[cnt++] = pip(i,pii(j,j+i));
		}
	}
	//cout << cnt << '\n';
	sort(edges, edges+cnt, greater<pip>());
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 0; i < cnt; i++) {
		a = edges[i].ss.ff, b = edges[i].ss.ss;
		v = edges[i].ff;
		if (fnd(a) != fnd(b)) {
			path[a].pb(pii(b, v)), path[b].pb(pii(a, v));
			dsu[dsu[a]] = dsu[b];
		}
	}
	cnt = 0;
	ac[1][0] = 1;
	mx[1][0] = INF;
	DFS(1, 0);
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= n; j++) {
			ac[j][i] = ac[ac[j][i-1]][i-1];
			mx[j][i] = min(mx[j][i-1], mx[ac[j][i-1]][i-1]);
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		m = LCA(a, b);
		cout << min(min_edge(a, m), min_edge(b, m)) << '\n';
	}
	return 0;
}