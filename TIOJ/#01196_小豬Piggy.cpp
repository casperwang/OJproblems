#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 10;

int n;
string arr[MAXN+5];
int dp[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i <= n; i++) arr[0] += "X";
	for (int i = 1; i <= n; i++)
		cin >> arr[i], arr[i] = "X" + arr[i];
	arr[1][1] = arr[n][n] = '0';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = -1;
			if (arr[i][j] == 'X')
				continue;
			if (dp[i-1][j] != -1 && i-1)
				dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i][j]-'0');
			if (dp[i][j-1] != -1 && j-1)
				dp[i][j] = max(dp[i][j], dp[i][j-1] + arr[i][j]-'0');
		}
	}
	if (dp[n][n] == -1) cout << "X\n";
	else cout << dp[n][n] << "\n";
	return 0;
}