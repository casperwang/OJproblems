#include <bits/stdc++.h>
#define MAXN 1000000+5
#define MOD 1000000007
using namespace std;

int n, m;
long long int ans = 1;
bool not_prime[MAXN];
int num[MAXN];
vector <int> primes;

int main() {
  for (int i = 2; i < MAXN; i++) {
  	if (!not_prime[i]) primes.push_back(i);
  	for (int j = 0; j < primes.size() && i * primes[j] <= MAXN; j++) {
  	  not_prime[i * primes[j]] = 1;
  	  if (i % primes[j] == 0) break;
    }
  }
  scanf("%d%d", &n, &m);
  if (n-m > m) m = n-m;
  for (int i = m+1; i <= n; i++) {
    int tmp = i;
    for (int j = 0; primes[j] <= sqrt(i); j++) {
      while (tmp % primes[j] == 0) {
        tmp /= primes[j];
        num[j]++;
      }
    }
    if (tmp > 1) num[lower_bound(primes.begin(), primes.end(), tmp) - primes.begin()]++;
  }
  for (int i = 2; i <= n-m; i++) {
    int tmp = i;
    for (int j = 0; primes[j] <= sqrt(i); j++) {
      while (tmp % primes[j] == 0) {
        tmp /= primes[j];
        num[j]--;
      }
    }
    if (tmp > 1) num[lower_bound(primes.begin(), primes.end(), tmp) - primes.begin()]--;
  }
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < num[i]; j++) {
      ans *= primes[i];
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
