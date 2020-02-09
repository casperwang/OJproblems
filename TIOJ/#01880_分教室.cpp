#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
#define MOD 1000007
#define pb push_back
using namespace std;

int n, m;
int a, b, ans;
bool tf = 1;
bool vis[MAXN+5];
int bi[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int a) {
  vis[a] = 1;
  for (int i : path[a]) {
    if (!vis[i])
      bi[i] = !bi[a], DFS(i);
    else if (bi[i] == bi[a])
      tf = 0;
  }
}

int pw(int a, int n) {
  int t = 1;
  for (int i = 1; i <= n; i <<= 1) {
    if (i & n) t = (t * a) % MOD;
    a = (a * a) % MOD;
  }
  return t;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].pb(b);
    path[b].pb(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      ans++, bi[i] = 1, DFS(i);
  }
  if (tf) cout << pw(2, ans-1) << '\n';
  else cout << 0 << '\n';
}