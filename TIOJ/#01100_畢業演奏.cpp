#include <bits/stdc++.h>
#define MAXN 1000
#define INF 1000000001
using namespace std;

int n, now;
int l, r, p;
int dp[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		now = 0, dp[1] = INF;
		for (int i = 0; i < n; i++) {
			cin >> l >> r >> p;
			for (int j = now; j >= 0; j--) {
				if (r-max(dp[j]+1, l)+1 >= p) {
					dp[j+1] = min(dp[j+1], max(dp[j]+1, l)+p-1);
				}
			}
			if (dp[now+1] < INF) now = now+1, dp[now+1] = INF;;
		}
		cout << now << '\n';
	}
}