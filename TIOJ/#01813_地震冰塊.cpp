#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 300;
int n, m, q, x, y, now;
int d, a, ans;
string mp[MAXN+1];
int dp[MAXN+1][MAXN+1];
deque <pii> dq;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> x >> y;
	for (int i = 0; i <= m+1; i++) {
		mp[0]   += "*";
		mp[n+1] += "*";
	}
	for (int i = 1; i <= n; i++) {
		cin >> mp[i];
		mp[i] = '*' + mp[i] + '*';
	}
	for (int i = 0; i <= n+1; i++)
		for (int j = 0; j <= m+1; j++)
			dp[i][j] = -1;
	dp[x][y]= 0;
	cin >> q;
	for (int k = 0; k < q; k++) {
		cin >> d >> a;
		if (d == 4) {
			for (int i = 1; i <= n; i++) {
				dq.clear();
				for (int j = 1; j <= m; j++) {
					if (mp[i][j] == '*') {
						dq.clear();
						continue;
					}
					if (dq.size() && j-dq.front().ss > a)
						dq.pop_front();
					while (dq.size() && dp[i][j] >= dq.back().ff+(j-dq.back().ss))
						dq.pop_back();
					if (dp[i][j] != -1)
						dq.push_back(pii(dp[i][j], j));
					if (dq.size())
						dp[i][j] = max(dp[i][j], dq.front().ff+j-dq.front().ss);
				}
			}
		}
		if (d == 3) {
			for (int i = 1; i <= n; i++) {
				dq.clear();
				for (int j = m; j >= 1; j--) {
					if (mp[i][j] == '*') {
						dq.clear();
						continue;
					}
					if (dq.size() && dq.front().ss-j > a)
						dq.pop_front();
					while (dq.size() && dp[i][j] >= dq.back().ff+(dq.back().ss-j))
						dq.pop_back();
					if (dp[i][j] != -1)
						dq.push_back(pii(dp[i][j], j));
					if (dq.size())
						dp[i][j] = max(dp[i][j], dq.front().ff+dq.front().ss-j);
				}
			}
		}
		if (d == 2) {
			for (int j = 1; j <= m; j++) {
				dq.clear();
				for (int i = 1; i <= n; i++) {
					if (mp[i][j] == '*') {
						dq.clear();
						continue;
					}
					if (dq.size() && i-dq.front().ss > a)
						dq.pop_front();
					while (dq.size() && dp[i][j] >= dq.back().ff+(i-dq.back().ss))
						dq.pop_back();
					if (dp[i][j] != -1)
						dq.push_back(pii(dp[i][j], i));
					if (dq.size())
						dp[i][j] = max(dp[i][j], dq.front().ff+i-dq.front().ss);
				}
			}
		} 
		if (d == 1) {
			for (int j = 1; j <= m; j++) {
				dq.clear();
				for (int i = n; i >= 1; i--) {
					if (mp[i][j] == '*') {
						dq.clear();
						continue;
					}
					if (dq.size() && dq.front().ss-i > a)
						dq.pop_front();
					while (dq.size() && dp[i][j] >= dq.back().ff+(dq.back().ss-i))
						dq.pop_back();
					if (dp[i][j] != -1)
						dq.push_back(pii(dp[i][j], i));
					if (dq.size())
						dp[i][j] = max(dp[i][j], dq.front().ff+dq.front().ss-i);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dp[i][j]);
	cout << ans << "\n";
	return 0;
}