#include <bits/stdc++.h>
#define MAXN 1
using namespace std;

int pos = -1, n;
char k;
string s;

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] >= k) {
      k = s[i];
      pos = i;
    } else {
      cout << "YES" << endl;
      cout << pos+1 << " " << i+1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
