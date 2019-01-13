#include <iostream>
#define N 100
using namespace std;
string s;
int op[N+5];
int t, n, ans, o;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
  	cin >> n;
  	ans = 0;
  	for (int i = 0; i < n; i++) {
  	  cin >> s;
  	  if (s == "LEFT") {
		op[i] = -1;
	  } else if (s == "RIGHT") {
		op[i] = 1;
	  } else {
  	  	cin >> s >> o;
  	  	op[i] = op[o-1];
	  }
	  ans += op[i];
	}
	cout << ans << endl; 
  }
}
