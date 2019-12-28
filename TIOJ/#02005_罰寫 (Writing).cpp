#include <bits/stdc++.h>
#define vv vector<vector<int>>
using namespace std;

int n, m;
vv A, ans;

vv operator *(vv A, vv B) {
	vv t;
	t.resize(A.size());
	for (int i = 0; i < t.size(); i++)
		t[i].resize(A.size());
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			for (int k = 0; k < t.size(); k++) {
				t[i][j] = (t[i][j] + A[i][k] * B[k][j]) % m;
			}
		}
	}
	return t;
}

vv operator ^(vv A, int p) {
	vv t;
	t.resize(A.size());
	for (int i = 0; i < t.size(); i++) {
		t[i].resize(A.size());
		t[i][i] = 1;
	}
	for (int i = 1; i <= p; i *= 2) {
		if (i & p) t = t * A;
		A = A * A;
	}
	return t;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		A.clear();
		A.resize(3);
		for (int i = 0; i < 3; i++)
			A[i].resize(3);
		A[0][0] = 10, A[0][1] = A[0][2] = 1;
		A[1][1] = A[1][2] = A[2][2] = 1;
		ans.clear();
		ans.resize(3);
		for (int i = 0; i < 3; i++)
			ans[i].resize(3);
		ans[0][0] = ans[1][1] = ans[2][2] = 1;
		for (int i = 1; i <= n; i *= 10) {
			if (n < i*10) {
				ans = (A ^ (n-i+1)) * ans;
				break;
			}
			ans = (A ^ (i*9)) * ans;
			A[0][0] = (A[0][0] * 10) % m;
		}
		cout << ans[0][2] << '\n';
	}
}