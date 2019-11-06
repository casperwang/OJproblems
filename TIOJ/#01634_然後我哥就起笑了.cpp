#include <bits/stdc++.h>
using namespace std;
int k, a, s;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> k;
	for (int i = 0; i <= k; i++) {
		cin >> a;
		if (s >= ((1<<i)-1)) s += a*(1<<i);
	}
	cout << s+1 << '\n';
}