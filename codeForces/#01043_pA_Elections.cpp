#include <bits/stdc++.h>
using namespace std;

long long int n, a, m, s;
int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
  	scanf("%d",&a);
  	s += a;
  	m = max(m, a);
  }
  if (m*n - s > s) printf("%d\n",m);
  else printf("%d\n",max(m, (2*s - m*n) / n + 1 + m));
  return 0;
}
