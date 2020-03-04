#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 10000;
string s;
bool tf;
int dp[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> s) {
		if (s == "0") return 0;
		dp[0] = tf = 1;
		for (int i = 1; i <= s.size(); i++) {
			if (s[i-1] != '0') {
				dp[i] = dp[i-1];
				if (i > 1 && s[i-2] == '1')
					dp[i] += dp[i-2];
				if (i > 1 && s[i-2] == '2' && s[i-1] <= '6')
					dp[i] += dp[i-2];
			} else if (s[i-2] == '1' || s[i-2] == '2') {
				dp[i] = dp[i-2];
			} else {
				tf = 0;
			}
		}
		if (tf) cout << dp[s.size()] << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}