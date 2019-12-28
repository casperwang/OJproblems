#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, ans;
int tf;
int abc[26];
int num[22];
string s;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  num[0] = 1;
  for (int i = 1; i < 22; i++)
    num[i] = num[i-1]*i;
  cin >> t;
  while (t--) {
    cin >> s;
    tf = 0;
    memset(abc, 0, sizeof(abc));
    for (int i = 0; i < s.size(); i++)
      abc[s[i]-'a']++;
    ans = num[s.size()/2];
    for (int i = 0; i < 26; i++) {
      if (abc[i] % 2) tf++;
      ans /= num[abc[i]/2];
    }
    if (tf <= 1) cout << ans << '\n';
    else cout << 0 << '\n';
  }
  return 0;
}