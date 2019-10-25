#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 100000
using namespace std;

int n, k, t, ans;
int arr[MAXN+5];

signed main() {
	Hina;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	ans = arr[n-1] - arr[0];
	for (int i = 0; i < n/2; i++) {
		t = min(arr[i+1]-arr[i] + arr[n-i-1]-arr[n-i-2], k / (i+1));
		ans -= t;
		k -= t * (i+1);
	}
	cout << max((int)0, ans) << endl;
	return 0;
}