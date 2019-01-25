#include <iostream>
#include <cstdio>
#include <cmath>
#define N 1000000
using namespace std;
long long int num[N+5], n;
int main() {
  num[0] = 1;
  for (int i = 1; i <= N; i++) {
  	num[i] = num[(int)(i-ceil(sqrt(i)))] + num[(int)log(i)] + num[(int)(i*sin(i)*sin(i))];
  	num[i] %= N;
  }
  while (scanf("%lld", &n)) {
  	if (n == -1) return 0;
  	printf("%lld\n",num[n]);
  }
}
