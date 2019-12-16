#include <bits/stdc++.h>
#define MAXN 1000000
#define pii pair<double,double>
#define x first
#define y second
using namespace std;

int n, m;
double r;
pii cen, pts[MAXN+5];

double dis(pii a, pii b) {
	return hypot(a.x-b.x, a.y-b.y);
}

void init(pii a, pii b) {
	cen = pii((a.x+b.x)/2, (a.y+b.y)/2);
	r = dis(cen, a);
}

pii ccc(pii a, pii b, pii c) {
	double s, A, B, C, X, Y;
	s = ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y))*2;
	A = a.x*a.x+a.y*a.y;
	B = b.x*b.x+b.y*b.y;
	C = c.x*c.x+c.y*c.y;
	X = (A*(b.y-c.y)-B*(a.y-c.y)+C*(a.y-b.y))/s;
	Y = (a.x*(B-C)-b.x*(A-C)+c.x*(A-B))/s;
	return pii(X, Y);
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
  	if (!n && !m) return 0;
  	for (int i = 0; i < m; i++) {
  		cin >> pts[i].x >> pts[i].y;
  	}
  	random_shuffle(pts, pts+m);
  	init(pts[0], pts[1]);
  	for (int i = 2; i < m; i++) {
  		if (dis(cen, pts[i]) <= r) continue;
  		init(pts[0], pts[i]);
  		for (int j = 1; j < i; j++) {
  			if (dis(cen, pts[j]) <= r) continue;
  			init(pts[i], pts[j]);
  			for (int k = 0; k < j; k++) {
  				if (dis(cen, pts[k]) <= r) continue;
  				cen = ccc(pts[i], pts[j], pts[k]);
  				r = dis(cen, pts[k]);
  			}
  		}
  	}
  	cout << (int)ceil(r) << '\n';
  }
}