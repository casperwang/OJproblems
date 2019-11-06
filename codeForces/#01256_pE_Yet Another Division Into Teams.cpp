#include <bits/stdc++.h>
#define MAXN 200000
#define INF 1e18
#define pii pair<int,int>
#define int long long
#define ff first
#define ss second
using namespace std;

int n, mmin, p;
pii a[MAXN+5];
int dp[MAXN+5];
int pre[MAXN+5];
int ans[MAXN+5];

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].ff, a[i].ss = i;
		pre[i] = -1;
	}
	sort(a, a+n);
	dp[0] = dp[1] = mmin = INF;
	dp[2] = a[2].ff - a[0].ff;
	for (int i = 2; i < n; i++) {
		if (i >= 5) {
			if (dp[i-3]-a[i-2].ff < mmin) mmin = dp[i-3]-a[i-2].ff, p = i-3;
		}
		if (a[i].ff + mmin < a[i].ff - a[0].ff) {
			dp[i] = a[i].ff + mmin;
			pre[i] = p;
		} else {
			dp[i] = a[i].ff - a[0].ff;
		}
	}
	int k = 1;
	for (int i = n-1; i >= 0;) {
		for (int j = pre[i]+1; j <= i; j++) {
			ans[a[j].ss] = k;
		}
		i = pre[i], k++;
	}
	cout << dp[n-1] << " " << k-1 << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i==n-1];
	}
}