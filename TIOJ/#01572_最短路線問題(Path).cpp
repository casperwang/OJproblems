#include <bits/stdc++.h>
#define MAXN 800000
#define pb push_back
using namespace std;
 
int n, m, s, t;
int a, b, tmp;
int anc[MAXN+5];
int dis[MAXN+5];
vector <int> path[MAXN+5];
stack <int> ans;
queue <int> nxt;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++)
  	path[i].reserve(2);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].pb(b);
    path[b].pb(a);
  }
  for (int i = 1; i <= n; i++)
  	sort(path[i].begin(), path[i].end());
  nxt.push(s);
  dis[s] = 1;
  while (!dis[t]) {
    tmp = nxt.front();
    nxt.pop();
    for (int i : path[tmp]) {
      if (!dis[i]) {
        anc[i] = tmp;
        dis[i] = dis[tmp]+1;
        nxt.push(i);
      }
    }
  }
  cout << dis[t]-2 << '\n';
  tmp = t;
  while (tmp) {
    ans.push(tmp);
    tmp = anc[tmp];
  }
  while (ans.size()) {
    cout << ans.top();
    ans.pop();
    if (ans.size()) cout << "-";
  }
  cout << "\n";
}