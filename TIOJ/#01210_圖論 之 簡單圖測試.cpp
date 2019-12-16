#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int n, sum;
int pre, suf[MAXN+5], now;
int arr[MAXN+5];
bool tf;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		suf[n+1] = sum = pre = 0, tf = 1;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		tf &= !(sum % 2);
		sort(arr+1, arr+1+n, greater<int>());
		for (int i = n; i >= 1; i--)
			suf[i] = suf[i+1] + arr[i];
		now = n;
		for (int i = 1; i <= n; i++) {
			now = i > now ? i : now;
			pre += arr[i];
			while (now > i && arr[now] <= i) --now;
			tf &= (pre <= i*(now-1)+suf[now+1]);
		}
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}