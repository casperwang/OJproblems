#include <bits/stdc++.h>
#define MAXN 1000005
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

struct node{
	int pos, a, b, tag;
	node() : tag(0) {}
	node(int p, int a, int b, int t) : pos(p), a(a), b(b), tag(t) {}
};

bool cmp(const node a, const node b) {
	return a.pos < b.pos;
}

class Seg{
public:
	int arr[MAXN*2];
	int tag[MAXN*2];
	void pull(int now, int len) {
		if (tag[now]) arr[now] = len;
		else if (len == 1) arr[now] = 0;
		else arr[now] = arr[now*2]+arr[now*2+1];
	}
	void mdy(int now, int l, int r, int ml, int mr, int k) {
		if (l >= ml && r <= mr) {
			tag[now] += k;
			pull(now, r-l+1);
			return;
		} else if (l > mr || r < ml) return;
		int mid = (l+r)/2;
		mdy(now*2  , l, mid, ml, mr, k);
		mdy(now*2+1,mid+1,r, ml, mr, k);
		pull(now, r-l+1);
		return;
	}
} seg;

int n, x, y, a, b, ans;
node arr[MAXN/5+5];

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> a >> b;
		x++, y++, a++, b++;
		arr[i*2  ] = node(x, a+1, b,  1);
		arr[i*2+1] = node(y, a+1, b, -1);
	}
	sort(arr, arr+2*n, cmp);
	for (int i = 0; i < 2*n; i++) {
		if (i) ans += (arr[i].pos-arr[i-1].pos)*seg.arr[1];
		seg.mdy(1, 1, MAXN, arr[i].a, arr[i].b, arr[i].tag);
	}
	cout << ans << endl;
	return 0;
}