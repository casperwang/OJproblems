#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

string a, b;
short dp[MAXN+5][MAXN+5];
short pre[MAXN+5][MAXN+5];
int appr[10];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    appr[a[i]-'0']++;
  }
  for (int i = 0; i < 10; i++) {
    if (appr[i] >= 1000) {
      for (int j = 0; j < 1000; j++) {
        cout << (char)(i+'0');
      }
      cout << '\n';
      return 0;
    }
  }
  for (int i = a.size()-1; i >= 0; i--) {
    b += a[i];
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      if (a[i] == b[j]) {
        dp[i+1][j+1] = dp[i][j]+1;
        pre[i+1][j+1] = 0;
      } else {
        dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        if (dp[i][j+1] > dp[i+1][j]) {
          pre[i+1][j+1] = -1;
        } else {
          pre[i+1][j+1] = 1;
        }
      }
      //cout << dp[i+1][j+1] << " \n"[j==a.size()-1];
    }
  }
  int i = a.size()-1, j = a.size()-1;
  int len = dp[i+1][j+1];
  while (len) {
    if (pre[i+1][j+1] == 0) {
      cout << a[i];
      len--, i--, j--;
    } else if (pre[i+1][j+1] == -1) {
      i--;
    } else {
      j--;
    }
  }
  cout << '\n';
  return 0;
}