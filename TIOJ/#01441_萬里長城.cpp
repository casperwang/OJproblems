#include <bits/stdc++.h>
#define MAXN 1000000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, ans, h, l;
int a[MAXN+5];
int appr[MAXN+5];

class Seg{
public:
	int arr[MAXN*4+5];
	void pull(int now) {
		arr[now] = max(arr[now*2], arr[now*2+1]);
	}
	void mdy(int now, int l, int r, int p, int v) {
		if (l >= p && r <= p) {
			arr[now] = max(arr[now], v);
			return;
		} else if (l > p || r < p) return;
		int mid = (l+r)>>1;
		mdy(now*2  , l, mid, p, v);
		mdy(now*2+1,mid+1,r, p, v);
		pull(now);
		return;
	}
	int qry(int now, int l, int r, int ql, int qr) {
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)>>1, tmp = 0;
		tmp = max(tmp, qry(now*2  , l, mid, ql, qr));
		tmp = max(tmp, qry(now*2+1,mid+1,r, ql, qr));
		return tmp;
	}
} H, L;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], appr[i] = a[i];
	sort(appr+1, appr+1+n);
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(appr+1, appr+1+n, a[i])-appr;
	for (int i = 1; i <= n; i++) {
		h = L.qry(1, 1, n, 1, a[i]-1)+1;
		H.mdy(1, 1, n, a[i], h);
		ans = max(ans, h);
		l = H.qry(1, 1, n, a[i]+1, n)+1;
		if (l > 1) L.mdy(1, 1, n, a[i], l);
	}
	cout << ans << '\n';
}