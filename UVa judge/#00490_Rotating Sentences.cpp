#include <iostream>
using namespace std;
string s[200+5];
int len, m;
int main() {
  while (getline(cin, s[len])) {
  	m = max(m, (int)s[len].length());
  	len++;
  }
  for (int i = 0; i < m; i++) {
  	for (int j = len-1; j >= 0; j--) {
  	  if (s[j].length() > i) cout << s[j][i];
  	  else cout << " ";
	}
	cout << endl;
  } 
  return 0;
}
