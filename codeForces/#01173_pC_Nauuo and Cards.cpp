#include <bits/stdc++.h>
#define int long long
#define MAXN 200000
using namespace std;

int n, a[MAXN+5], b[MAXN+5];
int s, k, p = -1, m = 1;
bool tf;

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 1) s = i+1, p = i;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] && i > p && i-p+1 >= b[i]) k = max(k, i-p-(b[i]-1));
  }
  for (int i = 0; i < n; i++) {
    if (tf && b[i] == m+1) m++;
    else tf = 0;
    if (b[i] == 1) tf = 1;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] && i < p && i+m+1 >= b[i]) tf = 0;
  }
  if (!tf) cout << n+s+k << endl;
  else cout << n-m << endl;
  return 0;
}
