#include <bits/stdc++.h>
using namespace std;

int n, a, b, ak, bk;
string s;
bool tf = 1;

signed main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?' && i < n/2) ak++;
    else if (s[i] == '?') bk++;
    else if (i < n/2) a += s[i]-'0';
    else b += s[i]-'0';
  }
  if (bk*9+b-a == ak*9+a-b) cout << "Bicarp" << endl;
  else cout << "Monocarp" << endl;
  return 0;
}