#include <iostream>
using namespace std;
string s, ans;
int c, n;
int main() {
  cin >> n >> s;
  for (int i = 1; c < n; i++) {
    ans += s[c];
    c += i;
  }
  cout << ans << endl;
}
