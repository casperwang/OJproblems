#include <bits/stdc++.h>
#define MAXN 50000
using namespace std;

int n;
long long ans;
int a[MAXN+5], b[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a, a+n), sort(b, b+n);
		for (int i = 0; i < n; i++) ans += a[i]*b[i];
		cout << ans << '\n';
	}
}