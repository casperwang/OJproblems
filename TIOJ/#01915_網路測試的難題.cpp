#include <bits/stdc++.h>
#define MAXN 500000
#define pb push_back
using namespace std;

int t, n, m, now;
int ans1, ans2;
int a, b, tmp;
int vis[MAXN+5];
int deg[MAXN+5];
stack <int, vector<int>> cnt[MAXN+5];
vector <int> path[MAXN+5];

signed main() {
	return 0;
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			deg[i] = vis[i] = 0;
			path[i].clear();
			while (cnt[i].size()) cnt[i].pop();
		}
		ans1 = ans2 = now = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			deg[a]++, deg[b]++;
			path[a].pb(b), path[b].pb(a);
			vis[min(a, b)]++;
		}
		for (int i = 0; i < n; i++) {
			ans1 = max(ans1, vis[i]);
			cnt[deg[i]].push(i);
		}
		for (int i = 0; i < n; i++)
			vis[i] = 0;
		for (int i = 0; i < n; ) {
			while (!cnt[now].size()) now++;
			if (vis[cnt[now].top()]) {
				cnt[now].pop(); continue;
			} i++;
			ans2 = max(ans2, now);
			tmp = cnt[now].top();
			vis[tmp] = 1, cnt[now].pop();
			for (int j : path[tmp]) {
				if (!vis[j] && deg[j] > now) {
					deg[j]--;
					cnt[deg[j]].push(j);
				}
			}
		}
		cout << ans1 << " " << ans2 << '\n';
	}
}