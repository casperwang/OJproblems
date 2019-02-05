#include <bits/stdc++.h>
#define MAXN 12000000+5
using namespace std;

int n;
bool not_prime[MAXN];
vector <int> primes;

int main() {
  for (int i = 2; i <= MAXN; i++) {
  	if (!not_prime[i]) primes.push_back(i);
  	for (int j = 0; j < primes.size() && i * primes[j] <= MAXN; j++) {
  	  not_prime[i * primes[j]] = 1;
  	  if (i % primes[j] == 0) break;
    }
  }
  scanf("%d", &n);
  for (int i = 0; primes[i] < n; i++) {
    if (i) printf(" ");
    printf("%d",primes[i]);
  }
  printf("\n");
  return 0;
}

