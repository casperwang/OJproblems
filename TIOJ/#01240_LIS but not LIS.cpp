#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int n, mx;
int a[MAXN+5];
bool tf;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int cnt = 1; cnt <= n; cnt++) {
    tf = 1;
    mx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > mx) mx = a[i], a[i] = 0;
      if (a[i]) tf = 0;
    }
    if (tf) {
      cout << cnt << "\n";
      return 0;
    }
  }
}