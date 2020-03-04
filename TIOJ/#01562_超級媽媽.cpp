#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100;
int n, k, sum, cnt, tmp, mmax;
int l, r, mid;
int a[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> k) {
		sum = mmax = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
			mmax = max(mmax, a[i]);
		}
		l = mmax, r = sum;
		while (l < r) {
			mid = (l+r)>>1;
			tmp = 0, cnt = 1;
			for (int i = 1; i <= n; i++) {
				if (tmp + a[i] > mid)
					tmp = 0, cnt++;
				tmp += a[i];
			}
			if (cnt > k) l = mid+1;
			else r = mid;
		}
		cout << l << "\n";
	}
}