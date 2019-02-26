#include <bits/stdc++.h>
using namespace std; 

int n, k, abc[26], c, ans;
bool tf;
string a;

int main() {
  cin >> n >> k;
  cin >> a;
  for (int i = 0; i < a.length(); i++) {
    abc[a[i]-'a']++;
  }
  for (int i = 0; i < 26 && c < k; i++) {
    if (abc[i] && !tf) {
      c++;
      ans += i;
      tf = 1;
    } else {
      tf = 0;
    }
  }
  if (c == k) cout << ans+c << endl;
  else cout << -1 << endl;
  return 0;
}
