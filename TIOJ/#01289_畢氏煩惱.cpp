#include <bits/stdc++.h>
#define MAXN 2000
#define int long long
using namespace std;

int n, ans, s;
int a[MAXN+5];
int b[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    ans = 0;
    for (int i = 0; i < n; i++)
      cin >> a[i], b[i] = a[i]*a[i];
    sort(a, a+n);
    sort(b, b+n);
    b[n] = 1e18;
    s = 0;
    while (a[s] <= 0) s++;
    for (int i = s; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (*lower_bound(b, b+n, a[i]*a[i]+a[j]*a[j]) == a[i]*a[i]+a[j]*a[j])
          ans++;
      }
    }
    cout << ans << '\n';
  }
}