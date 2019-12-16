#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int t, n;

int pw(int a, int n) {
	int t = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) t = (t * a) % MOD;
		a = (a * a) % MOD;
	}
	return t;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << pw(4, n-1) << '\n';
	}
  return 0;
}