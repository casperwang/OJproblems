#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define N 150
#define MOD 1000000009
using namespace std;

int n, m, q, l;
int a, b;
int path[N+5][N+5], ans[N+5][N+5];

void mul(int A[N+5][N+5], int B[N+5][N+5], int C[N+5][N+5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= MOD;
			}
		}
	}
	return;
}

void pw(int A[N+5][N+5], int len, int ans[N+5][N+5]) {
	int tmpA[N+5][N+5], tAns[N+5][N+5];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) ans[i][j] = 1;
			else ans[i][j] = 0;
		}
	}
	int p = 1;
	for (; p <= len; p <<= 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//cout << A[i][j] << " ";
				tmpA[i][j] = A[i][j];
				tAns[i][j] = ans[i][j];
			}
			//cout << endl;
		}
		//cout << endl;
		if (p & len) mul(tAns, tmpA, ans);
		mul(tmpA, tmpA, A);
	}
}

signed main() {
	Hina;
	cin >> n >> m >> q >> l;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		path[a][b]++;
	}
	pw(path, l, ans);
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << ans[a][b] << endl;
	}
	return 0;
}