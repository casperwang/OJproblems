#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0);
#define MAXN 20000
#define int long long
using namespace std;

int n, ans;
int a[MAXN+5];
int b[MAXN+5];

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n  ; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+n-1, greater<int>());
	for (int i = 0; i < n-1; i++) {
		if (i) a[i] += a[i-1];
		ans += a[i] * b[i];
	}
	cout << ans << endl;
	return 0;
}