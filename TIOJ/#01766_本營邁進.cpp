#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 200000
#define INF 1e18
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n;
int a, b, c;
int mmax;
vector < pair<int,int> > path[MAXN+5];
int ans[MAXN+5];

int DFS(int now, int par) {
	for (auto i : path[now]) {
		if (i.ff != par) ans[now] += min(i.ss, DFS(i.ff, now));
	}
	if (path[now].size() == 1) return INF;
	return ans[now];
}

void reDFS(int now, int par, int c) {
	if ((int)path[par].size() == 1) ans[now] += c;
	else ans[now] += min(c, ans[par] - min(c, ans[now]));
	for (auto i : path[now]) {
		if (i.ff != par) reDFS(i.ff, now, i.ss);
	}
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		path[a].pb({b, c});
		path[b].pb({a, c});
	}
	DFS(1, 0);
	reDFS(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		mmax = max(ans[i], mmax);
	}
	cout << mmax << '\n';
	return 0;
}