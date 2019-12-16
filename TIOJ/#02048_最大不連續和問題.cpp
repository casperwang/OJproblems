#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a;
int dp[2][3];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dp[i%2][2] = max(dp[(i-1)%2][1] + a, dp[(i-1)%2][2] + max((int)0, a));
		dp[i%2][1] = max(dp[(i-1)%2][0], dp[(i-1)%2][1]);
		dp[i%2][0] = max(a, dp[(i-1)%2][0]+a);
		//cout << dp[i%2][0] << " " << dp[i%2][1] << " " << dp[i%2][2] << '\n';
	}
	cout << dp[n%2][2] << '\n';
}