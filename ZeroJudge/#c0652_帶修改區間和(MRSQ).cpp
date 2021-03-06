#include <bits/stdc++.h>
#define MAXN 300000
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define pb push_back
using namespace std;

int n, q;
int t, x, y, k;
int v[MAXN+5];

class Seg{
public:
	int arr[MAXN*4+5];
	bool tag[MAXN*4+5];
	void push(int now, int len) {
		if (tag[now]) {
			if (len > 1) {
				tag[now*2]   = tag[now];
				tag[now*2+1] = tag[now];
				if (arr[now*2]!=len-len/2) push(now*2, len-len/2);
				if (arr[now*2+1]!=len/2) push(now*2+1, len/2);
				pull(now);
			} else arr[now] = floor(sqrt(arr[now]));
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
	void mdy(int now, int l, int r, int ml, int mr) {
		if (l >= ml && r <= mr) {
			tag[now] += 1;
			if (arr[now] != r-l+1) push(now, r-l+1);
			return;
		} else if (l > mr || r < ml) return;
		int mid = (l+r)/2;
		mdy(now*2  , l, mid, ml, mr);
		mdy(now*2+1,mid+1,r, ml, mr);
		pull(now);
		return;
	}
	int qry(int now, int l, int r, int ql, int qr) {
		if (arr[now] == r-l+1) return max((int)0, min(r, qr)-max(l, ql)+1);
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)/2, sum = 0;
		sum += qry(now*2  , l, mid, ql, qr);
		sum += qry(now*2+1,mid+1,r, ql, qr);
		pull(now);
		return sum;
	}
} seg;

signed main() {
	Hina;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> v[i];
	seg.build(1, 1, n);
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			seg.mdy(1, 1, n, x, y);
		} else {
			cin >> x >> y;
			cout << seg.qry(1, 1, n, x, y) << endl;
		}
	}
	return 0;
}