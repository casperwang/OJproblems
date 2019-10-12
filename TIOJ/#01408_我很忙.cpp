#include <bits/stdc++.h>
#define MAXN 100010
#define ff first
#define ss second
using namespace std;

int n;
int sum, tmp, nnd;
pair <pair<int, int>, int> arr[MAXN+5];

bool cmp(const pair <pair<int, int>, int> a, const pair <pair<int, int>, int> b) {
	return a.ff.ss < b.ff.ss;
}

class Seg{
public:
	int arr[MAXN*4+5];
	bool tag[MAXN*4+5];
	void push(int now, int len) {
		if (!tag[now]) return;
		arr[now] = len;
		if (len > 1) {
			tag[now*2  ] = 1;
			tag[now*2+1] = 1;
		}
		tag[now] = 0;
	}
	void pull(int now) {
		arr[now] = arr[now*2] + arr[now*2+1];
	}
	void build(int now, int l, int r) {
		arr[now] = tag[now] = 0;
		if (l == r) return;
		int mid = (l+r)/2;
		build(now*2  , l, mid);
		build(now*2+1,mid+1,r);
		return;
	}
	void mdy(int now, int l, int r, int ml, int mr) {
		push(now, r-l+1);
		if (l >= ml && r <= mr) {
			tag[now]=1;
			push(now, r-l+1);
			return;
		} else if (l > mr || r < ml) return;
		int mid = (l+r)/2;
		mdy(now*2  , l, mid, ml, mr);
		mdy(now*2+1,mid+1,r, ml, mr);
		pull(now);
		return;
	}
	int qry(int now, int l, int r, int ql, int qr) {
		push(now, r-l+1);
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return 0;
		int mid = (l+r)/2, tmp = 0;
		tmp += qry(now*2  , l, mid, ql, qr);
		tmp += qry(now*2+1,mid+1,r, ql, qr);
		pull(now);
		return tmp;
	}
} seg;

signed main() {
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].ff.ff >> arr[i].ff.ss >> arr[i].ss;
			arr[i].ff.ff++;
		}
		sort(arr, arr+n, cmp);
		seg.build(1, 1, MAXN);
		for (int i = 0; i < n; i++) {
			sum = seg.qry(1, 1, MAXN, arr[i].ff.ff, arr[i].ff.ss);
			tmp = arr[i].ss - sum;
			int l = arr[i].ff.ff, r = arr[i].ff.ss-tmp+1, mid;
			while (l < r) {
				mid = (l+r+1)/2;
				sum = seg.qry(1, 1, MAXN, mid, arr[i].ff.ss);
				nnd = arr[i].ff.ss-mid+1-sum;
				if (nnd < tmp) r = mid-1;
				else l = mid;
			}
			seg.mdy(1, 1, MAXN, l, arr[i].ff.ss);
		}
		cout << seg.qry(1, 1, MAXN, 1, MAXN) << endl;
	}
	return 0;
}