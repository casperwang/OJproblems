#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n;
int ans[30];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 2; i < 30; i++)
		ans[i] = pow(3, i-1)-ans[i-1];
	while (t--) {
		cin >> n;
		cout << ans[n] << '\n';
	}
}