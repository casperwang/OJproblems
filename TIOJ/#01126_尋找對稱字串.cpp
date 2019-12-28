#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define MAXN 60
using namespace std;

int ans, sum;
int dp[MAXN*2+5];
pii m;
string s1, s2;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> s1) {
    m.ff = ans = 0;
    s2 = "";
    for (int i = 0; i < s1.size(); i++)
      s2 = s2 + '^' + s1[i];
    s2 = s2 + '^';
    memset(dp, 0, sizeof(dp));
    //cout << s2 << "\n";
    for (int i = 0; i < s2.size(); i++) {
      if (m.ff > i)
        dp[i] = min(dp[2*m.ss-i], m.ff-i-1);
      while (s2[i+dp[i]] == s2[i-dp[i]]) {
        dp[i]++;
        if (i-dp[i] < 0) break;
        if (i+dp[i] >= s2.size()) break;
      }
      //cout << dp[i];
      m = max(m, pii(i+dp[i], i));
      ans = max(ans, dp[i]-1);
    }
    //cout << "\n";
    cout << ans << '\n';
  }
}