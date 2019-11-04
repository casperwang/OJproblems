#include <bits/stdc++.h>
#define MAXN 500000
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

int t, n, m;
int a, b;
int ans1, ans2;
int arr[MAXN+5];
vector <int> path[MAXN+5];
int deg[MAXN+5];
int ans[MAXN+5];
int vis[MAXN+5];
pii tmp;
priority_queue <pii, vector<pii>, greater<pii>> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		while (nxt.size()) nxt.pop();
		for (int j = 0; j < n; j++) {
			deg[j] = ans[j] = vis[j] = arr[j] = 0;
			path[j].clear();
		}
		ans1 = ans2 = 0;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			path[a].pb(b);
			path[b].pb(a);
			deg[a]++;
			deg[b]++;
			ans[min(a, b)]++;
		}
		for (int j = 0; j < n; j++) {
			ans1 = max(ans1, ans[j]);
			nxt.push(pii(deg[j], j));
		}
		for (int j = 0; j < n; j++) {
			while (nxt.size() && vis[nxt.top().ss]) nxt.pop();
			tmp = nxt.top();
			vis[tmp.ss] = 1;
			arr[j] = tmp.ss;
			ans2 = max(ans2, tmp.ff);
			for (auto k : path[arr[j]]) {
				deg[k]--;
				nxt.push(pii(deg[k], k));
			}
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}