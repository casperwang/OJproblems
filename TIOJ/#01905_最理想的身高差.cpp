#include <bits/stdc++.h>
#pragma GCC optimize("O1,O2,Os,Ofast,O3,unroll-loops")
#define ppi pair<pii,int>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100000;
const int INF = (1<<30);
int n, q;
int v, l, r, t;
int cnt, nowL;
int arr[MAXN+1];
int num[MAXN+1];
int ans[MAXN+1];
ppi qry[MAXN+1];

inline char readchar() {
	static const size_t bufsize = 65536;
	static char buf[bufsize];
	static char *p = buf, *end = buf;
	if (p == end)
		end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
	return p==end?EOF:*p++;
}

inline void Read(int &p) {
	p = 0;
	char c = readchar();
	while (c < '0' || c > '9')
		c = readchar();
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
}

class Seg{
public:
	int arr[MAXN*4+5];
	void pull(int now) {
		arr[now] = min(arr[now*2], arr[now*2+1]);
	}
	void build(int now=1, int l=1, int r=MAXN) {
		if (l == r) {
			arr[now] = INF;
			return;
		}
		int mid = l + r >> 1;
		build(now*2  , l, mid);
		build(now*2+1,mid+1,r);
		pull(now);
	}
	void mdy(int pos, int k, int now=1, int l=1, int r=MAXN) {
		if (l == pos && r == pos) {
			arr[now] = min(arr[now], k);
			return;
		} else if (l > pos || r < pos) return;
		int mid = l + r >> 1;
		mdy(pos, k, now*2  , l, mid);
		mdy(pos, k, now*2+1,mid+1,r);
		pull(now);
	}
	int qry(int ql, int qr, int now=1, int l=1, int r=MAXN) {
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return INF;
		int mid = l + r >> 1, mmin = INF;
		mmin = min(mmin, qry(ql, qr, now*2  , l, mid));
		mmin = min(mmin, qry(ql, qr, now*2+1,mid+1,r));
		return mmin;
	}
} pos_seg, val_seg;

signed main() {
	Read(n);
	for (int i = 1; i <= n; i++)
		Read(arr[i]), num[i] = arr[i];
	sort(num+1, num+1+n);
	for (int i = 1; i <= n; i++)
		arr[i] = lower_bound(num+1, num+1+n, arr[i])-num;
	Read(q);
	for (int i = 0; i < q; i++) {
		Read(qry[i].ff.ff), Read(qry[i].ff.ss);
		qry[i].ss = i;
	}
	sort(qry, qry+q, greater<ppi>());
	pos_seg.build();
	val_seg.build();
	nowL = n+1;
	for (int i = 0; i < q; i++) {
		while (qry[i].ff.ff < nowL) {
			v = arr[--nowL];
			r = val_seg.qry(v, MAXN);
			while (r != INF && arr[r] >= v) {
				pos_seg.mdy(r, num[arr[r]] - num[v]);
				r = val_seg.qry(v, lower_bound(num+1, num+1+n, num[arr[r]] + num[v] >> 1)-1-num);
			}
			l = val_seg.qry(1, v);
			while (l != INF && arr[l] <= v) {
				pos_seg.mdy(l, num[v] - num[arr[l]]);
				l = val_seg.qry(upper_bound(num+1, num+1+n, num[v] + num[arr[l]] >> 1)-num, v);
			}
			val_seg.mdy(v, nowL);
		}
		ans[qry[i].ss] = pos_seg.qry(qry[i].ff.ff, qry[i].ff.ss);
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
}