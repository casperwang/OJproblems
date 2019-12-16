#include <bits/stdc++.h>
#define MAXN 1000000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n, t, now, ans;
int w, m, c;
vector <pii> arr;
int dp[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	arr.reserve(n*12);
	for (register int i = 0; i < n; i++) {
		cin >> w >> m >> c;
		for (register int j = 1; j <= c; j <<= 1) {
			arr.pb(pii(w*j, m*j));
			c -= j;
		}
		arr.pb(pii(w*c, m*c));
	}
	sort(arr.begin(), arr.end());
	cin >> t;
	for (pii item : arr) {
		now = min(t, now+item.ff);
		for (int i = now; i >= item.ff; i--) {
			dp[i] = max(dp[i], dp[i-item.ff]+item.ss);
		}
	}
	for (int i = 1; i <= t; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}