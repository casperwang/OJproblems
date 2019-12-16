#include <bits/stdc++.h>
#define MAXN 20000000
#define int long long
using namespace std;

int n, x, sum, cnt;
short arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i], cnt += arr[i] * i;
	}
	while (true) {
		if (cnt % sum == 0) {
			cout << x << " " << cnt/sum << '\n';
			break;
		}
		x++;
		cnt += (n - (x<<1) + 1) * (arr[x-1] - arr[n-x]);
	}
	return 0;
}