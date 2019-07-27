#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, m, ans;

signed main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans = 0;
    cin >> n >> m;
    while (n > 0) {
      ans += n % m;
      n /= m;
      ans++;
    }
    cout << ans-1 << endl;
  }
  return 0;
}
