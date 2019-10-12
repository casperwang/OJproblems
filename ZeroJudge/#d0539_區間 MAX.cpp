#include <bits/stdc++.h>
#define MAXN 500000
#define Hina ios_base::sync_with_stdio(false),cin.tie(0)
using namespace std;

int n, m;
int a, b;
int SP[MAXN+5][50];

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> SP[i][0];
	}
	for (int k = 2, j = 1; k <= n; k *= 2, j++) {
		for (int i = 1; i <= n-k+1; i++) {
			SP[i][j] = max(SP[i][j-1],SP[i+k/2][j-1]);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		int p = floor(log2(b-a+1));
		cout << max(SP[a][p], SP[b-(1<<p)+1][p]) << '\n';
	}
	return 0;
}