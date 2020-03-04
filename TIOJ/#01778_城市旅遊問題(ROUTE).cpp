#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100;
const int MOD = 1000000009;
int n, m, s, t, k;
int a, b;
int arr[MAXN+5][MAXN+5];

void mul(int a[MAXN+5][MAXN+5], int b[MAXN+5][MAXN+5]) {
	int t[MAXN+5][MAXN+5];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			t[i][j] = 0;
			for (int k = 1; k <= n; k++)
				t[i][j] += (a[i][k] * b[k][j]) % MOD;
			t[i][j] %= MOD;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = t[i][j];
}

void pw(int arr[MAXN+5][MAXN+5], int k) {
	int t[MAXN+5][MAXN+5];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			t[i][j] = (i==j);
	for (int i = 1; i <= k; i<<=1) {
		if (i & k) mul(t, arr);
		mul(arr, arr);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = t[i][j];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> s >> t >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b]++, arr[b][a]++;
	}
	pw(arr, k);
	cout << arr[s][t] << "\n";
	return 0;
}
