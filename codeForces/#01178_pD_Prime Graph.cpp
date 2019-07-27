#include <bits/stdc++.h>
#define int long long
#define MAXN 10000
using namespace std;
 
int n;
bool not_prime[MAXN+5];
bool appr[MAXN+5];
vector <int> primes; 
 
signed main() {
  for (int i = 2; i <= MAXN; i++) {
    if (!not_prime[i]) {
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && i * primes[j] <= MAXN; j++) {
      not_prime[i * primes[j]] = 1;
      if (i % primes[j] == 0) break;
    }
  }
  cin >> n;
  if (!not_prime[n]) {
    cout << n << endl;
    for (int i = 1; i < n; i++) {
      cout << i << " " << i+1 << endl;
    }
    cout << n << " " << 1 << endl;
  } else {
    int k = 0;
    while(not_prime[n+k]) k++;
    cout << n+k << endl;
    for (int i = 1; i < n; i++) {
      cout << i << " " << i+1 << endl;
    }
    cout << n << " " << 1 << endl;
    int i = 1;
    while (k) {
      while (appr[i]) i++;
      cout << i << " " << i+2 << endl;
      appr[i] = appr[i+2] = 1;
      k--, i++;
    }
  }
  return 0;
}

