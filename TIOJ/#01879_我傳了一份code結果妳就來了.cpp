#include <bits/stdc++.h>
#define MAXN 10000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n, m;
int a, b, cnt, k;
vector <int> path[MAXN+5];
int low[MAXN+5];
int vis[MAXN+5];
int dsu[MAXN+5];
vector <vector<int>> bcc;

int fnd(int now) {
	if (now != dsu[now]) dsu[now] = fnd(dsu[now]);
	return dsu[now];
}

void DFS(int now, int par) {
	vis[now] = low[now] = ++cnt;
	for (int i : path[now]) {
		if (i == par) continue;
		if (!vis[i]) {
			DFS(i, now);
			if (low[i] <= vis[now]) {
				dsu[fnd(i)] = fnd(now);
			}
			low[now] = min(low[i], low[now]);
		} else {
			low[now] = min(vis[i], low[now]);
			dsu[fnd(i)] = fnd(now);
		}
	}
}

bool cmp(const vector <int> &a, const vector <int> &b) {
	if (!b.size()) return 0;
	if (!a.size()) return 1;
	return a[0] < b[0];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a++, b++;
		path[a].pb(b);
		path[b].pb(a);
	}
	for (int i = 1; i <= n; i++) dsu[i] = i;
	DFS(1, 0);
	bcc.resize(n+1);
	for (int i = 1; i <= n; i++) {
		bcc[fnd(i)].pb(i);
	}
	for (int i = 0; i < bcc.size(); i++) {
		if (!bcc[i].size()) continue;
		sort(bcc[i].begin(), bcc[i].end());
	}
	sort(bcc.begin(), bcc.end(), cmp);
	for (int i = 0; i < bcc.size(); i++) {
		if (!bcc[i].size()) continue;
		cout << ++k << ":";
		for (int j : bcc[i]) {
			cout << " " << j-1;
		}
		cout << '\n';
	}
}