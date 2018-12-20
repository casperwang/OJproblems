#include <iostream>
#include <cstdio>
#include <vector>
#define N 200000
using namespace std;
long long int n;
long long int phi[N+5], f[N+5];
bool not_prime[N+5];
vector <long long int> primes;
int main() {
  // O(N) prime, phi
  phi[1] = 0;
  for (int i = 2; i <= N; i++) {
    if (!not_prime[i]) {
      primes.push_back(i);
      phi[i] = i-1;
    }
    for (int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > N) break;
      not_prime[i * primes[j]] = 1;
      if (i % primes[j] == 0){
        phi[i*primes[j]] = phi[i] * primes[j];
        break;
      } else {
        phi[i * primes[j]] = phi[i] * phi[primes[j]];
      }
    }
  }
  // f[i] = GCD(i,1) + GCD(i,2) + GCD(i,3) ...
  for (int i = 1; i <= N; i++) f[i] = phi[i];
  for (int i = 2; i*2 <= N; i++) {
    for (int j = i*2; j <= N; j+=i) {
      f[j] += i * phi[j/i];
    }
  }
  for (int i = 1; i <= N; i++) {
    f[i] = f[i] + f[i-1];
  }
  while (scanf("%lld",&n)) {
    if (!n) return 0;
    printf("%lld\n", f[n]);
  }
  return 0;
}
