#include <iostream>
#include <cstdio>
#include <map>
#define N 1000000
using namespace std;
long long int n, a[N+5], b[N+5], ans, p;
map <long long int, int> v;
int main() {
  scanf("%lld",&n);
  for (int i = 0; i < n; i++) {
  	scanf("%lld%lld",&a[i],&b[i]);
  	v[a[i]  ]++;
  	v[b[i]+1]--;
  }
  for (auto it : v) {
  	p += it.second;
  	ans = max(ans, p);
  }
  printf("%lld\n", ans);
  return 0;
}
