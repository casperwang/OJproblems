#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 10
using namespace std;

int n, k, a, m;
int ans[MAXN+5][MAXN+5];

signed main() {
	Hina;
	for (int v = 1; v <= MAXN; v++) {
		for (int i = 0; i < (1<<v); i++) {
			a = m = 0;
			for (int j = 0; j < v; j++) {
				if (i & (1<<j)) a++;
				else a = 0;
				m = max(m, a);
			}
			for (int j = m+1; j <= MAXN; j++) {
				ans[v][j]++;
			}
		}
	}
	while (cin >> n >> k) {
		cout << ans[n][k] << endl;
	}
	return 0;
}