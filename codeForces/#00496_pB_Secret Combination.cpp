#include <bits/stdc++.h>
using namespace std;

int n, k;
string a, b, ans;

int main() {
  cin >> n >> a;
  ans = a;
  for (int i = 0; i < n; i++) {
    b = a + a;
    k = '0'+10 - a[i];
    for (int j = 0; j < n; j++) {
      b[i+j] += k;
      if (b[i+j] > '9') b[i+j] -= 10;
    }
    b = b.substr(i, n);
    ans = min(ans, b);
  }
  cout << ans << endl;
}
