#include <iostream>
#include <cstdio>
#define N 20
using namespace std;
long long int n, num[N+5];
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a%b);
}
int main() {
  while (scanf("%lld",&n) != EOF) {
  	for (int i = 0; i < n; i++) {
  	  scanf("%lld",&num[i]);
  	  if (i) num[i] = gcd(num[i],num[i-1]);
	}
	printf("%lld\n",num[n-1]);
  }
  return 0;
}
