#include <iostream>
#include <cstdio>
using namespace std;
long long int n;
int main() {
  scanf("%lld",&n);
  if ((n*(n+1)) % 4 == 0) printf("0\n");
  else printf("1\n");
  return 0;
}
