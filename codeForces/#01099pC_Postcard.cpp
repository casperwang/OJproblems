#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
string s, ans;
int n, a, b, len;
int main() {
  cin >> s >> n;
  for (int i = 0; i < s.length(); i++) {
  	if (s[i] == '?') a++;
  	else if (s[i] == '*') b++;
  }
  if (s.length()-2*a-2*b > n) {
  	cout << "Impossible" << endl;
  } else if (b == 0 && s.length()-a < n) {
  	cout << "Impossible" << endl;
  } else {
  	if (s.length()-a-b > n) {
  	  len = s.length()-a-b;
  	  for (int i = 0; i < s.length(); i++) {
  	  	if (i+1 < s.length() && (s[i+1] == '?' || s[i+1] == '*') && len > n) {
  	  	  len--;
		} else if (s[i] != '?' && s[i] != '*') {
		  ans += s[i];
		}
	  }
	} else {
	  len = s.length()-a-b;
	  for (int i = 0; i < s.length(); i++) {
  	  	if (s[i] != '?' && s[i] != '*') {
		  ans += s[i];
		}
		if (i+1 < s.length() && s[i+1] == '*') {
		  while (len < n) {
		  	ans += s[i];
		  	len++;
		  }
		}
	  }
	}
	cout << ans << endl;
  }
  return 0;
}
