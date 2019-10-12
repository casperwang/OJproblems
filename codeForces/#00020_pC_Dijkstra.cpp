#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1e18
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, m;
int a, b, c;
vector < pair<int, int> > path[MAXN+5];
int dis[MAXN+5], par[MAXN+5];
stack <int> ans;
priority_queue < pair<int,int>, vector < pair<int,int> >, greater< pair<int,int> > > arr;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) dis[i] = INF, par[i] = i;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    path[a].pb({b, c});
    path[b].pb({a, c});
  }
  arr.push({0, MAXN+5+1});
  pair <int, int> tmp;
  int now;
  for (int i = 0; i < n && arr.size(); i++) {
    while (arr.size() && dis[arr.top().ss/(MAXN+5)] != INF) arr.pop();
    if (!arr.size()) break;
    tmp = arr.top();
    arr.pop();
    now = tmp.ss/(MAXN+5);
    dis[now] = tmp.ff;
    par[now] = tmp.ss % (MAXN+5);
    for (int j = 0; j < path[now].size(); j++) {
      if (dis[path[now][j].ff] == INF) {
        arr.push({path[now][j].ss + tmp.ff
          , path[now][j].ff*(MAXN+5)+now});
      }
    }
    if (tmp.ss == n) break;
  }
  if (par[n] == n) {
    cout << -1 << endl;
    return 0;
  }
  now = n;
  while (par[now] != now) {
    ans.push(now);
    now = par[now];
  }
  ans.push(1);
  while (ans.size()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << endl;
  return 0;
}