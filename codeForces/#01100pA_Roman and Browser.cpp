#include <iostream>
#define N 100
using namespace std;
int n, k, ans, s;
int a[N+5];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
  	s = 0;
  	for (int j = 1; j <= n; j++) {
  	  if ((j-i+k)%k) s += a[j];
	}
	s = max(s, -s);
	ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}
