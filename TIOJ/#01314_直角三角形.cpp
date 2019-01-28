#include <iostream>
#include <cstdio>
#include <map>
#define N 1000000
using namespace std;
long long int n, a, b, c;
int main() {
  scanf("%lld",&n);
  for (int i = 0; i < n; i++) {
  	scanf("%lld%lld%lld",&a,&b,&c);
  	if (a > 0 && b > 0 && c > 0) {
  	  if (a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b) cout << "yes" << endl;
  	  else cout << "no" << endl;
  	} else cout << "no" << endl;
  }
  return 0;
}
