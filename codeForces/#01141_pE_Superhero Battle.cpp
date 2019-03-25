#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

long long int h, n, sum, m, ans;
long long int d[MAXN];

int main() {
  cin >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    sum += d[i];
    m = min(m, sum);
  }
  if (sum >= 0 && h + m > 0) {
    cout << -1 << endl;
    return 0;
  } else if (sum < 0 && h + m > 0) {
    ans = ((h + m) / (-sum)) * n;
    h = h + ans / n * sum;
  }
  int i;
  for (i = 0; i < 10 * n && h > 0; i++) {
    h += d[i%n];
  }
  assert(h <= 0);
  cout << ans + i << endl;
  return 0;
}
