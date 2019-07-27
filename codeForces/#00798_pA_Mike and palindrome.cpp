#include <bits/stdc++.h>
using namespace std;

string s;
bool tf;

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length()-i-1]) {
      if (!tf) s[i] = s[s.length()-i-1];
      else {
        cout << "NO" << endl;
        return 0; 
      } 
      tf = 1;
    }
  }
  if (tf) cout << "YES" << endl;
  else cout << "NO" << endl;
}
