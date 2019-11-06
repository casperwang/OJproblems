#include <bits/stdc++.h>
#define int long long
#define MOD ((int)1<<32)
using namespace std;

int n, a, b, x, y;
int A[2][2], ans[2][2];

int m(int a, int b) {
	int tmp = 0;
	for (int i = 1; i <= b; i *= 2) {
		if (i & b) tmp = (tmp + a) % MOD;
		a = (a + a) % MOD;
	}
	return tmp;
}

void mul(int A[2][2], int B[2][2]) {
	int C[2][2];
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++)
			C[i][j] = m(A[i][0], B[0][j]) + m(A[i][1], B[1][j]);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			A[i][j] = C[i][j] % MOD;
}

void pw(int n) {
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) mul(ans, A);
		mul(A, A);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (n < 0) return 0;
		cin >> a >> b >> x >> y;
		A[0][0] = y, A[0][1] = x, A[1][0] = 1, A[1][1] = 0;
		ans[0][0] = ans[1][1] = 1;
		ans[0][1] = ans[1][0] = 0;
		pw(n);
		cout << (m(ans[1][0], b) + m(ans[1][1],a)) % MOD << '\n';
	}
	return 0;
}