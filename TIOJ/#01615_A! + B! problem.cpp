#include <iostream>
#include <vector>
#define N 1000000
using namespace std;
long long int a, b, ans, tmp;
bool not_prime[N+5];
vector <int> primes;
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
  while (cin >> a >> b) {
    ans = 0;
    for (int i = 0; i < primes.size() && primes[i] <= min(a, b); i++) ans++;
    tmp = 1;
    for (int i = min(a,b)+1; i <= max(a,b); i++) {
      tmp *= i;
    }
    tmp += 1;
    for (int i = 0; i < primes.size(); i++) {
      if (tmp % primes[i] == 0 && primes[i] > min(a,b)) ans++;
      while (tmp % primes[i] == 0) {
        tmp /= primes[i];
      }
    }
    if (tmp > 1) ans++;
    cout << ans << endl;
  }
  return 0;
}
