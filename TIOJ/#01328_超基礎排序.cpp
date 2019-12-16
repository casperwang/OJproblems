#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr+n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " \n"[i==n-1];
	}
}