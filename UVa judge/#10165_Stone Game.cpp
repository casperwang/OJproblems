#include <bits/stdc++.h>
#define MAXN 1000000+5 
using namespace std;
int n, a, s;
int main() {
  while (cin >> n) {
  	if (!n) return 0;
  	s = 0;
  	for (int i = 0; i < n; i++) {
  		cin >> a;
  		s ^= a;
	}
	if (s) cout << "Yes" << endl;
	else cout << "No" << endl;
  }
  return 0;
}
