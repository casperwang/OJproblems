#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
#define pii pair<int,int>
#define ff first
#define ss second
#define INF 1e18
using namespace std;

class Seg{
public:
	int arr[MAXN*4+5];
	int tag[MAXN*4+5];
	void pull(int now) {
		arr[now] = min(arr[now*2], arr[now*2+1]);
	}
	void push(int now, int len) {
		if (!tag[now]) return;
		arr[now] += tag[now];
		if (len > 1) {
			tag[now*2  ] += tag[now];
			tag[now*2+1] += tag[now];
		}
		tag[now] = 0;
	}
	void mdy(int now, int l, int r, int ml, int mr, int k) {
		push(now, r-l+1);
		if (l >= ml && r <= mr) {
			tag[now] += k;
			push(now, r-l+1);
			return;
		} else if (l > mr || r < ml) return;
		int mid = (l+r)>>1;
		mdy(now*2  , l, mid, ml, mr, k);
		mdy(now*2+1,mid+1,r, ml, mr, k);
		pull(now);
		return;
	}
	int qry(int now, int l, int r, int ql, int qr) {
		push(now, r-l+1);
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return INF;
		int mid = (l+r)>>1, t = INF;
		t = min(t, qry(now*2  , l, mid, ql, qr));
		t = min(t, qry(now*2+1,mid+1,r, ql, qr));
		pull(now);
		return t;
	}
} seg;

int n, L;
int h, w[MAXN+5];
int now, s, dp;
pii t;
stack <pii> d;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> L;
	d.push(pii(INF, 0));
	now = 1;
	for (int i = 1; i <= n; i++) {
		cin >> h >> w[i];
		s += w[i];
		while (h >= d.top().ff) {
			t = d.top();
			d.pop();
			seg.mdy(1, 1, n, d.top().ss+1, t.ss, -t.ff);
		}
		seg.mdy(1, 1, n, d.top().ss+1, i, h);
		d.push(pii(h, i));
		while (s > L) s -= w[now++];
		dp = seg.qry(1, 1, n, now, i);
		seg.mdy(1, 1, n, i+1, i+1, dp);
	}
	cout << dp << '\n';
}