#include <iostream>
#include <cstdio>
#include <vector>
#define N 50000
using namespace std;
long long int t, a, b, ans, n, m;
bool not_prime[N+5];
vector <int> primes;
int main() {
  for (int i = 2; i <= N; i++) {
  	if (!not_prime[i]) primes.push_back(i);
  	for (int j = 0; j < primes.size() && i * primes[j] <= N; j++) {
  	  not_prime[i * primes[j]] = 1;
  	  if (i % primes[j] == 0) break;
	}
  }
  scanf("%lld",&t);
  for (int i = 0; i < t; i++) {
  	ans = n = 0;
  	scanf("%lld%lld",&a,&b);
  	for (int j = a; j <= b; j++) {
  	  long long int p = j, tmp;
  	  m = 1;
  	  for (int k = 0; k < primes.size() && p; k++) {
  	  	tmp = 1;
  	    while (p % primes[k] == 0) {
  	      p /= primes[k];
  	      tmp++;
		}
		m *= tmp;
	  }
	  if (p > 1) m *= 2;
	  if (m > n) {
	  	n = m;
	  	ans = j;
	  }
	}
	printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,ans,n);
  } 
  return 0;
}
