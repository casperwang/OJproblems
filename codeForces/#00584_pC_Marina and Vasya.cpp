#include <bits/stdc++.h>
using namespace std;

int n, t;
int same, diff, k, now;
string a, b;

int main() {
  cin >> n >> t;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) diff++;
    else same++;
  }
  if (n - t > same + diff/2) cout << -1 << endl;
  else {
    k = n - t;
    for (int i = 0; i < n; i++) {
      if (k > 0 && !(k == 1 && now % 2 == 1) && a[i] == b[i]) {
        cout << a[i];
        k--;
      } else if (a[i] != b[i] && k > 0 && (diff > 1 || (diff == 1 && now % 2 == 1))) {
        if (now % 2) cout << b[i];
        else cout << a[i];
        now++;
        if (now % 2 == 0) k--;
        diff--;
      } else {
        char c = 'a';
        while (c == a[i] || c == b[i]) {
          c++;
        }
        if (a[i] != b[i]) diff--;
        cout << c;
      }
    }
    cout << endl;
  }
  return 0;
}
