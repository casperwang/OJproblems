#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long int n;
int main() {
  while (scanf("%lld",&n)) {
  	if (!n) return 0;
  	if (floor(sqrt(n)) * floor(sqrt(n)) < n) printf("no\n");
  	else printf("yes\n");
  }
  return 0;
}
