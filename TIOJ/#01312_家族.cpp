#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int n, m, k;
int a, b;
int dsu[MAXN+5];

int fnd(int now) {
  if (dsu[now] != now) dsu[now] = fnd(dsu[now]);
  return dsu[now];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      dsu[max(fnd(a), fnd(b))] = min(fnd(a), fnd(b));
    }
    cin >> k;
    cout << fnd(k) << '\n';
  }
  return 0;
}