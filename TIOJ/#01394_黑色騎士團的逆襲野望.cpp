#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 32768
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, t, a;
vector <int> path[MAXN+5];
pair <int, int> dp[MAXN+5];

void DFS(int now) {
	dp[now].ff = 1;
	for (int i = 0; i < path[now].size(); i++) {
		DFS(path[now][i]);
		dp[now].ff += min(dp[path[now][i]].ff, dp[path[now][i]].ss);
		dp[now].ss += dp[path[now][i]].ff;
	}
	return;
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> a;
			path[i].pb(a);
		}
	}
	DFS(0);
	cout << min(dp[0].ff, dp[0].ss) << endl;
	return 0;
}