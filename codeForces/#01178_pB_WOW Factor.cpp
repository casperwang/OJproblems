#include <bits/stdc++.h>
#define int long long
#define MAXN 1000000
using namespace std;
 
int ans, len;
int fro[MAXN+5], bac[MAXN+5];
char s[MAXN+5];
 
signed main() {
  cin >> s;
  while (s[len]) len++;
  for (int i = 1; i < len; i++) {
    fro[i] += fro[i-1];
    if (s[i] == s[i-1] && s[i] == 'v') fro[i]++;
  }
  for (int i = len-2; i >= 0; i--) {
    bac[i] += bac[i+1];
    if (s[i] == s[i+1] && s[i] == 'v') bac[i]++;
  }
  for (int i = 0; i < len; i++) {
    if (s[i] == 'o') ans += fro[i] * bac[i];
  }
  cout << ans << endl;
  return 0;
}
