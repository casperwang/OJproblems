#include <cstdio>
#include <iostream>
using namespace std;
string a, b;
int main() {
  cin >> a;
  for (int i = 0; i < 5; i++) {
  	cin >> b;
  	if (b[0] == a[0] || b[1] == a[1]) {
  	  cout << "YES" << endl;
  	  return 0;
	}
  }
  cout << "NO" << endl;
  return 0;
}
