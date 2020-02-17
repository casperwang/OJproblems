#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100000;
int n, q;
int a, b, k, cnt;
pii dfs[MAXN+5];
int dis[MAXN+5];
int anc[MAXN+5][20];
vector <int> path[MAXN+5];

void DFS(int now, int par) {
	dfs[now].ff = ++cnt;
	for (int i : path[now]) {
		if (i != par) {
			dis[i] = dis[now]+1;
			DFS(i, now);
			anc[i][0] = now;
		}
	}
	dfs[now].ss = ++cnt;
}

void init() {
	for (int L = 1; L < 20; L++)
		for (int i = 1; i <= n; i++)
			anc[i][L] = anc[anc[i][L-1]][L-1];
}

bool ancestor(int a, int b) {
	if (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss)
		return 1;
	return 0;
}

int LCA(int a, int b) {
	if (ancestor(a, b)) return a;
	for (int L = 20-1; L >= 0; L--) {
		if (!ancestor(anc[a][L], b))
			a = anc[a][L];
	}
	return anc[a][0];
}

int kth_anc(int a, int k) {
	for (int L = 0; (1<<L) <= k; L++) {
		if ((1<<L) & k) a = anc[a][L];
	}
	return a;
}

int get_ans(int a, int b, int k) {
	int t = LCA(a, b);
	if (dis[a]-dis[t] >= k) {
		return kth_anc(a, k);
	} else if (dis[b]-dis[t]-(k-(dis[a]-dis[t])) >= 0) {
		return kth_anc(b, dis[b]-dis[t]-(k-(dis[a]-dis[t])));
	} else {
		return -1;
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	anc[1][0] = 1;
	DFS(1, 0);
	init();
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> k;
		cout << get_ans(a, b, k) << "\n";
	}
	return 0;
}