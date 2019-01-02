#include <cstdio>
#include <iostream>
#define N 1000000
using namespace std;
int T, n, num[N+5], ans[N+5];
int main() {
  for (int i = 1; i <= N; i++) {
  	for (int j = i; j <= N; j += i) {
  	  num[j]++;
	}
	if (num[i] >= num[ans[i-1]]) ans[i] = i;
	else ans[i] = ans[i-1];
  }
  scanf("%d",&T);
  for (int i = 0; i < T; i++) {
  	scanf("%d",&n);
  	printf("%d\n", ans[n]);
  }
  return 0;
}
