#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int a, b, c, m;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> a >> b >> c) {
    m = max({a,b,c});
    if (a+b+c-m > m) cout << "SAFE\n";
    else cout << "BYE\n";
  }
}