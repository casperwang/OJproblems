#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

const int INF = 1e18;
int t, n, m, a;
int mmax, mmin;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		mmax = INF, mmin = -INF;
		for (int i = 1; i < n; i++) {
			cin >> a;
			if (a > m) mmax = min(mmax, a);
			if (a < m) mmin = max(mmin, a);
		}
		cout << mmax << " " << mmin << "\n";
	}
 	return 0;
}