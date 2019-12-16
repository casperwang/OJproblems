#include <bits/stdc++.h>
#define MAXN 1000000
#define pt pair<double,double>
#define x first
#define y second
using namespace std;

int n, m;
double R, Rl, Rr, d;
double const eps = 0;
pt c, l, r, tmp;
pt pts[MAXN+5];

inline double dis(pt a, pt b) {
	return hypot(a.x-b.x, a.y-b.y);
}

inline bool cross(pt a, pt b, pt c) {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) > 0;
}

inline void init(int i, int j) {
	c = pt((pts[i].x+pts[j].x)/2, (pts[i].y+pts[j].y)/2);
	R = dis(c, pts[i]);
	Rl = Rr = -1;
	return;
}

pt ccc(pt a, pt b, pt c) {
	double s, A, B, C, X, Y;
	s = ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))*2;
	A = a.x*a.x+a.y*a.y;
	B = b.x*b.x+b.y*b.y;
	C = c.x*c.x+c.y*c.y;
	X = (A*(b.y-c.y)-B*(a.y-c.y)+C*(a.y-b.y))/s;
	Y = (a.x*(B-C)-b.x*(A-C)+c.x*(A-B))/s;
	return pt(X, Y);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		for (int i = 0; i < m; i++)
			cin >> pts[i].x >> pts[i].y;
		srand((unsigned)time(NULL));
		random_shuffle(pts, pts+m);
		init(0, 1);
		for (int i = 2; i < m; i++) {
			if (R - dis(c, pts[i]) > eps) continue;
			init(0, i);
			for (int j = 1; j < i; j++) {
				if (R - dis(c, pts[j]) > eps) continue;
				init(i, j);
				for (int k = 0; k < j; k++) {
					if (R - dis(c, pts[k]) > eps) continue;
					c = ccc(pts[i], pts[j], pts[k]);
					R = dis(c, pts[i]);
				}
			}
		}
		cout << fixed << setprecision(3) << R << '\n';
	}
  return 0;
}