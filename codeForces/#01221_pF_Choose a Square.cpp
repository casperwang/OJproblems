#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 500000
#define ff first
#define ss second
using namespace std;

struct node{
	int x, y;
	int val;
	node(){}
	node(int x, int y, int v) : x(x), y(y), val(v) {}
};

bool cmp (const node a, const node b) {
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}
 
int n, ans;
int x, y, c;
int L, R;
node arr[MAXN+5];
int num[MAXN*2+5];

class Seg{
public:
	pair<int, int> arr[MAXN*4+5];
	int tag[MAXN*4+5];
	void push(int now, int len) {
		if (tag[now] == 0) return;
		arr[now].ff += tag[now];
		if (len > 1) {
			tag[now*2]   += tag[now];
			tag[now*2+1] += tag[now];
		}
		tag[now] = 0;
		return;
	}
	void pull(int now) {
		arr[now] = max(arr[now*2], arr[now*2+1]);
	}
	void build(int now, int l, int r) {
		if (l == r) {
			arr[now].ff = num[l-1];
			arr[now].ss = l;
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
	pair<int,int> qry(int now, int l, int r, int ql, int qr) {
		push(now, r-l+1);
		if (l >= ql && r <= qr) {
			return arr[now];
		} else if (l > qr || r < ql) return {-1e18, 0};
		int mid = (l+r)/2;
		pair <int, int> tmp = {-1e18, 0};
		tmp = max(tmp, qry(now*2  , l, mid, ql, qr));
		tmp = max(tmp, qry(now*2+1,mid+1,r, ql, qr));
		pull(now);
		return tmp;
	}
} seg;
 
signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> c;
		arr[i] = node(min(x, y), max(x, y), c);
		num[i] = min(x, y);
	}
	sort(arr, arr+n, cmp);
	sort(num, num+n);
	int len = n;
	for (int i = 0; i < n; i++) {
		if (i && num[i] == num[i-1]) num[i-1] = 1e18, len--;
	}
	sort(num, num+n);
	seg.build(1, 1, len);
	L = R = 1578499999;
	for (int i = 0; i < n; i++) {
		int tmp = lower_bound(num, num+len, arr[i].x)-num+1;
		seg.mdy(1, 1, len, 1, tmp, arr[i].val);
		if (i < n-1 && arr[i].y == arr[i+1].y) continue;
		pair <int, int> p = seg.qry(1, 1, len, 1, tmp);
		if ( - arr[i].y + p.ff >= ans) {
			ans =  - arr[i].y + p.ff;
			L = num[p.ss-1], R = arr[i].y;
		}
	}
	cout << ans << endl;
	cout << L << " " << L << " " << R << " " << R << endl;
	return 0;
}