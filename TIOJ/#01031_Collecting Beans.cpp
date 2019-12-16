#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
 
int a, ans;
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> a) {
    if (!a) {
      if (!ans) return 0;
      cout << ans << '\n';
      ans = 0;
    } else {
      ans += (1<<(int)floor(__lg(a)));
    }
  }
}