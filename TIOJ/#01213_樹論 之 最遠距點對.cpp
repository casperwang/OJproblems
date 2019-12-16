#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n, ans;
int a, b, c;
vector <pii> path[MAXN+5];

int DFS(int now, int par) {
	int m1, m2, tmp;
	m1 = m2 = 0;
	for (pii i : path[now]) {
		if (i.ff == par) continue;
		tmp = DFS(i.ff, now) + i.ss;
		if (tmp > m1)
			m2 = m1, m1 = tmp;
		else if (tmp > m2)
			m2 = tmp;
	}
	ans = max(ans, m1+m2);
	return m1;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
			path[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> a >> b >> c;
			path[a].pb(pii(b, c));
			path[b].pb(pii(a, c));
		}
		DFS(1, 0);
		cout << ans << '\n';
	}
}