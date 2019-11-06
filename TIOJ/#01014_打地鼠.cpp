#include <bits/stdc++.h>
#define MAXN 16
#define INF 1e18
#define int long long
#define d(a,b) (a>b?a-b:b-a)
#define lb(a) (a&-a)
using namespace std;

int n, arr[MAXN], tmp, ans = INF;
int dp[(1<<MAXN)+5][MAXN];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (register int i = 1; i < (1<<n); i++) {
		if (lb(i) == i) {
			int j = __lg(i);
			dp[i][j] = max(arr[j], (j+arr[j]-1)/arr[j]*arr[j]);
			continue;
		}
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
			tmp = (1<<j);
			if (!(i & tmp)) continue;
			tmp ^= i;
			for (int k = 0; k < n; k++) {
				if (!(i & (1<<k)) || j == k) continue;
				dp[i][j] = min(dp[i][j], (dp[tmp][k]+d(j,k)+arr[j]-1)/arr[j]*arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[(1<<n)-1][i]);
	}
	cout << ans << '\n';
}