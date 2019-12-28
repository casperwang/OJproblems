#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, ans;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    ans = n/3;
    for (int i = 9; i <= n; i*=3)
      ans += n/i;
    cout << ans << "\n";
  }
}