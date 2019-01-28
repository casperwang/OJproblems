#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 2147483648
using namespace std;
long long int n, num, ans;
long long int a, b, c;
vector <long long int> m;
int main() {
  scanf("%lld",&n);
  a = b = 1;
  m.push_back(1);
  while (c < N) {
  	c = a+b;
  	a = b;
  	b = c;
  	m.push_back(c);
  }
  for (int i = 1; i <= n; i++) {
  	scanf("%lld",&num);
  	ans = 0;
  	for (int j = m.size()-1; j >= 0; j--) {
  	  if (num >= m[j]) {
  	  	ans++;
  	  	num -= m[j];
	  }
	}
	if (!num) printf("%lld\n",ans);
	else printf("iyada~\n");
  }
  return 0;
}
