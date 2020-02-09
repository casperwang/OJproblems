#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

int n, m, k, p, t, ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> k) {
		ans = 0, m = 1, p = (10-k)%10, t = n;
		while (n) {
			ans += (n+p-1)/10*m + ((n+p)%10==0)*(t%m+1);
			n /= 10, m *= 10;
		}
		cout << ans << "\n";
	}
}