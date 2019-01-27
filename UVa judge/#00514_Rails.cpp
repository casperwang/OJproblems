#include <iostream>
#define N 1000
using namespace std;
int n, num[N+5], m;
bool tf;
int main() {
  while (cin >> n) {
  	if (!n) return 0;
  	while (cin >> num[0]) {
  	  if (!num[0]) break;
  	  m = num[0];
  	  tf = 1;
  	  for (int i = 1; i < n; i++) {
  	  	cin >> num[i];
  	  	if (num[i] > num[i-1] && num[i] < m) tf = 0;
  	  	m = max(m, num[i]);
	  }
	  if (tf) cout << "Yes" << endl;
	  else cout << "No" << endl;
	}
	cout << endl;
  }
  return 0;
}
