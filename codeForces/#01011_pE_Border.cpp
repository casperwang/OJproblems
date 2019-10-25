#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
using namespace std;

int n, k, m;
int a[MAXN+5];

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

signed main() {
	Hina;
	cin >> n >> k;
	m = k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= k;
		m = gcd(m, a[i]);
	}
	cout << k/m << endl;
	for (int i = 0; i < k; i += m) {
		cout << i << " \n"[i==k-m];
	}
	return 0;
}