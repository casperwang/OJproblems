#include <bits/stdc++.h>
#define int long long
#define MAXN 200000
using namespace std;

int n, tmp;
int a[MAXN+5], b[MAXN+5], c[MAXN+5];
map <int, int> apprB;

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i], apprB[b[i]]++;
  for (int i = 0; i < n; i++) {
    if (apprB.lower_bound(n-a[i]) == apprB.end()) {
      tmp = (*apprB.lower_bound(0)).first;
      c[i] = a[i] + tmp;
      apprB[tmp]--;
      if (!apprB[tmp]) apprB.erase(tmp);
    } else {
      tmp = (*apprB.lower_bound(n-a[i])).first;
      c[i] = (a[i] + tmp) % n;
      apprB[tmp]--;
      if (!apprB[tmp]) apprB.erase(tmp);
    }
    cout << c[i] << " \n"[i==n-1];
  }
  return 0;
}
