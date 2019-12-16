#include <bits/stdc++.h>
#define MAXN 50000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n;
long long ans;
int a[MAXN+5];
int b[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		ans = 0;
		for (register int i = 0; i < n; i++) cin >> a[i];
		for (register int i = 0; i < n; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+n, greater<int>());
		for (register int i = 0; i < n; i++) ans += a[i]*b[i];
		cout << ans << '\n';
	}
	return 0;
}