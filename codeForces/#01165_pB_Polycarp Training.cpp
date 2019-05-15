#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, num[MAXN+5], ans = 1;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  for (int i = 0; i < n; i++) {
    if (num[i] >= ans) ans++;
  }
  cout << ans-1 << endl;
  return 0;
}
