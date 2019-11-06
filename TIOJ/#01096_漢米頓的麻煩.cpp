#include <bits/stdc++.h>
#define MAXN 100
#define INF 1e9
using namespace std;

int n, ans;
int path[MAXN+2][MAXN+2];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    if (!n) return 0;
    ans = INF;
    for (register int i = 1; i <= n; i++) {
      for (register int j = 1; j <= n; j++) {
        cin >> path[i][j];
        if (!path[i][j]) path[i][j] = INF;
      }
    }
    for (register int k = 1; k <= n; k++) {
      for (register int i = 1; i <= n; i++) {
        for (register int j = 1; j <= n; j++) {
          path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
        }
      }
    }
    for (register int i = 1; i <= n; i++) ans = min(ans, path[i][i]);
    if (ans != INF) cout << ans << '\n';
    else cout << -1 << '\n';
  }
  return 0;
}