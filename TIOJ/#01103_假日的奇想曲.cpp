#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 10000
#define MOD 10000
using namespace std;

int n;
int dp[MAXN*2+5][2];
int ans[MAXN+5];

signed main() {
	Hina;
	dp[1][0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		for (int j = 1; j <= i*2+1; j++) {
			dp[j][i%2] = (dp[j][(i+1)%2]+dp[j-1][i%2]) % MOD;
			//cout << dp[j][i%2] << " \n"[j==i*2+1];
		}
		ans[i] = dp[i*2+1][i%2] % MOD;
		//cout << ans[i] << endl;
	}
	while (cin >> n) {
		if (!n) return 0;
		if (n < 8) cout << ans[n] << "\n";
		else if (ans[n] < 10) cout << "000" << ans[n] << "\n";
		else if (ans[n] < 100) cout << "00" << ans[n] << "\n";
		else if (ans[n] < 1000) cout << "0" << ans[n] << "\n";
		else cout << ans[n] << "\n";
	}
	return 0;
}