#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a;
stack <int> arr;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  a = n;
  for (int i = 1; i*i <= n; i++) {
    if (n%i == 0) arr.push(n/i);
    if (n%i == 0 && i*2/k >= k+1) {
      for (int j = 1; j < k; j++) {
        cout << j*n/i << " ";
        a -= j*n/i;
      }
      cout << a << endl;
      return 0;
    }
  }
  while (arr.size()) {
    int i = arr.top();
    if (i*2/k >= k+1) {
      for (int j = 1; j < k; j++) {
        cout << j*n/i << " ";
        a -= j*n/i;
      }
      cout << a << endl;
      return 0;
    }
    arr.pop();
  }
  cout << -1 << endl;
  return 0;
}