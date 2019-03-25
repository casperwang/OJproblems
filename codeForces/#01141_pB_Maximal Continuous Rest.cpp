#include <bits/stdc++.h>
using namespace std;

int n, a, s, k, ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) k++;
    else {
      if (s == 0 && i == k) s = k;
      ans = max(ans, k);
      k = 0;
    } 
  }
  ans = max(ans, s+k);
  cout << ans << endl;
  return 0;
}
