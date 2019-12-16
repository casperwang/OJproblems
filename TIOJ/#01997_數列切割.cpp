#include <bits/stdc++.h>
#define MAXN 1000000
#define int long long
#define INF 1e10
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, k, a;
int dp[2][6];
stack <pii> ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int j = 1; j < k; j++)
		dp[0][j] = dp[1][j] = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dp[i&1][0] = dp[(i-1)&1][0] + a;
		for (int j = 1; j < min(i, k); j++) {
			if (dp[(i-1)&1][j-1] < dp[(i-1)&1][j]) {
				dp[i&1][j] = dp[(i-1)&1][j] + (1-(j&1)*2) * a;
			} else {
				ans.push(pii(i, j));
				dp[i&1][j] = dp[(i-1)&1][j-1] + (1-(j&1)*2) * a;
			}
		}
	}
	n++, k--;
	while (ans.size()) {
		if (ans.top().ss == k && ans.top().ff < n) {
			n = ans.top().ff;
			cout << n-1 << '\n';
			k--;
		}
		ans.pop();
	}
}