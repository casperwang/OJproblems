#include <bits/stdc++.h>
#define p 103
#define MAXN 20
using namespace std;

int n, a, ans, sum;
int arr[MAXN+5][MAXN+5];
int pre[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> a) {
		ans = 0;
		arr[1][1] = a;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i+j == 2) continue;
				if (j == 1) arr[i][j] = arr[1][1]+i;
				else arr[i][j] = (arr[i][j-1]*17)%103*((i+j)%2?-1:1);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				pre[i][j] = pre[i][j-1]+arr[i][j];
			}
		}
		for (int l = 1; l <= n; l++) {
			for (int r = l; r <= n; r++) {
				sum = 0;
				for (int i = 1; i <= n; i++) {
					sum += pre[i][r]-pre[i][l-1];
					ans = max(ans, sum);
					if (sum < 0) sum = 0;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}