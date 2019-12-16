#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int n, k;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> k) {
		if (!n && !k) return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr+n, greater<int>());
		cout << arr[k-1] << '\n';
	}
	return 0;
}