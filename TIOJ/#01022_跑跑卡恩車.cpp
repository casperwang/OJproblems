#include <bits/stdc++.h>
#define MAXN 100
#define INF 1000000
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int t, n, m;
int arr[MAXN+5][MAXN+5];
int dp[MAXN+5][MAXN+5];
bool vis[MAXN+5][MAXN+5];
pii now;
pii dir[4] = {pii(1,0),pii(0,1),pii(-1,0),pii(0,-1)};
queue <pii> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(dp, INF, sizeof(dp));
		memset(arr, INF, sizeof(arr));
		memset(vis, 1, sizeof(vis));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				vis[i][j] = 0, cin >> arr[i][j];
		dp[1][1] = 0;
		nxt.push(pii(1, 1));
		vis[1][1] = 1;
		while (nxt.size()) {
			now = nxt.front();
			//cout << now.ff << " " << now.ss << '\n';
			for (pii d : dir) {
				if (abs(arr[now.ff+d.ff][now.ss+d.ss]-arr[now.ff][now.ss]) > 5)
					continue;
				if (!vis[now.ff+d.ff][now.ss+d.ss]) {
					dp[now.ff+d.ff][now.ss+d.ss] = dp[now.ff][now.ss]+1;
					vis[now.ff+d.ff][now.ss+d.ss] = 1;
					nxt.push(pii(now.ff+d.ff, now.ss+d.ss));
				}
			}
			nxt.pop();
		}
		cout << dp[n][m] << '\n';
	}
}