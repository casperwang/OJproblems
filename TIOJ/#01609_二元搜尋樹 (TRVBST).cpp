#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1000000
using namespace std;
int n, ans[N+5];
int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
  	scanf("%d",&ans[i]);
  }
  sort(ans, ans+n);
  for (int i = 0; i < n; i++) {
  	if (i) printf(" ");
  	printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
