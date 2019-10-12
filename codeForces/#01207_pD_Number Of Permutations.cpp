#include <bits/stdc++.h>
#define MAXN 300000
#define MOD 998244353
#define int long long
using namespace std;

int n, a, b, ans = 1, s;
int num[MAXN+5];
map <int, int> appr[3];
pair<int, int> v[MAXN+5];
bool tf = 1;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  num[0] = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans * i) % MOD;
    num[i] = (num[i-1] * i) % MOD;
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v[i].first = a;
    v[i].second = b;
    appr[0][a]++;
    appr[1][b]++;
    appr[2][a*(MAXN+5)+b]++;
  }
  sort(v, v + n);
  for (int i = 1; i < n; i++) {
    if (v[i].second < v[i-1].second) tf = 0;
  }
  s = 1;
  for (auto i : appr[0]) {
    s = (s * num[i.second]) % MOD;
  }
  ans = (ans - s + MOD) % MOD;
  s = 1;
  for (auto i : appr[1]) {
    s = (s * num[i.second]) % MOD;
  }
  ans = (ans - s + MOD) % MOD;
  s = 1;
  for (auto i : appr[2]) {
    s = (s * num[i.second]) % MOD;
  }
  if (tf) ans = (ans + s + MOD) % MOD;
  cout << ans << endl;
} 

