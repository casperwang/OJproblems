#include <bits/stdc++.h>
using namespace std;

string s;
bool tf;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> s) {
  	tf = 1;
  	for (int i = 0; i < s.size()/2; i++) {
  		if (s[i] != s[s.size()-1-i]) tf = 0;
  	}
  	if (tf) cout << "palindrome\n";
  	else cout << "not palindrome\n";
  }
}
