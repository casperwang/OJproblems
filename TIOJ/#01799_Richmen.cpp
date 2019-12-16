#include <bits/stdc++.h>
#define MAXN 5000000
#define int long long
using namespace std;

int n, ave, ans;
int v[MAXN+5];
int x[MAXN+5];
int c[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		ave += v[i];
	}
	ave /= n;
	for (int i = 2; i <= n; i++) {
		c[i] = c[i-1] - v[i] + ave;
	}
	sort(c+1, c+1+n);
	x[1] = c[(n+1)/2];
	ans = abs(x[1]);
	c[1] = 0;
	for (int i = 2; i <= n; i++) {
		c[i] = c[i-1] - v[i] + ave;
		x[i] = x[1] - c[i];
		ans += abs(x[i]);
	}
	cout << ans << '\n';
}