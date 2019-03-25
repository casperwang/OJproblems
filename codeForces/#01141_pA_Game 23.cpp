#include <bits/stdc++.h>
#define MAXN 10000+5
using namespace std;

int a, b, k, ans;

int main() {
  cin >> a >> b;
  k = b / a;
  while (k % 2 == 0) {
    k /= 2;
    ans++;
  }
  while (k % 3 == 0) {
    k /= 3;
    ans++;
  }
  if (k != 1 || b % a != 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
