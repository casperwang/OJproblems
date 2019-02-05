#include <bits/stdc++.h>
using namespace std;

string a, b;
bool tf = 1;

int main() {
  cin >> a >> b;
  if (a.length() != b.length()) cout << "No" << endl;
  else {
  	for (int i = 0; i < a.length(); i++) {
  	  if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
  	  	if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') {
  	  	  
		} else {
		  tf = 0;
		}
	  } else if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') {
  	  	if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
  	  	  
		} else {
		  tf = 0;
		}
	  } else {
	  	
	  }
	}
	if (tf) cout << "Yes" << endl;
	else cout << "No" << endl;
  }
  
  return 0;
}

