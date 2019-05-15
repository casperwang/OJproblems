#include <bits/stdc++.h>
using namespace std;

int n;
string m;

int main() {
  cin >> n >> m;
  if (n < m.length()) cout << -1 << endl;
  else {
    cout << m;
    for (int i = m.length(); i < n; i++) {
      cout << 0;
    }
    cout << endl;
  }
  return 0;
}
