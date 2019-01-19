#include <iostream>
#include <cstdio>
using namespace std;
string s;
int a, b, ans;
int main() {
  cin >> s;
  b = s.length()-1;
  while (a <= b && s[a] != '[') a++;
  while (a <= b && s[a] != ':') a++;
  while (b >= 0 && s[b] != ']') b--;
  while (b >= 0 && s[b] != ':') b--;
  if (a < b && a < s.length() && b >= 0) ans = 4;
  else ans = -1;
  for (int i = a; i <= b; i++) {
  	if (s[i] == '|') ans++;
  }
  cout << ans << endl;
  return 0;
}
