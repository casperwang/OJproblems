#include <bits/stdc++.h>
#define int long long
#define MAXN 300000
using namespace std;

int n, ans;
int num[MAXN+5];

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  for (int i = 0; i < n/2; i++) {
    ans = ans + (num[i]+num[n-1-i])*(num[i]+num[n-1-i]);
  }
  cout << ans << endl;
  return 0;
}
