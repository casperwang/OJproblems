#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, sum;
double a, k;

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (k > 0) {
      sum += ceil(a);
      k += a - ceil(a);
      cout << (int)ceil(a) << endl;
    } else {
      sum += floor(a);
      k += a - floor(a);
      cout << (int)floor(a) << endl; 
    }
  }
  return 0;
}
