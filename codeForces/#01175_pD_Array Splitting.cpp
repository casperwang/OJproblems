#include <bits/stdc++.h>
#define int long long
#define MAXN 300000
using namespace std;

int n, k, num[MAXN+5];
int suf[MAXN+5];
int ans = 0;

signed main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  for (int i = n-1; i >= 0; i--) {
    suf[i] = suf[i+1] + NUM[i];
  }
  ans = suf[0], k--;
  sort(suf+1, suf+n);
  for (int i = n-1; i >= 1 && k; i--) {
    ans += suf[i];
    k--;
  }
  cout << ans << endl;
  return 0;
}
