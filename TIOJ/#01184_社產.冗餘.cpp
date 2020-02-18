#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

const int INF = 1e18;
int t, n, m;
int v, c, ans;
vector <int> arr;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		arr.clear(), ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> v >> c;
			while (c--) arr.pb(v);
		}
		sort(arr.begin(), arr.end());
		if (arr.size() < m) {
			cout << "so sad\n";
			continue;
		}
		for (int i = 0; i < m; i++) {
			ans += arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}