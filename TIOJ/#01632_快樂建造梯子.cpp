#include <bits/stdc++.h>
#define MAXN 200000
#define int long long
using namespace std;

int n, k, t, cnt;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	int l = 1, r = arr[n-1]-arr[0], mid;
	while (l < r) {
		mid = (l+r)>>1, cnt = 0;
		for (int i = 1; i < n; i++) {
			t = lower_bound(arr,arr+i,arr[i]-mid)-arr;
			cnt += i-t;
		}
		if (cnt < k) l = mid+1;
		else r = mid;
	}
	cout << l << '\n';
	return 0;
}