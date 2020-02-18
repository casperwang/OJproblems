#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
using namespace std;

const int MAXN = 50;
int n, k, a, b;
int S[MAXN+5];
int P[MAXN+5][MAXN+5];
int U[MAXN+5][MAXN+5];
int L[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		for (int j = 1; j <= 2*k+1; j++)
			cin >> P[i][j];
		for (int j = 1; j <= 2*k+1; j++)
			cin >> U[i][j];
		for (int j = 1; j <= 2*k+1; j++)
			cin >> L[i][j];
	}
	for (int i = 1; i <= n; i++) {
		bool tf = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int m = 1; m <= k+1; m++) {
				if (P[i][m] < P[j][k+m])
					tf = 0;
				else if (P[i][m] == P[j][k+m] && S[j] < S[i])
					tf = 0;
			}
		}
		if (tf) a = max(a, S[i]);
	}
	for (int i = 1; i <= n; i++) {
		bool tf = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int m = 1; m <= k+1; m++) {
				if (U[i][m] < L[j][k+m])
					tf = 0;
				else if (U[i][m] == L[j][k+m] && S[j] < S[i])
					tf = 0;
			}
		}
		if (tf) b = max(b, S[i]);
	}
	cout << a << " " << b << "\n";
	return 0;
}