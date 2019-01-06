#include <iostream>
using namespace std;
int t, n, a, b;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
  	cin >> n;
  	a = b = 0;
  	for (int k = n; k > 0; k/=2) {
  	  if (k % 2) a++;
    }
    for (int k = n; k > 0; k/=10) {
  	  for (int m = k%10; m > 0; m/=2) {
  	    if (m % 2) b++;
	  }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
