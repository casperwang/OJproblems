#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

int n, a, ans[MAXN], m, appr[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a;
    ans[i] = ans[i-1] + a;
    m = min(m, ans[i]);
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] - m+1 < MAXN && ans[i] - m+1 > 0) appr[ans[i] - m+1] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!appr[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] - m+1 << " ";
  }
  cout << endl;
  return 0;
}
