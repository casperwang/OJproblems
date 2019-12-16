#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, arr[MAXN+5], ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			for (int j = 1; j < i; j++)
				ans += (arr[i] < arr[j]);
		}
		cout << ans << '\n';
	}
}