#include <bits/stdc++.h>
#define MAXN 10000
#define pb push_back
using namespace std;

int t, n, m;
int a, b, cnt, mmax;
vector <int> path[MAXN+5];
vector <int> rpath[MAXN+5];
vector <int> npath[MAXN+5];
bool vis[MAXN+5];
int dfs[MAXN+5];
int sze[MAXN+5];
int deg[MAXN+5];
int dsu[MAXN+5];
int ans[MAXN+5];
queue <int> nxt;

void init(int n) {
  cnt = mmax = 0;
  memset(vis, 0, sizeof(vis));
  memset(dfs, 0, sizeof(dfs));
  memset(sze, 0, sizeof(sze));
  memset(dsu, 0, sizeof(dsu));
  memset(deg, 0, sizeof(deg));
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    path[i].clear();
    rpath[i].clear();
    npath[i].clear();
  }
}

void DFS(int now) {
  vis[now] = 1;
  for (int i : path[now]) {
    if (!vis[i]) DFS(i);
  }
  dfs[++cnt] = now;
}

void reDFS(int now, int anc) {
  vis[now] = 1;
  dsu[now] = anc;
  sze[anc]++;
  for (int i : rpath[now]) {
    if (!vis[i]) reDFS(i, anc);
  }
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      path[a].pb(b);
      rpath[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) DFS(i);
    }
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = n; i >= 1; i--) {
      if (!vis[dfs[i]]) reDFS(dfs[i], dfs[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j : path[i]) {
        if (dsu[i] != dsu[j]) {
          npath[dsu[i]].pb(dsu[j]);
          deg[dsu[j]]++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dsu[i] == i && deg[i] == 0) {
        ans[i] = sze[i];
        nxt.push(i);
      }
    }
    while (nxt.size()) {
      a = nxt.front();
      for (int i : npath[a]) {
        ans[i] = max(ans[i], sze[i] + ans[a]);
        deg[i]--;
        if (!deg[i]) nxt.push(i);
      }
      nxt.pop();
    }
    for (int i = 1; i <= n; i++) {
      mmax = max(mmax, ans[i]);
    }
    cout << mmax << '\n';
  }
}