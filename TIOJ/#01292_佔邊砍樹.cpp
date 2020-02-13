#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
using namespace std;

const int MAXN = 10000;
int n, t, k, ans;
int a, b;
int vis[MAXN+5];
int deg[MAXN+5];
vector <int> path[MAXN+5];
queue <int> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b), deg[a]++;
		path[b].pb(a), deg[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) nxt.push(i);
	}
	while (nxt.size()) {
		t = nxt.front(), nxt.pop();
		if (vis[t]) continue;
		vis[t] = 1, k = -1;
		for (int i : path[t])
			if (!vis[i]) k = i;
		if (k == -1) continue;
		vis[k] = 1;
		for (int i : path[k]) {
			deg[i]--;
			if (deg[i] == 1) nxt.push(i);
		}
		ans++;
	}
	cout << ans << "\n";
 	return 0;
}