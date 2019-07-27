#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int k, d, t, m, ans;
int p = 0;

signed main() {
  cin >> k >> d >> t;
  t *= 2;
  m = (k+d-1)/d;
  ans += (t/(m*d+k))*(m*d);
  t %= m*d+k;
  if (t <= k*2) {
    p = t % 2;
    ans += t/2;
  } else {
    ans += k;
    t -= k*2;
    ans += t;
  }
  cout << ans << "." << p*5 << endl; 
  return 0;
}
