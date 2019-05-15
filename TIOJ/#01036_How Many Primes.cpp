#include <bits/stdc++.h>
#define MAXN 10000000
using namespace std;

int is_prime[MAXN+5];
vector <int> primes;
int t, n;

int main() {
  for (int i = 2; i <= MAXN; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
    }
    for (int j = 0; i * primes[j] <= MAXN && j < primes.size(); j++) {
      is_prime[i * primes[j]] = 1;
      if (i % primes[j] == 0) break;
    }
    is_prime[i] = !is_prime[i] + is_prime[i-1];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << is_prime[n] << endl;
  }
  return 0;
} 
