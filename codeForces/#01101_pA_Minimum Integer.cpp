#include <iostream>
#include <cstdio>
using namespace std;
long long int t, a, b, c;
int main() {
  scanf("%lld",&t);
  for (int i = 0; i < t; i++) {
  	scanf("%lld%lld%lld",&a,&b,&c);
  	if (c < a) printf("%lld\n",c);
  	else printf("%lld\n",c*(b/c+1));
  } 
  return 0;
}
