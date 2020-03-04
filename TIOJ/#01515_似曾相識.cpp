#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int k1 = 9807;
const int k2 = 1231;
const int MOD = 1000000007;
int n, m1, m2, p1, p2;
int l, r, mid;
unordered_set <signed> appr1, appr2;
bool tf;
string s;

int h1(int now) {
	return (now * k1) % MOD;
}

int h2(int now) {
	return (now * k2) % MOD;
}

int pw(int a, int n) {
	int t = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) t = (t * a) % MOD;
		a = (a * a) % MOD;
	}
	return t;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	l = 0, r = n-1;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		tf = 0;
		p1 = 0, m1 = pw(k1, mid);
		p2 = 0, m2 = pw(k2, mid);
		appr1.clear(), appr2.clear();
		for (int i = 0; i < mid; i++) {
			p1 = h1(p1) + s[i];
			p2 = h2(p2) + s[i];
		}
		appr1.insert(p1 % MOD);
		appr2.insert(p2 % MOD);
		for (int i = mid; i < n; i++) {
			p1 = h1(p1) + s[i] - m1 * s[i-mid];
			p1 = (p1 % MOD + MOD) % MOD;
			p2 = h2(p2) + s[i] - m2 * s[i-mid];
			p2 = (p2 % MOD + MOD) % MOD;
			if (appr1.count(p1) && appr2.count(p2)) {
				tf = 1;
				break;
			}
			appr1.insert(p1), appr2.insert(p2);
		}
		if (tf) l = mid;
		else r = mid-1;
	}
	cout << l << "\n";
	return 0;
}