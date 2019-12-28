#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans, i;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (i = 1; i*i <= n; i++)
    ans += n/i-1;
  for (i = n/i; i >= 1; i--)
    ans += (n/i-n/(i+1))*(i-1);
  cout << ans << '\n';
}