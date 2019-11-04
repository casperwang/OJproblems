#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAXN 100
#define ff first
#define ss second
#define pb push_back
#define INF 1e9
using namespace std;

int n, m;
int a, b, c;
int s, t;
int v, dis;
vector <pii> path[MAXN+5];
int d1[MAXN+5], d2[MAXN+5];
priority_queue <pii> nxt;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      path[i].clear();
      d1[i] = d2[i] = INF;
    }
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      path[a].pb({b, c});
      path[b].pb({a, c});
    }
    cin >> s >> t;
    d1[s] = 0;
    nxt.push(pii(0, s));
    while (!nxt.empty()) {
      v = nxt.top().ss, dis = nxt.top().ff;
      nxt.pop();
      if (d2[v] < dis) continue;
      for (pii i : path[v]) {
        if (dis+i.ss < d1[i.ff]) {
          d2[i.ff] = d1[i.ff];
          d1[i.ff] = dis+i.ss;
          nxt.push(pii(d1[i.ff], i.ff));
        } else if (dis+i.ss != d1[i.ff] && dis+i.ss < d2[i.ff]) {
          d2[i.ff] = dis+i.ss;
          nxt.push(pii(d2[i.ff], i.ff));
        }
      }
    }
    if (d2[t] == INF) cout << -1 << '\n';
    else cout << d2[t] << '\n';
  }
  return 0;
}