#include <bits/stdc++.h>
#define MAXN 1000+5
using namespace std; 

int n, m, a[MAXN], b[MAXN];
bool tf = 1;
double l, r, mid, now_f;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) tf = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 1) tf = 0;
  }
  l = 0, r = 1000000001;
  while (r - l >= 0.0000001) {
    mid = (l + r) / 2;
    now_f = mid;
    for (int i = 0; i < n; i++) {
      now_f -= (now_f + m) / a[i];
      if (now_f < 0) break;
      now_f -= (now_f + m) / b[(i+1)%n];
      if (now_f < 0) break;
    }
    if (now_f < 0) l = mid;
    else r = mid;
  }
  if (tf) printf("%.8lf\n", l);
  else printf("-1\n");
  return 0;
}
