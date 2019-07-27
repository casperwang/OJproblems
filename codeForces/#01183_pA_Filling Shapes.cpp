#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n, ans[31];

signed main() {
  ans[0] = 1;
  for (int i = 1; i <= 30; i++) {
    ans[i] = ans[i-1]*2;
  }
  cin >> n;
  if (n % 2) cout << 0 << endl;
  else cout << ans[n/2] << endl;
}
