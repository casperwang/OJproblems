#include <bits/stdc++.h>
#define pb push_back
#define MAXN 1000
using namespace std;

int n, m;
int a, b, cnt, sum;
int vis[MAXN+5], low[MAXN+5];
bool E[MAXN+5][MAXN+5];
bool bi[MAXN+5], ans[MAXN+5];
vector <int> path[MAXN+5];
stack <int> tmp;

bool DFS(int now, int par, bool clr) {
  vis[now] = low[now] = ++cnt;
  bi[now] = clr;
  if (par) tmp.push(now);
  bool tf = 0, d;
  for (int i : path[now]) {
    if (i == par) continue;
    if (!vis[i]) {
      d = DFS(i, now, !clr);
      low[now] = min(low[now], low[i]);
      if (low[i] >= vis[now]) {
        while (tmp.top() != i)
          ans[tmp.top()] |= d, tmp.pop();
        ans[i] |= d, ans[now] |= d;
        tmp.pop();
      } else tf |= d;
    } else if (vis[i] < vis[now]) {
      low[now] = min(low[now], vis[i]);
      if (bi[i] == bi[now]) tf = 1;
    }
  }
  return tf;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
    if (!n && !m) return 0;
    sum = cnt = 0;
    for (int i = 1; i <= n; i++) {
      vis[i] = low[i] = ans[i] = bi[i] = 0;
      path[i].clear();
      for (int j = 1; j <= n; j++)
        E[i][j] = 1;
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      E[a][b] = E[b][a] = 0;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (E[i][j] && i != j) path[i].pb(j);
    for (int i = 1; i <= n; i++)
      if (!vis[i]) DFS(i, 0, 0);
    for (int i = 1; i <= n; i++)
      sum += !ans[i];
    cout << sum << '\n';
  }
}