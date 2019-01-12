#include <iostream>
#include <cstdio>
#define N 1000000
using namespace std;
int num[N+5], tmp[N+5];
long long int n, ans, t;
void MS(int L, int R) {
  if (L+1 == R) {
  	return;
  }
  int mid = (L+R)/2;
  MS(L,mid);
  MS(mid,R);
  for (int i = L, j = mid, k = L; k < R; k++) {
  	if ((i < mid && num[i] <= num[j]) || j == R) {
  	  tmp[k] = num[i++];
	} else {
	  ans += j-k;
	  tmp[k] = num[j++];
	}
  }
  for (int k = L; k < R; k++) num[k] = tmp[k];
}
int main() {
  while (scanf("%d",&n)) {
  	if (!n) return 0;
  	for (int i = 0; i < n; i++) {
  	  scanf("%d",&num[i]);
	}
	ans = 0;
	MS(0,n);
	printf("Case #%d: %lld\n",++t,ans);
  }
}
