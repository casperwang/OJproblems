#include <bits/stdc++.h>
#define MAXN 500000
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

int n, q;
int t, x, y, k;
int v[MAXN+5];

class Seg{
public:
	int arr[MAXN*4+5];
	int tag[MAXN*4+5];
	void push(int now, int len) {
		if (tag[now]) {
			arr[now] += tag[now]*len;
			if (len>1)
				tag[now*2] += tag[now], tag[now*2+1] += tag[now];
			tag[now] = 0;
		}
	}
	void pull(int now) {
		arr[now] = arr[now*2]+arr[now*2+1];
	}
	void build(int now, int l, int r) {
		if (l==r) {
			arr[now] = v[l];
			return;
		}
		int mid = (l+r)/2;
		build(now*2  , l, mid);
		build(now*2+1,mid+1,r);
		pull(now);
		return;
	}
	void mdy(int now, int l, int r, int ml, int mr, int k) {
		push(now, r-l+1);
		if (l >= ml && r <= mr) {
			tag[now] += k;
			push(now, r-l+1);
			return;
		} else if (l > mr || r < ml) return;
		int mid = (l+r)/2;
		mdy(now*2  , l, mid, ml, mr, k);
		mdy(now*2+1,mid+1,r, ml, mr, k);
		pull(now);
		return;
	}
	int qry(int now, int l, int r, int ql, int qr) {
		push(now, r-l+1);
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)/2, sum=0;
		sum += qry(now*2  , l, mid, ql, qr);
		sum += qry(now*2+1,mid+1,r, ql, qr);
		pull(now);
		return sum;
	}
} seg;

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	seg.build(1, 1, n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> k;
			seg.mdy(1, 1, n, x, y, k);
		} else {
			cin >> x >> y;
			cout << seg.qry(1, 1, n, x, y) << endl;
		}
	}
	return 0;
}