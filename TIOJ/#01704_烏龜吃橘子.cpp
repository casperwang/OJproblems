#include <bits/stdc++.h>
#define MAXN 2000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, k;
pii a[MAXN+5];
int dp[MAXN+5];
int mmax[MAXN+5];
int arr[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].ff, a[i].ss = i;
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int j = 1; j <= n; j++) {
		for (int i = j; i <= n; i++) {
			dp[i] = mmax[i-1]+arr[a[i].ss][j];
			if (dp[i] >= k) {
				cout << j << '\n';
				return 0;
			}
		}
		mmax[j-1] = -2147483647;
		for (int i = j; i <= n; i++)
			mmax[i] = max(mmax[i-1], dp[i]);
	}
	cout << -1 << '\n';
	return 0;
}