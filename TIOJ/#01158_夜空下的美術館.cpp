#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << 2*n*n-n+1 << '\n';
	}
	return 0;
}