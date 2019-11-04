#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100000
using namespace std;

int n, a, k, m;
vector <int> path[MAXN+5];
int dis[MAXN+5];

void dfs(int now, int par) {
  if (par != -1) dis[now] = dis[par]+1;
  for (auto i : path[now]) {
    if (i != par) dfs(i, now);
  }
}

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    while (cin >> a) {
      if (a == -1) break;
      path[k].pb(a);
      path[a].pb(k);
    }
    k++;
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    if (dis[i] > m) {
      m = dis[i], k = i;
    }
  }
  dis[k] = 0;
  dfs(k, -1);
  for (int i = 0; i < n; i++) {
    m = max(m, dis[i]);
  }
  cout << m << '\n';
  return 0;
}