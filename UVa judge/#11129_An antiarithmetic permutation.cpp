#include <cstdio>
#include <iostream>
#define N 16384
using namespace std;
int ans[N+5], n;
int main() {
  ans[1] = 1;
  for (int i = 1; i <= N/2; i *= 2) {
  	for (int j = 1; j <= i; j++) {
  	  ans[j] = ans[j] * 2 - 1;
  	  ans[j+i] = ans[j] + 1;
	}
  }
  while (cin >> n) {
  	if (!n) return 0;
  	cout << n << ": ";
  	for (int i = 1; i <= N; i++) {
  	  if (ans[i] <= n) {
  	  	if (i > 1) cout << " "; 
  	  	cout << ans[i]-1;
	  }
	}
	cout << endl;
  }
  return 0;
}
