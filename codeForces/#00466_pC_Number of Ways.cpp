#include <bits/stdc++.h>
#define MAXN 500000
#define int long long
using namespace std;

int n, k, ans;
int arr[MAXN+5], pre[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> arr[i];
  	pre[i] += arr[i] + pre[i-1];
  }
  for (int i = 1; i < n; i++) {
  	if (pre[i] == pre[n]/3*2) ans += k;
  	if (pre[i] == pre[n]/3) k++;
  }
  if (pre[n]%3 == 0) cout << ans << endl;
  else cout << 0 << endl;
  return 0;
}