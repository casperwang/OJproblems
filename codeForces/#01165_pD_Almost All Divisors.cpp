#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

long long int t, n, num[MAXN+5];
long long int ans, k, p[MAXN+5];
bool tf;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> num[j];
    }
    tf = 1, k = 0;
    sort(num, num+n);
    ans = num[0] * num[n-1];
    for (long long int j = 2; j <= (int)sqrt(ans); j++) {
      if (ans % j == 0) {
        p[k++] = j;
        if (j*j == ans) continue;
        p[k++] = ans/j;
      }
    }
    if (k != n) tf = 0;
    sort(p, p+n);
    for (int j = 0; j < n; j++) {
      if (p[j] != num[j]) tf = 0;
    }
    if (tf) cout << ans << endl;
    else cout << -1 << endl;
  }
}
