#include <bits/stdc++.h>
#define MAXN 500000
#define M 600
#define int long long
using namespace std;

int q, op, x, y;
int v[MAXN+5], a[M+5][M+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> op >> x >> y;
    if (op == 1) {
      v[x] += y;
      for (int j = 1; j <= M; j++) {
        a[j][x%j] += y;
      }
    } else {
      if (x > M) {
        int sum = 0;
        for (int j = y; j <= MAXN; j += x) sum += v[j];
        cout << sum << endl; 
      } else {
        cout << a[x][y] << endl;
      }
    }
  }
} 

