#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 200000;
int n, k, cnt;
long long ans;
pii a[MAXN+5];
map <int,int> appr;
int Ltmp[MAXN+5], Rtmp[MAXN+5];

class Seg{
public:
	int arr[MAXN*4+5];
	void pull(int now) {
		arr[now] = arr[now*2] + arr[now*2+1];
	}
	void mdy(int p, int k, int now=1, int l=1, int r=MAXN) {
		if (l == p && r == p) {
			arr[now] += k;
			return;
		} else if (l > p || r < p) return;
		int mid = (l+r)>>1;
		mdy(p, k, now*2  , l, mid);
		mdy(p, k, now*2+1,mid+1,r);
		pull(now);
	}
	int qry(int ql, int qr, int now=1, int l=1, int r=MAXN) {
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)>>1, sum = 0;
		sum += qry(ql, qr, now*2  , l, mid);
		sum += qry(ql, qr, now*2+1,mid+1,r);
		return sum;
	}
} L, R;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].ff, appr[a[i].ff] = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i].ss, appr[a[i].ss] = 1;
	for (pii i : appr)
		appr[i.ff] = ++cnt;
	for (int i = 1; i <= n; i++) {
		a[i].ff = appr[a[i].ff];
		a[i].ss = appr[a[i].ss];
	}
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++) {
		if (a[i].ff != a[i-1].ff) {
			int now = i;
			while (a[now].ff == a[i].ff)
				now++;
			Ltmp[i] = now-1;
		}
		Rtmp[i] = n+1;
		if (a[i].ff != a[i+1].ff) {
			int now = i;
			while (a[now].ff == a[i].ff)
				now--;
			Rtmp[i] = now+1;
		}
	}
	for (int i = 1; i <= n; i++)
		R.mdy(a[i].ss, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= Ltmp[i]; j++)
			R.mdy(a[j].ss, -1);
		ans += L.qry(a[i].ss+1, MAXN);
		ans += R.qry(1, a[i].ss-1);
		for (int j = i; j >= Rtmp[i]; j--)
			L.mdy(a[j].ss, 1);
	}
	cout << ans/2 << "\n";
}