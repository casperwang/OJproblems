#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int t, n;
int ans;
int dp[MAXN+5];

signed main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (int j = 1; j <= n; j++) {
			if (n/j-1 > dp[j]) {
				for (int k = j+j; k <= n; k += j) {
					dp[k]++;
				}
			} else {
				ans += dp[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}