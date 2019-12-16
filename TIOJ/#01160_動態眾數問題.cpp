#include <bits/stdc++.h>
using namespace std;

int n, ans, k;
unordered_map <int,int> appr;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		appr[n]++;
		if (appr[n] > k) {
			k = appr[n];
			ans = n;
		} else if (appr[n] == k) {
			ans = min(ans, n);
		}
		cout << k << " " << ans << '\n';
	}
}