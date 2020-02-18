#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

int n, ans, tf;
string s;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] - '0' == tf) {
			if (!i || s[i-1] - '0' != tf)
				ans++;
			else
				ans++, tf = !tf;
		}
	}
	cout << ans << "\n";
	return 0;
}