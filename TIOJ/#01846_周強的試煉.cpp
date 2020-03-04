#include <bits/stdc++.h>
#define int long long
#define y1 y_1
using namespace std;

int t;
double x1, y1, r1, x2, y2, r2;
double s, d, A, k, t1, t2, A1, A2;

signed main() {
	cin >> t;
	while (t--) {
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		if (r1 > r2) swap(r1, r2);
		if (d >= r1 + r2) {
			printf("0.00\n");
		} else if (d + r1 <= r2) {
			printf("%.2lf\n", r1*r1*acos(-1));
		} else {
			s = (r1 + r2 + d) / 2;
			A = sqrt(s * (s - r1) * (s - r2) * (s - d));
			k = A / d * 4;
			t1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d)) * 2;
			t2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d)) * 2;
			A1 = t1 * r1 * r1 / 2;
			A2 = t2 * r2 * r2 / 2;
			printf("%.2lf\n", A1 + A2 - A * 2);
		}
	}
}