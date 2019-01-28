#include <iostream>
#include <cstdio>
#include <stack>
#define N 1000000
using namespace std;
long long int n, m, k, ans;
long long int num[N+5], a[N+5], b[N+5];
int main() {
  while (scanf("%lld",&n) != EOF) {
  	stack <long long int> maximum;
  	m = k = 0;
  	for (int i = 0; i < n-1; i++) {
  	  scanf("%lld",&num[i]);
  	  while (maximum.size() && num[maximum.top()] < num[i]) {
  	    a[maximum.top()] = i-maximum.top();
  	    maximum.pop();
	  }
	  maximum.push(i);
	}
	while (maximum.size() > 0) {
      a[maximum.top()] = n-maximum.top()-1;
      maximum.pop();
	}
	for (int i = n-2; i >= 0; i--) {
  	  while (maximum.size() && num[maximum.top()] <= num[i]) {
  	    b[maximum.top()] += maximum.top()-i;
  	    maximum.pop();
	  }
	  maximum.push(i);
	}
	while (maximum.size() > 0) {
      b[maximum.top()] = maximum.top()+1;
      maximum.pop();
	}
	for (int i = 0; i < n-1; i++) {
	  ans += a[i]*b[i]*num[i];
	}
	printf("%lld\n",ans);
  }
  return 0;
}
