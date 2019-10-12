#include <bits/stdc++.h>
#define C 51
#define int long long
using namespace std;

string p, q;
bool tf;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> p >> q;
  for (int i = min(p.length(), q.length()); i >= 0; i--) {
    tf = 1;
    for (int j = 0; j < i; j++) {
      if (p[j] != q[q.length()-i+j]) tf = 0;
    }
    if (tf) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}