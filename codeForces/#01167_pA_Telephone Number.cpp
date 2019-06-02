#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> s;
    int j = 0;
    while (s[j] != '8') j++;
    if (n - j >= 11) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
