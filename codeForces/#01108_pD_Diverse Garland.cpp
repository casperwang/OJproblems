#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    if (s[i-1] == s[i]) {
      k++;
      if (s[i-1] != 'R' && (i == n-1 || s[i+1] != 'R')) s[i] = 'R';
      if (s[i-1] != 'G' && (i == n-1 || s[i+1] != 'G')) s[i] = 'G';
      if (s[i-1] != 'B' && (i == n-1 || s[i+1] != 'B')) s[i] = 'B';
    }
  }
  cout << k << endl;
  cout << s << endl;
  return 0;
}
