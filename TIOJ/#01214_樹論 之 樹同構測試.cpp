#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100;
const int k = 880301;
const int MOD = 1000000009;
int n;
int a, b;
int anc[MAXN+1];
int sze[MAXN+1];
pii h1, h2;
vector <int> path[MAXN+1];

int DFS(int now, int par) {
	sze[now] = 1;
	for (int i : path[now]) {
		if (i == par) continue;
		anc[i] = now;
		sze[now] += DFS(i, now);
	}
	return sze[now];
}

int DFS_hash(int now, int par) {
	int s = k;
	for (int i : path[now]) {
		if (i == par) continue;
		s += DFS_hash(i, now);
	}
	return (s * s) % MOD;
}

pii solve() {
	for (int i = 1; i <= n; i++)
		path[i].clear();
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	DFS(1, 0);
	pii h(0, 1);
	bool tf, d = 0;
	for (int i = 1; i <= n; i++) {
		tf = ((sze[1]-sze[i])*2 <= n);
		for (int j : path[i])
			if (j != anc[i] && sze[j]*2 > n) tf = 0;
		if (tf && !d) h.ff = DFS_hash(i, 0), d = 1;
		else if (tf) h.ss = DFS_hash(i, 0);
	}
	return h;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		h1 = solve();
		h2 = solve();
		if (h1.ff*h1.ss == h2.ff*h2.ss)
			cout << "Same\n";
		else
			cout << "Different\n";
	}
	return 0;
}