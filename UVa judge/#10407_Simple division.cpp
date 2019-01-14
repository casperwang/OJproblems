#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;
int gcd(int a, int b) {
  return (!b) ? a : gcd(b,a%b);
}
int n[N+5], a, k, ans;
int main() {
  while (cin >> a) {
  	if (!a && !k) return 0;
  	if (!a) {
  	  sort(n, n+k);
  	  ans = n[1]-n[0];
  	  for (int i = 2; i < k; i++) {
  	  	ans = gcd(ans, n[i]-n[i-1]);
	  }
	  cout << ans << endl;
	  k = 0;
  	  continue;
	}
  	n[k++] = a;
  }
  return 0;
}
