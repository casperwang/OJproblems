#include <bits/stdc++.h>
#define int long long
using namespace std;

int x, y, z;
bool tf = 0;

signed main() {
  cin >> x >> y >> z;
  if (min(x, y) + z < max(x, y)) tf = 1;
  if (x == y && !z) tf = 1;
  if (tf) {
    if (x > y) cout << "+" << endl;
    if (y > x) cout << "-" << endl;
    if (x == y) cout << "0" << endl;
  } else {
    cout << "?" << endl;
  }
  return 0;
}
