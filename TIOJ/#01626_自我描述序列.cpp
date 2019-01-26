#include <iostream>
#include <cstdio>
#define N 1200000
#define I 4000000000
using namespace std;
unsigned long long int n, num[N+5], sum, k, p;
int main() {
  num[1] = 1;
  sum = 1;
  num[2] = 2;
  p = 2;
  k = 2;
  while (sum <= I) {
  	for (long long int i = k; i < k + num[p]; i++) {
  	  num[i] = p;
  	  sum += p;
	}
	k += num[p];
	p++;
  }
  for (int i = 1; i <= N; i++) num[i] += num[i-1];
  while (scanf("%lld", &n)) {
  	if (!n) return 0;
  	printf("%lld\n",lower_bound(num, num+N, n) - num); 
  }
}
