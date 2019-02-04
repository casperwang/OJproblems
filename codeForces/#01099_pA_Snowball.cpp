#include <cstdio>
#include <iostream>
using namespace std;
int ans, w, h;
int u1, u2, d1, d2;
int main() {
  cin >> ans >> h;
  cin >> u1 >> d1;
  cin >> u2 >> d2;
  for (int i = h; i >= 0; i--) {
  	ans += i;
  	if (i == d1) ans -= u1;
  	if (i == d2) ans -= u2;
  	ans = max(ans, 0);
  }
  cout << ans << endl;
  return 0;
}
