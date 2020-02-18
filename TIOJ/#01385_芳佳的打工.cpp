#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 1000;
string a, b;
int dp[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	getline(cin, a);
	getline(cin, b);
	a = '0'+a, b = '0'+b;
	for (int i = 1; i <= max(a.size(), b.size()); i++)
		dp[0][i] = dp[i][0] = i;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
		}
	}
	cout << dp[a.size()-1][b.size()-1] << "\n";
	return 0;
}