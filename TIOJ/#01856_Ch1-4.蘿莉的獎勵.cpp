#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int t, n, ans;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr+n, greater<int>());
		for (int i = 0; i < n; i++) {
			if (i+1 >= arr[i]) break;
			ans += arr[i] - (i+1);
		}
		cout << ans << '\n';
	}
}