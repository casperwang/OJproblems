#include <bits/stdc++.h>
#define int long long
#define MAXN 300000
using namespace std;
 
int n, p, k, ans, tmp;
int num[MAXN+5];
map <int, int> appr;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    tmp = num[i]; 
    tmp *= tmp;
    tmp %= p;
    tmp *= tmp;
    tmp %= p;
    tmp -= k*num[i];
    tmp += p*p;
    tmp %= p;
    appr[tmp]++;
  }
  for (auto i : appr) {
    ans += i.second*(i.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}
