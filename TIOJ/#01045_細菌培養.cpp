#include <bits/stdc++.h>
#define MAXN 10000
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define int long long
using namespace std;

int n, ans;
int x_1, y_1, x_2, y_2;
vector <pair<pii,int>> mdy[MAXN+5];

class Seg{
public:
	int arr[MAXN*4+5];
	int tag[MAXN*4+5];
	void pull(int now) {
		arr[now] = arr[now*2] + arr[now*2+1];
	}
	void push(int now, int len) {
		if (!tag[now]) return;
		if (len > 1) {
			tag[now*2  ] += tag[now];
			tag[now*2+1] += tag[now];
		}
		while (tag[now] > 0) arr[now] *= 2, tag[now]--;
		while (tag[now] < 0) arr[now] /= 2, tag[now]++;
	}
	void build(int now, int l, int r) {
		tag[now] = 0;
		if (l == r) {
			arr[now] = 1;
			return;
		}
		int mid = (l+r)/2;
		build(now*2  , l, mid);
		build(now*2+1,mid+1,r);
		pull(now);
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
	}
	int qry(int now, int l, int r) {
		push(now, r-l+1);
		return arr[now];
	}
} seg;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		ans = 0;
		for (int i = 1; i <= MAXN; i++) mdy[i].clear();
		for (int i = 0; i < n; i++) {
			cin >> x_1 >> y_1 >> x_2 >> y_2;
			x_1++, y_1++;
			mdy[ x_1 ].pb({pii(y_1, y_2),  1});
			mdy[x_2+1].pb({pii(y_1, y_2), -1});
		}
		seg.build(1, 1, MAXN);
		for (int i = 1; i <= MAXN; i++) {
			for (int j = 0; j < mdy[i].size(); j++) {
				seg.mdy(1, 1, MAXN, mdy[i][j].ff.ff, mdy[i][j].ff.ss, mdy[i][j].ss);
			}
			ans += seg.qry(1, 1, MAXN);
		}
		cout << ans << "\n";
	}
	return 0;
}