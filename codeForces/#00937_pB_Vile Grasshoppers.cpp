#include <bits/stdc++.h>
#define int long long
#define MAXN 1000000
using namespace std;

int p, y;
bool notPrime[MAXN+5];
vector <int> primes;

signed main() {
  cin >> p >> y;
  for (int i = 2; i <= min(p, (long long)MAXN); i++) {
    if (!notPrime[i]) {
      primes.push_back(i);
      if (i > 1000000) cout << i << endl;
      for (int j = i; i*j < MAXN; j++) {
        notPrime[i*j] = 1;
      }
    }
  }
  for (int j = y; j > p; j--) {
    bool tf = 1;
    for (int k = 0; k < primes.size(); k++) {
      if (j % primes[k] == 0) {
        tf = 0;
        break;
      }
    }
    if (tf) {
      cout << j << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
