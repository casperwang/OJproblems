#include <bits/stdc++.h>
#define MAXN 100
#define int long long
using namespace std;

int n, a[MAXN+2];
int dp[MAXN+2][MAXN+2];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			for (int j = 1; j <= n; j++) dp[i][j] = 0;
			dp[i][i] = a[i];
		}
		for (int r = 1; r <= n; r++) {
			for (int l = r-1; l >= 1; l--) {
				//cout << l << " " << r << " ";
				for (int k = l; k < r; k++) {
					if ((r-l+1)&1)
						dp[l][r] = max(dp[l][r], dp[l][k]*dp[k+1][r]);
					else
						dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]);
				}
				//cout << dp[l][r] << endl;
			}
		}
		cout << dp[1][n] << '\n';
	}
}