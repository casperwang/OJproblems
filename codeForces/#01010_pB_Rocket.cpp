#include <bits/stdc++.h>
using namespace std; 

int n, m, l, r, mid, i;
int tf[30], p;

int main() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    fflush(stdout);
    cin >> tf[i];
    if (tf[i] == 0) return 0;
    if (tf[i] == -1) tf[i]= 0;
  }
  l = 1, r = m;
  while (l >= 1 && r <= m) {
    mid = (l + r) / 2;
    cout << mid << endl;
    fflush(stdout);
    cin >> p;
    if (p == 0) {
      return 0;
    } else if (p == 1) {
      if (tf[i%n]) l = mid+1;
      else r = mid-1;
    } else if (p == -1) {
      if (tf[i%n]) r = mid-1;
      else l = mid+1;
    }
    i++;
  }
  return 0;
}
