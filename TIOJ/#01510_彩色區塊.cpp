#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define y1 y_1
#define int long long
#define pdd pair<double,double>
#define ff first
#define ss second
using namespace std;

struct rgb{
	int R, G, B;
};

struct cmp_key {
  bool operator()(const rgb &a, const rgb &b) const {
  	return a.R < b.R;
  }
};


const int MAXN = 1000;
int n;
rgb t;
int x1, x2, y1, y2;
int R, G, B, p;
rgb arr[MAXN+5][MAXN+5];
int cnt[MAXN+5][MAXN+5];
pair <int, rgb> tmp;
map <rgb, int, cmp_key> appr;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> R >> G >> B;
		if (!R && !G && !B) continue;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int j = x1; j <= x2; j++) {
			arr[j][y1].R += R, arr[j][y2+1].R -= R;
			arr[j][y1].G += G, arr[j][y2+1].G -= G;
			arr[j][y1].B += B, arr[j][y2+1].B -= B;
			cnt[j][y1]   += 1, cnt[j][y2+1] -= 1;
		}
	}
	for (int i = 0; i <= MAXN; i++) {
		for (int j = 0; j <= MAXN; j++) {
			if (j) {
				arr[i][j].R += arr[i][j-1].R;
				arr[i][j].G += arr[i][j-1].G;
				arr[i][j].B += arr[i][j-1].B;
				cnt[i][j]   += cnt[i][j-1];
			}
			if (!cnt[i][j]) continue;
			t.R = (arr[i][j].R + cnt[i][j] - 1) / cnt[i][j];
			t.G = (arr[i][j].G + cnt[i][j] - 1) / cnt[i][j];
			t.B = (arr[i][j].B + cnt[i][j] - 1) / cnt[i][j];
			appr[t]++;
		}
	}
	for (auto i : appr) {
		if (i.ss > tmp.ff) {
			tmp = pair<int,rgb>(i.ss, i.ff);
		}
	}
	cout << tmp.ss.R << " " << tmp.ss.G << " " << tmp.ss.B << "\n";
	return 0;
}