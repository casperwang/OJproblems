#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

long long int n, m, g, k;
long long int x[MAXN+5], p[MAXN+5];
long long int poss = 22222222222222222;

long long int GCD(long long int a, long long int b) {
  return (b == 0) ? a : GCD(b, a % b);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0;i < m; i++) {
    cin >> p[i];
  }
  g = GCD(g, x[1] - x[0]);
  for (int i = 1; i < n; i++) {
    g = GCD(g, x[i] - x[i-1]);
  }
  for (int i = 0; i < m; i++) {
    if (g % p[i] == 0) {
      if (poss > p[i]) {
        poss = p[i];
        k = i+1;
      }
    }
  }
  if (k > 0) {
    cout << "YES" << endl;
    cout << x[0] << " " << k << endl; 
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
