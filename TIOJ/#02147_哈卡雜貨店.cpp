#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define INF 1e18
#define MAXN 200
using namespace std;

int n, K, ans;
int arr[MAXN+5];
int cpy[MAXN+5];
int t[MAXN+5];
int dp[MAXN+5][MAXN+5][MAXN+5];

signed main() {
	Hina;
	ans = INF;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cpy[i] = arr[i];
	}
	sort(cpy+1, cpy+1+n);
	for (int i = 1; i <= n; i++) {
		arr[i] = lower_bound(cpy+1, cpy+1+n, arr[i]) - cpy;
	}
	for (int k = 1; k <= K; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j][k] = INF;
			}
		}
	}
	t[0] = INF;
	for (int k = 1; k <= K; k++) {
		if (k > 1) for (int i = 1; i <= n; i++) t[i] = INF;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i] > j || k > i) continue;
				dp[i][j][k] = t[j];
				dp[i][j][k] += cpy[j] - cpy[arr[i]];
				//cout << dp[i][j][k] << " \n"[j==n];
				if (k == K) ans = min(ans, dp[i][j][k]);
			}
			for (int j = arr[i]; j <= n; j++) {
				t[j] = min(t[j], dp[i][j][k-1]);
				t[j] = min(t[j], t[j-1]);
			}
		}
		//cout << endl;
	}
	cout << ans << endl;
	return 0;
}