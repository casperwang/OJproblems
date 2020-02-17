#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int unsigned long long
using namespace std;

int n, k, a, now, ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	now = k;
	while (n--) {
		cin >> a;
		if (a >= k) {
			cout << -1 << "\n";
			return 0;
		} else if (a >= now) {
			now = k-a, ans++; 
		} else {
			now -= a;
		}
	}
	cout << ans << "\n";
	return 0;
}