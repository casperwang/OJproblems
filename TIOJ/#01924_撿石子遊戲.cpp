#include <bits/stdc++.h>
#define MAXN 2000000
using namespace std;

int n, ans;
string s;
string arr[6] = {"PEC","PCE","EPC","ECP","CPE","CEP"};
int dp[2][3];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (int t = 0; t < 6; t++) {
		dp[0][0] = (s[0] == arr[t][0]);
		dp[0][1] = dp[0][2] = 0;
		for (int i = 1; i < n; i++) {
			dp[i&1][0] = dp[!(i&1)][0] + (s[i] == arr[t][0]);
			dp[i&1][1] = max(dp[!(i&1)][0], dp[!(i&1)][1]) + (s[i] == arr[t][1]);
			dp[i&1][2] = max({dp[!(i&1)][0], dp[!(i&1)][1], dp[!(i&1)][2]}) + (s[i] == arr[t][2]);
		}
		ans = max(ans, dp[!(n&1)][2]);
	}
	cout << ans << '\n';
}
