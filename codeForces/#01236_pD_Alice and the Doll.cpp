#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 100000
#define ff first
#define ss second
using namespace std;
 
int n, m, k;
int x, y, now;
bool flag = 1;
pair <int, int> a, b, c, d;
set <pair<int, int> > appr;
bool maps[100][100];

bool tf(pair<int,int>a, pair<int,int>b, pair<int,int>c, pair<int,int>d) {
	if (a.ss <= b.ss && b.ff <= c.ff && c.ss >= d.ss && d.ff >= a.ff) return 1;
	return 0;
}

signed main() {
	Hina;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		appr.insert({x, y});
	}
	a = {1, 1}, b = {1, m}, c = {n, m}, d = {n, 1};
	while (flag && appr.size() && tf(a, b, c, d)) {
		if (now % 4 == 0) {
			//cout << a.ff << " " << a.ss << endl;
			while (appr.count(b) && tf(a,b,c,d)) {
				for (int i = b.ff; i <= c.ff; i++) {
					if (!appr.count({i, b.ss})) {
						flag = 0;
						break;
					}
					appr.erase({i, b.ss});
				}
				b.ss--, c.ss--;
			}
			a.ff++;
			if (now) a.ss++;
		} else if (now % 4 == 1) {
			//cout << b.ff << " " << b.ss << endl;
			while (appr.count(c) && tf(a,b,c,d)) {
				for (int i = c.ss; i >= d.ss; i--) {
					if (!appr.count({c.ff, i})) {
						flag = 0;
						break;
					}
					appr.erase({c.ff, i});
				}
				c.ff--, d.ff--;
			}
			b.ff++, b.ss--;
		} else if (now % 4 == 2) {
			//cout << c.ff << " " << c.ss << endl;
			while (appr.count(d) && tf(a,b,c,d)) {
				for (int i = d.ff; i >= a.ff; i--) {
					if (!appr.count({i, d.ss})) {
						flag = 0;
						break;
					}
					appr.erase({i, d.ss});
				}
				d.ss++, a.ss++;
			}
			c.ff--, c.ss--;
		} else if (now % 4 == 3) {
			//cout << d.ff << " " << d.ss << endl;
			while (appr.count(a) && tf(a,b,c,d)) {
				for (int i = a.ss; i <= b.ss; i++) {
					if (!appr.count({a.ff, i})) {
						flag = 0;
						break;
					}
					appr.erase({a.ff, i});
				}
				a.ff++, b.ff++;
			}
			d.ff--, d.ss++;
		}
		now++;
	}
	if (flag && !appr.size()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}