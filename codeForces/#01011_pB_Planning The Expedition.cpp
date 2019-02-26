#include <bits/stdc++.h>
#define MAXN 100+5
using namespace std; 

int n, m, a, appr[MAXN], k;
int l, r, mid = 1;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a;
    appr[a]++;
  }
  l = 0, r = m+1;
  while (l+1 < r) {
    mid = (l + r) / 2;
    if (!mid) break;
    k = 0;
    for (int i = 1; i <= 100; i++) {
      k += appr[i]/mid;
    }
    if (k >= n) l = mid;
    else r = mid;
  }
  cout << l << endl;
  return 0;
}
