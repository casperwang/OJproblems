#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int a, b;
int A[2][2], ans[2][2];

void mul(int a[2][2], int b[2][2]) {
	int tmp[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tmp[i][j] = a[i][0]*b[0][j]+a[i][1]*b[1][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = tmp[i][j] % MOD;
	return;
}

int pw(int n) {
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) mul(ans, A);
		mul(A, A);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ans[0][0] = ans[1][1] = 1;
	A[0][0] = A[0][1] = A[1][0] = 1;
	cin >> a >> b;
	pw(__gcd(a+1, b+1));
	cout << ans[0][1] << '\n';
}