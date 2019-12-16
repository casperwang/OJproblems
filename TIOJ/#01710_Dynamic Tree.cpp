#include <bits/stdc++.h>
#define MAXN 50000
#define MAXK 100000
#define pb push_back
#define lb(a) (a&-a)
using namespace std;

int t, n, mmax;
long long ans;
int arr[MAXN+5];
int l[MAXN+5], r[MAXN+5];

class BIT{
public:
	int arr[MAXK+5];
	void init(int n) {
		memset(arr, 0, n*sizeof(int)+4);
	}
	void mdy(int now) {
		if (now > MAXK) return;
		arr[now]++;
		mdy(now+lb(now));
	}
	int qry(int now) {
		return now?arr[now]+qry(now-lb(now)):0;
	}
} bit;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = mmax = 0;
		for (int i = 1; i <= n; i++)
			cin >> arr[i], mmax = max(mmax, arr[i]);
		bit.init(mmax);
		for (int i = 1; i <= n; i++) {
			l[i] = bit.qry(arr[i]);
			bit.mdy(arr[i]);
		}
		bit.init(mmax);
		for (int i = n; i >= 1; i--) {
			r[i] = n-i-bit.qry(arr[i]);
			bit.mdy(arr[i]);
		}
		for (int i = 1; i <= n; i++) ans += l[i] * r[i];
		bit.init(mmax);
		for (int i = 1; i <= n; i++) {
			l[i] = i-1-bit.qry(arr[i]);
			bit.mdy(arr[i]);
		}
		bit.init(mmax);
		for (int i = n; i >= 1; i--) {
			r[i] = bit.qry(arr[i]);
			bit.mdy(arr[i]);
		}
		for (int i = 1; i <= n; i++) ans += l[i] * r[i];
		cout << ans << '\n';
	}
}