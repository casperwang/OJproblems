#include <iostream>
using namespace std;
bool a[5],b[5], ans;
int main() {
  while (cin >> a[0]) {
  	ans = 1;
  	for (int i = 1; i < 5; i++) cin >> a[i];
  	for (int i = 0; i < 5; i++) cin >> b[i];
  	for (int i = 0; i < 5; i++) if (a[i] == b[i]) ans = 0;
  	if (ans) cout << "Y" << endl;
  	else cout << "N" << endl;
  }
}
