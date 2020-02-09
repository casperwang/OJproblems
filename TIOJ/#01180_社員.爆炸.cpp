#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

int t, n, cnt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << "Case #" << i << ":\n";
		cnt = 1;
		for (int j = 0; j <= n; j++) {
			if (j) cnt *= j;
			cout << "TFCIS" << j << "=" << cnt << "\n";
		}
	}
	return 0;
}