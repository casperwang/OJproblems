#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
#define pb push_back
#define ff first
#define ss second
#define L (int)log2(MAXN)
using namespace std;

int n, m, q;
int t, t1, t2;
int a, b, ans;
pair<int,int> dfs[MAXN+5];
bool vis[MAXN+5];
vector <int> path[MAXN+5];
int sze[MAXN+5];
int dth[MAXN+5];
int ac[MAXN+5][L+5];

bool ancestor(int a, int b) {
	if (dfs[a].ff <= dfs[b].ff && dfs[a].ss >= dfs[b].ss) return 1;
	else return 0;
}

void DFS(int now, int d) {
	vis[now] = sze[now] = 1;
	dth[now] = d;
	dfs[now].ff = ++t;
	for (int i = 0; i < path[now].size(); i++) {
		if (vis[path[now][i]]) continue;
		ac[path[now][i]][0] = now;
		DFS(path[now][i], d+1);
		sze[now] += sze[path[now][i]];
	}
	dfs[now].ss = ++t;
}

int pw(int a, int n) {
	int b = 1, t = 1;
	for (; b <= n; b <<= 1) {
		if (b & n) t = t*a;
		a = a*a;
	}
	return t;
}

int LCA(int a, int b) {
	if (ancestor(a, b)) return a;
	for (int i = L; i >= 0; i--) {
		if (!ancestor(ac[a][i], b)) a = ac[a][i];
	}
	return ac[a][0];
}

int Kth(int a, int k) {
	for (int i = L; i >= 0; i--) {
		if (pw(2, i) & k) a = ac[a][i];
	}
	return a;
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	ac[1][0] = 1;
	DFS(1, 0);
	for (int j = 1; j <= L; j++) {
		for (int i = 1; i <= n; i++) {
			ac[i][j] = ac[ac[i][j-1]][j-1];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if ((dth[a]+dth[b]-2*dth[m])%2 == 0) {
			int m = LCA(a, b);
			if (a == b) {
				ans = n;
			} else if (dth[a] == dth[b]) {
				t1 = Kth(a, (dth[a]-dth[m])-1);
				t2 = Kth(b, (dth[b]-dth[m])-1);
				ans = n - sze[t1] - sze[t2];
			} else if (dth[a] > dth[b]) {
				t = Kth(a, (dth[a]+dth[b]-2*dth[m])/2-1);
				ans = sze[ac[t][0]] - sze[t];
			} else if (dth[a] < dth[b]) {
				t = Kth(b, (dth[a]+dth[b]-2*dth[m])/2-1);
				ans = sze[ac[t][0]] - sze[t];
			}
			cout << ans << "\n";
		} else {
			cout << 0 << "\n";
		}
	}
	return 0;
}