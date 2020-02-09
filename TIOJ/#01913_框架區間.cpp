#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int t, n, ans;
int mn, mx;
int a[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      mn = mx = a[i];
      for (int j = i+1; j < n; j++) {
        if (a[j] > a[i] && mn != a[i]) break;
        if (a[j] < a[i] && mx != a[i]) break;
        if (a[j] > a[i]) mx = max(mx, a[j]);
        if (a[j] < a[i]) mn = min(mn, a[j]);
        if (a[j] != mx && a[j] != mn) continue;
        if (mx-mn == j-i) ans++;
      }
    }
    cout << ans << "\n";
  }
}