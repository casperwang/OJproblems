#include <iostream>
#define N 1000
using namespace std;
int t, n, req, a;
bool bag[N+5];
int main() {
  cin >> t;
  bag[0] = 1;
  for (int i = 0; i < t; i++) {
  	cin >> req >> n;
  	for (int i = 1; i <= req; i++) bag[i] = 0;
  	for (int i = 0; i < n; i++) {
  	  cin >> a;
  	  for (int j = req-a; j >= 0; j--) {
  	  	if (bag[j]) bag[j+a] = 1;
	  }
	}
	if (bag[req]) cout << "YES" << endl;
	else cout << "NO" << endl;
  }
}
