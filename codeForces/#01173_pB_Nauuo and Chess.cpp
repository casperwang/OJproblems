#include <bits/stdc++.h>
#define int long long
using namespace std;

int x, y, n;
bool tf = 0;

signed main() {
  cin >> n;
  cout << (n+2)/2 << endl;
  x = y = 1;
  for (int i = 1; i <= n; i++) {
    cout << x << " " << y << endl;
    if (i % 2) x++;
    else y++; 
  }
  return 0;
}
