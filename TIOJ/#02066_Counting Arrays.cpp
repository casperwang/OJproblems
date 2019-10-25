#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
#define MAXK 70
using namespace std;

const int MOD = (1ll << 61)-1;
int t, n, K, ans;
signed a[MAXN+1], c[MAXN+1];
int dp[MAXN+1][2];

class BIT{
public:
	int arr[MAXN+1];
	int lowbit(int a) { return a&-a; }
	int qry(int a) {
		if (!a) return 0;
		int t = qry(a-lowbit(a))+arr[a];
		return (t>=MOD)?t-MOD:t;
	}
	void mdy(int a, int k) {
		arr[a] = ((arr[a]+k>=MOD)?arr[a]+k-MOD:arr[a]+k);
		if (a+lowbit(a)<MAXN) mdy(a+lowbit(a), k);
	}
} bit;

signed main() {
	Hina;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> K;
		ans = 0;
		for (int j = 1; j <= n; j++) cin >> a[j], c[j] = a[j];
		sort(c+1, c+1+n);
		for (int j = 1; j <= n; j++) {
			a[j] = lower_bound(c+1, c+1+n, a[j])-c;
		}
		for (int j = 1; j <= n; j++) dp[j][0] = 0;
		for (int k = 1; k <= K; k++) {
			memset(bit.arr, 0, sizeof(bit.arr));
			for (int j = 1; j <= n; j++) {
				dp[j][k%2] = bit.qry(a[j]-1)+(k==1);
				if (dp[j][k%2] >= MOD) dp[j][k%2] -= MOD;
				ans += dp[j][k%2];
				bit.mdy(a[j], dp[j][(k+1)%2]);
				if (ans >= MOD) ans -= MOD;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}