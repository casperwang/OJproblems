#include <iostream>
using namespace std;
int n, m, x, y;
int a, b, c, d, s;
int ans;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m >> x >> y) {
		a = x-1, b = y-1, c = n-x, d = m-y;
		ans = 0, s = (a ^ b ^ c ^ d);
		if (s) {
			if (a > (s ^ a)) ans = max(ans, (a - (s ^ a)) * m);
			if (b > (s ^ b)) ans = max(ans, (b - (s ^ b)) * n);
			if (c > (s ^ c)) ans = max(ans, (c - (s ^ c)) * m);
			if (d > (s ^ d)) ans = max(ans, (d - (s ^ d)) * n);
			if      ((a - (s ^ a)) * m == ans)
				cout << "horizontal " << a - (s ^ a) << ' ' << ans << '\n';
			else if ((c - (s ^ c)) * m == ans)
				cout << "horizontal " << n - ((c - (s ^ c))) << ' ' << ans << '\n';
			else if ((b - (s ^ b)) * n == ans)
				cout << "vertical " << b - (s ^ b) << ' ' << ans << '\n';
			else if ((d - (s ^ d)) * n == ans)
				cout << "vertical " << m - ((d - (s ^ d))) << ' ' << ans << '\n';
		} else {
			cout << "No winning strategy." << '\n';
		}
	}
	return 0;
}