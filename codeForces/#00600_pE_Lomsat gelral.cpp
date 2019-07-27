#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAXN 100000
using namespace std;

int n, m, now_ans;
int c[MAXN+5];
int u, v;
int sze[MAXN+5], ans[MAXN+5];
int cnt[MAXN+5], arr[MAXN+5];
bool visited[MAXN+5];
vector <int> path[MAXN+5];
vector <int> toDel; 

int DFS_sze(int now) {
  sze[now] = 1;
  for (int i = 0; i < path[now].size(); i++) {
    sze[now] += DFS_sze(path[now][i]);
  }
  return sze[now];
}

void update(int now) {
  arr[cnt[c[now]]]--;
  cnt[c[now]]++;
  arr[cnt[c[now]]]++;
  if (cnt[c[now]] > m) {
    m = cnt[c[now]];
    now_ans = c[now];
  } else if (cnt[c[now]] == m) {
    now_ans += c[now];
  }
  toDel.pb(c[now]);
}

void DFS(int now) {
  update(now);
  for (int i = 0; i < path[now].size(); i++) {
    DFS(path[now][i]);
  }
}

void DFS_ans(int now, bool tf) {
  int mmax = 0, k = 0;
  for (int i = 0; i < path[now].size(); i++) {
    if (sze[path[now][i]] > mmax) {
      mmax = sze[path[now][i]];
      k = path[now][i];
    }
  }
  for (int i = 0; i < path[now].size(); i++) {
    if (path[now][i] != k) DFS_ans(path[now][i], 0);
  }
  if (k) DFS_ans(k, 1);
  for (int i = 0; i < path[now].size(); i++) {
    if (path[now][i] != k) DFS(path[now][i]);
  }
  update(now);
  ans[now] = now_ans;
  if (!tf) {
    for (auto i : toDel) {
      arr[cnt[i]] = 0;
      cnt[i] = 0;
    }
    toDel.clear();
    now_ans = m = 0;
  }
  return;
}

void dfs(int now) {
  visited[now] = 1;
  for (int i = 0; i < path[now].size(); i++) {
    if (visited[path[now][i]]) path[now].erase(path[now].begin()+i), i--;
    else dfs(path[now][i]);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    path[u].pb(v);
    path[v].pb(u);
  }
  dfs(1);
  DFS_sze(1);
  DFS_ans(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i==n];
  }
  return 0;
}
