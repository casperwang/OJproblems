#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 100000;
const int INF = 1e18;
int n, a;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i <= MAXN; i++)
		arr[i] = INF;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[upper_bound(arr, arr+n, a)-arr] = a;
	}
	cout << upper_bound(arr, arr+n, INF-1)-arr << "\n";
	return 0;
}