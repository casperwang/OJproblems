#include <bits/stdc++.h>
#define MAXN 300000
#define int long long
#define pb push_back
using namespace std;

int n, m, q, t;
int a, b, tmp;
int vis[MAXN+5];
vector <int> path[MAXN+5];
stack <int> cir;
int p[MAXN+5], pre[MAXN+5];

void DFS(int now, int par) {
	vis[now] = ++tmp;
	cir.push(now);
	for (int i = 0; i < path[now].size(); i++) {
		if (path[now][i] == par) continue;
		if (!vis[path[now][i]]) DFS(path[now][i], now);
		else if (vis[path[now][i]] < vis[now]) {
			int mmin = now, mmax = now;
			while (cir.size()) {
				t = cir.top(); cir.pop();
				mmin = min(mmin, t);
				mmax = max(mmax, t);
				if (t == path[now][i]) break;
			}
			p[mmin] = mmax-1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		path[a].pb(b);
		path[b].pb(a);
	}
	for (int i = 1; i <= n; i++) p[i] = n;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) DFS(i, 0);
	}
	for (int i = n; i >= 1; i--) {
		tmp = min(tmp, p[i]);
		p[i] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + p[i]-i+1;
		//cout << p[i] << " \n"[i==n];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		tmp = upper_bound(p+a, p+b+1, b)-p;
		cout << (b-tmp+2)*(b-tmp+1)/2 + pre[tmp-1]-pre[a-1] << endl;
	}
	return 0;
}