#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 50
#define INF 1e9
using namespace std;

int n, m, ans, sum;
int arr[MAXN+5][MAXN+5];

signed main() {
	Hina;
	while (cin >> n >> m) {
		ans = -INF;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
				ans = max(ans, arr[i][j]);
				arr[i][j] += arr[i-1][j];
			}
		}
		for (int l = 0; l < n; l++) {
			for (int r = 1; r <= n; r++) {
				if (l >= r) continue;
				sum = 0;
				for (int j = 1; j <= m; j++) {
					sum += arr[r][j] - arr[l][j];
					ans = max(ans, sum);
					if (sum < 0) sum = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}