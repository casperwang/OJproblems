#include <bits/stdc++.h>
#define MAXN 5000
#define max(a,b) (a>b?a:b)
using namespace std;

struct task{
	int c, a, p;
} arr[MAXN+5];
int n, C, P, ans;
int dp[MAXN+5];

bool cmp(const task a, const task b) {
	return a.c < b.c;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> C >> P;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].c >> arr[i].a >> arr[i].p;
		arr[i].a -= arr[i].c;
	}
	dp[P] = C;
	sort(arr, arr+n, cmp);
	for (int i = 0; i < n; i++) {
		for (int j = arr[i].p; j <= P; j++) {
			if (dp[j] < arr[i].c) continue;
			dp[j-arr[i].p] = max(dp[j-arr[i].p], dp[j]+arr[i].a);
		}
	}
	for (int i = 1; i <= P; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}