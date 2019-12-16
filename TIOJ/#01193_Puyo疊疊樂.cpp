#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = (ans * i) % m;
			if (ans == 0) break;
		}
		cout << ans << '\n';
	}
}