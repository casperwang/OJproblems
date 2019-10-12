#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;
 
const double PI = acos(-1);
double x, y, r, a;
 
signed main() {
    Hina;
    while (cin >> x >> y >> r) {
        if (y+r <= 0) {
            printf("0.00\n");
        } else if (y-r >= 0) {
            a = PI*r*r;
            printf("%.2lf\n", a);
        } else {
            a = abs(acos(-y/r))*r*r;
            a += sqrt(r*r-y*y)*y;
            printf("%.2lf\n", a);
        }
    }
}