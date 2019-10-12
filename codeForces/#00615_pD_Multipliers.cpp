#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int n, t, ans, d;
map <int, int> num;

int pow(int p, int k) {
  int a = p, b = 1, tmp = 1;
  while (b <= k) {
    if (b & k) tmp = (tmp*a)%MOD;
    a = (a*a)%MOD;
    b *= 2;
  }
  return tmp;
}

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    num[t]++;
  }
  ans = d = 1;
  for (auto i : num) {
    ans = (pow(ans, i.second+1)*pow(pow(i.first, (i.second+1)*i.second/2), d))%MOD;
    d = (d*(i.second+1))%(MOD-1);
  }
  cout << ans << endl;
  return 0;
}