#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans;
string s;

int main() {
  cin >> n >> x >> y;
  cin >> s;
  int i = n-x;
  for (; i < n-y-1; i++) {
    if (s[i] == '1') ans++;
  }
  if (s[i] == '0') ans++;
  i++;
  for (; i < n; i++) {
    if (s[i] == '1') ans++;
  }
  cout << ans << endl;
}
