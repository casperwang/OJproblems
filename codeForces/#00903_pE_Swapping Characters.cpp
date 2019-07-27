#include <bits/stdc++.h>
#define int long long
#define MAXN 5000
using namespace std;

int k, n, x;
string s[MAXN+5], p;
bool dif[MAXN+5][MAXN+5];
int difs[MAXN+5];
bool same[MAXN+5];
int appr[MAXN+5][26];
bool tf;

signed main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> s[i];
  }
  p = s[0];
  for (int m = 0; m < k; m++) {
    for (int i = 0; i < n; i++) {
      appr[m][s[m][i]-'a']++;
      for (int j = i+1; j < n; j++) {
        if (s[m][i] == s[m][j]) same[m] = 1;
      }
    }
  }
  for (int m = 1; m < k; m++) {
    bool tf = 1;
    for (int i = 0; i < 26; i++) {
      if (appr[m][i] != appr[0][i]) tf = 0;
    }
    if (!tf) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int m = 1; m < k; m++) {
    for (int i = 0; i < n; i++) {
      if (p[i] != s[m][i]) {
        dif[m][i] = 1;
        difs[m]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+!(same[0]); j < n; j++) {
      swap(p[i], p[j]);
      tf = 1;
      for (int m = 1; m < k; m++) {
        x = difs[m];
        if (p[i] == s[m][i] && dif[m][i]) x--;
        else if (p[i] != s[m][i] && !dif[m][i]) x++;
        if (p[j] == s[m][j] && dif[m][j]) x--;
        else if (p[j] != s[m][j] && !dif[m][j]) x++;
        if (!(x == 2 || (x == 0 && same[m]))) {
          tf = 0;
          break;
        }
      }
      if (tf) {
        cout << p << endl;
        return 0; 
      }
      swap(p[i], p[j]);
    }
  }
  cout << -1 << endl;
  return 0;
}
