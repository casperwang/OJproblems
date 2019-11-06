#include <bits/stdc++.h>
#define MAXN 10000
#define pb push_back
using namespace std;

int n, m;
int a, b;
string s;
bool vis[MAXN+5], ans[MAXN+5];
vector <int> path[MAXN+5];

bool DFS(int now) {
  bool tf = 1;
  vis[now] = 1;
  for (int i : path[now])
    tf &= (vis[i]?ans[i]:DFS(i));
  ans[now] = !tf;
  return !tf;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
    if (!n && !m) return 0;
    for (int i = 1; i <= n; i++) path[i].clear(), vis[i] = 0;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      path[a].pb(b);
    }
    cin >> s;
    if (DFS(1) ^ (s == "Mimi")) cout << "Mimi" << '\n';
    else cout << "Moumou" << '\n';
  }
  return 0;
}