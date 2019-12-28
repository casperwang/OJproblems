#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, m, ans;
int a[MAXN+5], b[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(b, b+m);
	for (int i = 0; i < n; i++) {
		if (*lower_bound(b, b+m, a[i]) == a[i])
			continue;
		if ((n-(lower_bound(b, b+m, a[i])-b))%2 == 0)
			ans++;
	}
	cout << ans << '\n';
}