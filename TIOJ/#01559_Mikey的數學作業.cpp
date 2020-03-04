#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pdd pair<double,double>
#define x first
#define y second
using namespace std;

const double sqrt3 = 1.73205080757;
pdd a1, a2, b1, b2;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> a1.x >> a1.y >> a2.x >> a2.y) {
		a2.x -= a1.x, a2.y -= a1.y;
		b1.x  = a2.x/2 - a2.y*sqrt3/2 + a1.x;
		b1.y  = a2.y/2 + a2.x*sqrt3/2 + a1.y;
		b2.x  = a2.x/2 + a2.y*sqrt3/2 + a1.x;
		b2.y  = a2.y/2 - a2.x*sqrt3/2 + a1.y;
		if (b1 > b2) swap(b1, b2);
		printf("%.3lf %.3lf " , b1.x, b1.y);
		printf("%.3lf %.3lf\n", b2.x, b2.y);
	}
}