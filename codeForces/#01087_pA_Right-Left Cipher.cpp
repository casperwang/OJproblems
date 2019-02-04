#include <iostream>
using namespace std;
string s, ans;
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if ((i+s.length()%2) % 2 == 1) ans = s[i/2] + ans;
    else ans = s[s.length()-1-i/2] + ans;
  }
  cout << ans << endl;
  return 0;
}
