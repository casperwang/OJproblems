#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 20;
const int INF = 1e18;
const int MOD = 1000000007;
int n;
int c[MAXN], v[MAXN];

int f(int a, int n) {
	if (!n) return 0;
	if (a == 1) return min(n, c[a]+1);
	int k = min(n / v[a], c[a]);
	int x = f(a-1, v[a]), y = f(a-1, n-v[a]*k);
	if (k * v[a] == n)
		return (x * k) % MOD;
	else
		return (x * k + y) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	v[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (i>1) v[i] = v[i-1]*(i%2?2:5);
	}
	v[n+1] = v[n]*(n%2?5:2);
	cout << f(n, INF)-1 << "\n";
}