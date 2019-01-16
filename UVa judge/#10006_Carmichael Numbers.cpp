#include <iostream>
#include <cstdio>
#include <vector>
#define N 65000
using namespace std;
bool not_prime[N+5];
vector <int> primes;
long long int n, tmp, k, a;
bool tf;
int main() {
  for (int i = 2; i <= N; i++) {
  	if (!not_prime[i]) primes.push_back(i);
  	for (int j = 0; j < primes.size() && i*primes[j] <= N; j++) {
  	  not_prime[i*primes[j]] = 1;
  	  if (i % primes[j] == 0) break;
	}
  }
  while (scanf("%lld",&n)) {
  	if (!n) return 0;
  	if (!not_prime[n]) {
  	  printf("%lld is normal.\n",n);
  	  continue;
	}
  	for (long long int i = 2; i < n; i++) {
  	  tf = 0;
  	  a = 1;
  	  long long int tmp = i;
  	  for (long long int k = 1; k <= n; k*=2) {
  	  	if (n&k) a = (a*tmp)%n;
		tmp = (tmp*tmp)%n;
	  }
	  if (a != i) {
	  	tf = 1;
	  	break;
	  }
	}
	if (!tf) printf("The number %lld is a Carmichael number.\n",n);
	else printf("%lld is normal.\n",n);
  }
}
