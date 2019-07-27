#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
 
int w, h, ans;
 
signed main() {
  cin >> w >> h;
  ans = 1;
  for (int i = 0; i < w+h; i++) {
    ans *= 2;
    ans %= MOD; 
  }
  cout << ans << endl;
  return 0;
}
