#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, c;
int ans;

signed main() {
  cin >> a >> b >> c;
  ans = c*2 + min(a, b)*2 + (max(a, b) > min(a, b));
  cout << ans << endl;
  return 0;
}
