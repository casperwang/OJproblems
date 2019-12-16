#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, sum;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr+n);
		sum = 0;
		for (int i = 1; i < n-1; i++)
			sum += arr[i];
		cout << fixed << setprecision(2) << (double)sum/(n-2) << '\n';
	}
}