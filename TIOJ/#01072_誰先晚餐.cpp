#include <iostream>
#include <algorithm>
#define pii pair<int,int>
#define MAXN 10000
#define ff first
#define ss second
using namespace std;

int n, ans;
pii arr[MAXN+5];
int res[MAXN+5], len;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n, n) {
    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i].ss >> arr[i].ff;
    }
    sort(arr, arr+n, greater<pii>());
    for (int i = 1; i < n; i++) {
      arr[i].ss += arr[i-1].ss;
    }
    for (int i = 0; i < n; i++) {
      ans = max(ans, arr[i].ff+arr[i].ss);
    }
    res[len++] = ans;
  }
  for(int i = 0; i < len; i++) cout << res[i] << '\n';
  return 0;
}