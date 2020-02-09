#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

const int MAXN = 1000;
int n, w, m, s, now, cnt;
int a[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> w) {
		if (!n && !w) return 0;
		m = s = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i], m = max(m, a[i]), s += a[i];
		int l = m, r = s, mid;
		while (l < r) {
			mid = (l+r)>>1;
			now = cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (now + a[i] > mid)
					cnt++, now = 0;
				now += a[i];
			}
			if (cnt > w) l = mid+1;
			else r = mid;
		}
		cout << l << "\n";
	}
	return 0;
}