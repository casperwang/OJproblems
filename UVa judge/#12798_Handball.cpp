#include <iostream>
using namespace std;
int m, n, ans, t, tf;
int main() {
  while (cin >> n >> m) {
  	ans = 0;
  	for (int i = 0; i < n; i++) {
  	  tf = 1;
  	  for (int j = 0; j < m; j++) {
  	  	cin >> t;
  	  	if (!t) tf = 0;
	  }
	  ans += tf;
	}
	cout << ans << endl; 
  }
}
