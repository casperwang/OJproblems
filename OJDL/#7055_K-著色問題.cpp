#include <bits/stdc++.h>
#define MAXN 18
#define pb push_back
#define mmax(a,b) (a>b?a:b)
#define MOD 1000000007
using namespace std;

int n, m, k;
int a, b, t;
bool tf;
long long dp[MAXN+1][(1<<MAXN)+1];
bool adj[MAXN+1][MAXN+1];
vector <int> v, nv;

signed main(){
  v.reserve(MAXN);
  nv.reserve(MAXN);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    adj[a][b] = adj[b][a] = 1;
  }
  for (int i = 1; i <= MAXN; i++)
    dp[i][0] = 1;
  for (int i = 1; i < (1<<n); i++) {
    tf = 1;
    for (int x = 0; x < n; x++) {
      for (int y = x+1; y < n; y++) {
        if (adj[x][y] && (i & (1<<x)) && (i & (1<<y))) {
          tf = 0;
          break;
        }
      }
    }
    dp[1][i] = tf;
  }
  for (int c = 2; c <= mmax(k, n); c++) {
    for (int i = 1; i < (1<<n); i++) {
      v.clear();
      for (int j = 0; j < n; j++)
        if (i & (1<<j)) v.pb(j);
      a = *v.crbegin();
      for (int j = 0; j < (1<<(v.size()-1)); j++) {
        nv.clear();
        nv.pb(a);
        tf = 1, t = (1<<a);
        for (int p = 0; p < v.size()-1; p++) {
          if (j & (1<<p)) {
            for (int x : nv) {
              if (adj[x][v[p]]) {
                tf = 0;
                break;
              }
            }
            nv.pb(v[p]), t ^= (1<<v[p]);
          }
        }
        if (tf) {
          dp[c][i] += c * dp[c-1][i^t];
          dp[c][i] = dp[c][i] > MOD ? dp[c][i] % MOD : dp[c][i];
        }
      }
      //cout << dp[c][i] << " ";
    }
    if (c >= k && dp[c][(1<<n)-1])
      break;
    //cout << '\n';
  }
  for (int i = 1; i <= n; i++) {
    if (dp[i][(1<<n)-1]) {
      cout << i << '\n';
      break;
    }
  }
  cout << dp[k][(1<<n)-1] << '\n';
}