#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

long long int n, a[MAXN+5], b[MAXN+5], ans;
long long int MOD = 998244353;

bool cmp(const long long int a, const long long int b) {
  return a > b;
}

int main() {
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = a[i] * (i+1) * (n-i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a, a+n);
  sort(b, b+n, cmp);
  for (int i = 0; i < n; i++) {
    ans = (ans + (a[i] % MOD) * b[i]) % MOD;
  }
  cout << ans % MOD << endl;
}
