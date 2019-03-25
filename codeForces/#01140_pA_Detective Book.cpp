#include <bits/stdc++.h>
using namespace std;

long long int n, a, ans, m;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    m = max(m, a);
    if (a == i && i >= m) ans++; 
  }
  cout << ans << endl;
  return 0;
}
