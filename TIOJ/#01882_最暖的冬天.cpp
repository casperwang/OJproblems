#include <bits/stdc++.h>
#define MAXN 10000
#define int long long
using namespace std;

int n;
double l, r, m, lv, rv, mv;
int a[MAXN+5], b[MAXN+5], c[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  l = 0, r = 90*24*60;
  lv = c[0], rv = r*r*a[0]+r*b[0]+c[0];
  for (int i = 0; i < n; i++) {
    lv = min(lv, (double)c[i]);
    rv = min(rv, r*r*a[i]+r*b[i]+c[i]);
  }
  while (r-l >= 1e-7) {
    m = (l+r)/2, mv = m*m*a[0]+m*b[0]+c[0];
    for (int i = 0; i < n; i++) {
      mv = min(mv, m*m*a[i]+m*b[i]+c[i]);
    }
    if (mv <= lv) r = m, rv = mv;
    else if (mv <= rv) l = m, lv = mv;
    else if (rv < lv) r = m, rv = mv;
    else l = m, lv = mv;
  }
  printf("%.6lf\n", l);
} 