#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
using namespace std;

int n, q, op, l, r, k;
int a[MAXN+5];
int d[MAXN+5];

int gcd(int a, int b) {
	return (!b) ? a : gcd(b, a%b);
}

class BIT{
public:
	int arr[MAXN+5];
	int lowbit(int a) { return a&-a; }
	void build(int n) {
		for (int i = 1; i <= n; i++)
			arr[i] = a[i] - a[i - lowbit(i)];
	}
	void mdy(int now, int k) {
		if (now > MAXN) return;
		arr[now] += k;
		mdy(now + lowbit(now), k);
	}
	int qry(int now) {
		return now ? arr[now] + qry(now - lowbit(now)) : 0;
	}
} bit;

class Seg{
public:
	int arr[MAXN*4+5];
	void pull(int now) {
		arr[now] = gcd(arr[now*2], arr[now*2+1]);
	}
	void build(int now, int l, int r) {
		if (l == r) {
			arr[now] = d[l];
			return;
		}
		int mid = (l+r)>>1;
		build(now*2  , l, mid);
		build(now*2+1,mid+1,r);
		pull(now);
	}
	void mdy(int now, int l, int r, int p, int k) {
		if (l == p && r == p) {
			arr[now] += k;
			return;
		} else if (l > p || r < p) return;
		int mid = (l+r)>>1;
		mdy(now*2  , l, mid, p, k);
		mdy(now*2+1,mid+1,r, p, k);
		pull(now);
	}
	int qry(int now, int l, int r, int ql, int qr) {
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)>>1, tmp = 0;
		tmp = gcd(tmp, qry(now*2  , l, mid, ql, qr));
		tmp = gcd(tmp, qry(now*2+1,mid+1,r, ql, qr));
		return tmp;
	}
} seg;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i-1];
	}
	bit.build(n);
	seg.build(1, 1, n);
	for (int i = 0; i < q; i++) {
		cin >> op >> l >> r;
		if (op == 1) {
			cin >> k;
			bit.mdy(  l, k);
			bit.mdy(r+1,-k);
			seg.mdy(1, 1, n,  l, k);
			seg.mdy(1, 1, n,r+1,-k);
		} else {
			cout << abs(gcd(bit.qry(l), seg.qry(1, 1, n, l+1, r))) << '\n';
		}
	}
	return 0;
}