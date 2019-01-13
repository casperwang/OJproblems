#include <cstdio>
#include <cmath>
long long int L, n, d, a, b, g;
double c, m;
long long int f(long long int a, long long int b) {
  return (!b) ? a : f(b,a%b);
}
int main() {
  while (scanf("%lld%lld%lld",&L,&n,&d)) {
  	if (!L && !n && !d) return 0;
  	c = (double)d/(double)L;
  	a = m = L;
  	b = g = 1;
  	for (int i = 2; i <= n; i++) {
  	  if ((double)L*ceil(c*i) / (double)i < m) {
  	  	m = (double)L*ceil(c*i) / (double)i;
  	  	a = (long long int)L*ceil(c*i);
  	  	b = i;
	  }
	}
	g = f(a,b);
	a /= g;
	b /= g;
	printf("%lld/%lld\n",a,b);
  }
}
