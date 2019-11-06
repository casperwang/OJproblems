#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define int long long
using namespace std;

int m, q, a;

int gcd(int a, int b) {
	return (!b)?a:gcd(b,a%b);
}

pii extgcd(int a, int b) {
	if (!b) return {1,0};
	pii t = extgcd(b, a%b);
	return pii(t.ss, t.ff - t.ss * (a / b));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> m >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		if (gcd(a,m) != 1) cout << "jizz" << '\n';
		else cout << (extgcd(a, m).ff%m+m)%m << '\n';
	}
	return 0;
}