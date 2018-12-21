#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000000
using namespace std;
long long int t, a, b, k, tmp;
long long int almost_prime[N];
bool not_prime[N+5];
vector <long long int> primes;
int main() {
  for (int i = 2; i <= N; i++) {
    if (!not_prime[i]) {
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && primes[j]*i <= N; j++) {
      not_prime[primes[j]*i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
  for (int i = 0; i < primes.size(); i++) {
    tmp = primes[i] * primes[i];
    while (tmp <= 1000000000000 && tmp > 0) {
      almost_prime[k++] = tmp;
      tmp *= primes[i];
    }
  }
  sort(almost_prime, almost_prime+k);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    cout << upper_bound(almost_prime, almost_prime+k, b) - lower_bound(almost_prime, almost_prime+k, a) << endl;
  }
  return 0;
}
