#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100000
using namespace std;
long long int n, a[2*N+5], m = 2147483647, t, ans;
int main() {
  cin >> n;
  for (int i = 0; i < 2*n; i++) cin >> a[i];
  sort(a, a+(2*n));
  // finding min interval
  for (int i = n-1; i < 2*n; i++) {
    if (a[i] - a[i-n+1] < m) {
      m = a[i] - a[i-n+1];
      t = i-n+1;
    }
  }
  if (t == n || a[2*n-1]-a[n] == m) t = a[n-1] - a[0];
  else if (t == 0 || a[n-1] - a[0] == m) t = a[2*n-1]-a[n];
  else t = a[2*n-1]-a[0];
  ans = min(m*t, (a[2*n-1]-a[n]) * (a[n-1]-a[0]));
  printf("%lld\n",ans);
  return 0;
}
