#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define pb push_back
#define MAXN 200000
using namespace std;

int n, mmax;
int a, b;
vector <int> path[MAXN+5];
bool vis[MAXN+5];
int sze[MAXN+5];
int ans[MAXN+5];

void DFS(int now) {
	vis[now] = 1;
	sze[now] = 1;
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i]]) {
			DFS(path[now][i]);
			sze[now] += sze[path[now][i]];
		}
	}
	ans[1] += sze[now];
	return;
}

void reDFS(int now, int par) {
	vis[now] = 1;
	if (par) ans[now] = ans[par] - sze[now] + (n-sze[now]);
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i]]) reDFS(path[now][i], now);
	}
	return;
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	DFS(1);
	for (int i = 1; i <= n; i++) vis[i] = 0;
	reDFS(1, 0);
	for (int i = 1; i <= n; i++) {
		mmax = max(mmax, ans[i]);
	}
	cout << mmax << endl;
	return 0;
}