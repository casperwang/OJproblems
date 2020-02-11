#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 5000;
int n, m, k;
int t, sum;
int arr[MAXN+5];
int dp[MAXN+5][2];
map <int, int> appr;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> k >> m) {
		appr.clear();
		for (int i = 1; i <= n; i++)
			arr[i] = 0;
		for (int i = 1; i <= k; i++)
			dp[i][0] = dp[i][1] = 0;
		for (int i = 0; i < n; i++)
			cin >> t, appr[t]++;
		t = 0;
		for (auto i : appr)
			arr[++t] = i.second;
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i <= t; i++) {
			sum = 1;
			for (int j = 1; j <= k; j++) {
				sum += dp[j][(i-1)%2];
				dp[j][i%2] = sum % m;
				if (j >= arr[i])
					sum -= dp[j-arr[i]][(i-1)%2];
			}
		}
		cout << dp[k][t%2] << "\n";
	}
 	return 0;
}