#include <bits/stdc++.h>
#define MAXN 300000
#define int long long
using namespace std;

int n, m, a, b, k, s;
int ans;
int N[MAXN+5], M[MAXN+5];

signed main() {
  cin >> n >> m >> a >> b >> k;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  N[n] = 1000000001;
  for (int i = 0; i < m; i++) {
    cin >> M[i];
  }
  while (N[0]+a > M[s]) s++;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, M[(lower_bound(M+s, M+m, N[i]+a)-M)+k-i] + b);
    if (N[i]+a > M[max((long long)0, m-1-(k-i))]) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (m <= k) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
