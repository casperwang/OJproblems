#include <bits/stdc++.h>
#define MAXN 50
#define int long long
using namespace std;

int n;
int dp[MAXN+5];

signed main() {
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= 50; i++)
		dp[i] = dp[i-1]+dp[i-2];
	cin >> n;
	cout << dp[n+1] << '\n';
}