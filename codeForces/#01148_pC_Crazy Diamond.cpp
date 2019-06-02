#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

int n, p[MAXN+5], tmp;
map <int, int> appr;
vector <pair<int, int>> op;

void swop(int a, int b) {
  op.push_back({a, b});
  swap(p[a], p[b]);
  appr[p[b]] = b;
  appr[p[a]] = a;
}

signed main() {
  cin >> n;
  op.clear();
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    appr[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (appr[i] != i) {
      if (appr[i] - i >= n/2) {
        swop(i, appr[i]);
      } else {
        if (appr[i] > n/2 && i > n/2) {
          int tmp = appr[i];
          swop(1, appr[i]);
          swop(i, 1);
          swop(1, tmp);
        } else if (appr[i] > n/2 && i <= n/2) {
          int tmp = appr[i];
          swop(1, appr[i]);
          if (i == 1) continue;
          swop(n, 1);
          swop(i, n);
          swop(1, tmp);
        } else if (appr[i] <= n/2 && i <= n/2) {
          swop(n, appr[i]);
          swop(i, n);
        } else if (appr[i] <= n/2 && i > n/2) {
          swop(n, appr[i]);
          if (i == n) continue;
          swop(1, n);
          swop(i, 1);
          swop(1, n);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    assert(p[i] == i);
  } 
  assert(op.size() <= 5*n);
  cout << op.size() << endl;
  for (int i = 0; i < op.size(); i++) {
    assert(op[i].first-op[i].second >= n/2 || op[i].second-op[i].first >= n/2);
    cout << op[i].first << " " << op[i].second << endl; 
  }
  return 0;
}
