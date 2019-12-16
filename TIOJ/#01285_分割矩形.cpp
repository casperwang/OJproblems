#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int a, b, ans;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		ans += a/b;
		return gcd(b, a%b);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> a >> b) {
		ans = 0;
		gcd(a, b);
		cout << ans << '\n';
	}
}