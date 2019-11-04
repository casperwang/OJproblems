#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 5000
using namespace std;

int n, m, a, t, ans;
int dp[2][MAXN+5];
int arr[MAXN+5];

signed main() {
	Hina;
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		ans = 0;
		for (int i = 1; i <= MAXN; i++) {
			dp[0][i] = dp[1][i] = arr[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a;
				if (a == 2) {
					arr[j] = i;
					dp[i%2][j] = 0;
					//cout << 0 << " \n"[j==m];
					continue;
				}
				t = min(dp[i%2][j-1], dp[(i+1)%2][j]);
				if (dp[i%2][j-1] == dp[(i+1)%2][j]) {
					if (arr[j-t] != i-t) dp[i%2][j] = t+1;
					else dp[i%2][j] = t;
				} else {
					dp[i%2][j] = t+1;
				}
				//cout << dp[i%2][j] << " \n"[j==m];
				ans = max(ans, dp[i%2][j]);
			}
		}
		cout << ans*ans << "\n";
	}
	return 0;
}