#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MOD 1000000007
using namespace std;

int x1, x2, a, b, n;
int A[2][2], ans[2];

void multi(int t[2][2]) {
	int m[2][2], p[2][2];
	m[0][0] = A[0][0], m[0][1] = A[0][1], m[1][0] = A[1][0], m[1][1] = A[1][1];
	p[0][0] = t[0][0], p[0][1] = t[0][1], p[1][0] = t[1][0], p[1][1] = t[1][1];
	swap(p, m);
	t[0][0] = (m[0][0] * p[0][0] + m[1][0] * p[0][1]) % MOD;
	t[0][1] = (m[0][1] * p[0][0] + m[1][1] * p[0][1]) % MOD;
	t[1][0] = (m[0][0] * p[1][0] + m[1][0] * p[1][1]) % MOD;
	t[1][1] = (m[0][1] * p[1][0] + m[1][1] * p[1][1]) % MOD;
}

void pw(int n) {
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) {
			int tmp[2];
			tmp[0] = A[0][0] * ans[0] + A[0][1] * ans[1];
			tmp[1] = A[1][0] * ans[0] + A[1][1] * ans[1];
			ans[0] = tmp[0] % MOD, ans[1] = tmp[1] % MOD;
		}
		multi(A);
	}
	return;
}

signed main() {
	Hina;
	cin >> x1 >> x2 >> a >> b >> n;
	A[0][0] = b, A[0][1] = a, A[1][0] = 1, A[1][1] = 0;
	ans[0] = x2, ans[1] = x1;
	n -= 1, pw(n);
	cout << (ans[1])%MOD << endl;
	return 0;
}