#include <iostream>
#include <cstdio>
#include <vector>
#define N 1000000
using namespace std;
int ans[N+5], t, n;
bool not_prime[N*3+7+5];
vector <int> primes;
int main() {
  for (int i = 2; i <= N*3+7; i++) {
  	if (!not_prime[i]) {
  	  primes.push_back(i);
  	  if ((i-7 > 0) && (i-7)%3 == 0) {
  	  	ans[(i-7)/3]++;
	  }
	}
  	for (int j = 0; j < primes.size() && i * primes[j] <= N*3+7; j++) {
  	  not_prime[i*primes[j]] = 1;
  	  if (i % primes[j] == 0) break;
	}
  }
  for (int i = 1; i <= N; i++) {
  	ans[i] += ans[i-1];
  }
  scanf("%d",&t);
  for (int i = 0; i < t; i++) {
  	scanf("%d",&n);
  	printf("%d\n",ans[n]);
  }
  return 0;
}
