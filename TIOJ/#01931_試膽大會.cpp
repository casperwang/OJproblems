#include <bits/stdc++.h>
#define MAXN 100000
#define int long long
using namespace std;

int t, n, ans;
int arr[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    sort(arr, arr+n);
    for (int i = n-2; i >= 0; i -= 2)
      ans += arr[i]*4;
    cout << ans << '\n';
  }
}