#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
using namespace std;

int n, m, p;
int ans;
int arr[MAXN+5];

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> arr[j];
		}
		ans = 0;
		sort(arr, arr+m);
		p = lower_bound(arr, arr+m, (arr[0]+arr[m-1]+1)/2) - arr;
		ans = max(ans, arr[m-1] - arr[p]);
		if (p) ans = max(ans, arr[p-1] - arr[0]);
		cout << ans << endl;
	}
	return 0;
}