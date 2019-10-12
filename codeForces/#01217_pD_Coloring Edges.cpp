#include <bits/stdc++.h>
#define MAXN 5000
#define pb push_back
using namespace std;

int n, m;
int a, b;
bool vis[MAXN+5], now[MAXN+5], tf;
vector < pair<int,int> > edges;
int ans[MAXN+5];
vector <int> path[MAXN+5];
map < pair<int,int>, int > appr;

void DFS(int a, bool now[MAXN+5]) {
  vis[a] = now[a] = 1;
  for (int i = 0; i < path[a].size(); i++) {
    if (!now[path[a][i]]) {
      ans[appr[{a, path[a][i]}]] = 1;
      if (!vis[path[a][i]]) DFS(path[a][i], now);
    } else {
      ans[appr[{a, path[a][i]}]] = 2;
      tf = 1;
    }
  }
  now[a] = 0;
  return;
}

signed main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].pb(b);
    edges.pb({a, b});
    appr[{a, b}] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && path[i].size()) DFS(i, now);
  }
  if (tf) cout << 2 << endl;
  else cout << 1 << endl;
  for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i==m-1];
  return 0;
}