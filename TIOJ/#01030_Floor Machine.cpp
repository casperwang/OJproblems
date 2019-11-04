#include <bits/stdc++.h>
#define int long long
using namespace std;

signed n, a, mmax;
int ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		ans = mmax = 0;
		for (register signed i = 0; i < n; i++)
			cin >> a, ans += a, mmax=a>mmax?a:mmax;
		ans += mmax;
		cout << ans+1 << '\n';
	}
}