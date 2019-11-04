#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int m, p, n, a, t;
int ans;
vector <int> arr;

signed main() {
	cin >> m >> p >> n;
	arr.pb(0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.pb(a);
	}
	arr.pb(p);
	int now = 0;
	for (int i = 0; i < n; i++) {
		t = arr[upper_bound(arr.begin(), arr.end(), now+m)-arr.begin()-1];
		if (t == p) break;
		if (t == now) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		now = t, ans++;
	}
	cout << ans << endl;
	return 0;
}