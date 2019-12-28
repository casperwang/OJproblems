#include <bits/stdc++.h>
#define MAXN 200000
#define int long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, ans;
int a, b, c;
int dp[MAXN+5][4];
vector <pii> path[MAXN+5];

void dfs(int now, int par) {
	for (pii i : path[now]) {
		if (i.ff == par) continue;
		dfs(i.ff, now);
		if (i.ss) {
			dp[now][3] += dp[i.ff][3] + 1;
			dp[now][1] += dp[i.ff][0] + dp[i.ff][1];
		} else {
			dp[now][0] += dp[i.ff][0] + 1;
			dp[now][2] += dp[i.ff][3] + dp[i.ff][2];
		}
	}
	for (int i = 0; i < 4; i++) {
		ans += dp[now][i];
		if (i == 0 || i == 3)
			ans += dp[now][i];
	}
	for (pii i : path[now]) {
		if (i.ff == par) continue;
		if (i.ss) {
			ans += (dp[now][3]-dp[i.ff][3]-1)*(dp[i.ff][3]+1+dp[i.ff][1]+dp[i.ff][0]);
		} else {
			ans += (dp[now][3]+dp[now][2]-(dp[i.ff][2]+dp[i.ff][3])+dp[now][0]-dp[i.ff][0]-1)*(dp[i.ff][0]+1);
		}
	}
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
  	cin >> a >> b >> c;
  	path[a].pb(pii(b, c));
  	path[b].pb(pii(a, c));
  }
  dfs(1, 0);
  cout << ans << '\n';
  return 0;
}