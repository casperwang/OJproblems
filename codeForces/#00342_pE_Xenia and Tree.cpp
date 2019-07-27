#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
#define INF 214748364
using namespace std;
 
int n, m, k;
int u, v, t;
vector <int> path[MAXN+5];
vector <int> toDo; 
vector <int> arr;
vector <pair<int, int>> qry;
vector <int> STarr[20];
int   vis[MAXN+5];
bool  visited[MAXN+5];
int   dis[MAXN+5];
int   pow2[25];
int   ans[MAXN+5];
int   L[MAXN+5], R[MAXN+5];
 
void DFS(int now, int dis) {
  ans[now] = dis;
  for (int i = 0; i < path[now].size(); i++) {
    if (dis+1 < ans[path[now][i]]) DFS(path[now][i], dis+1);
  }
}
 
void dfs(int now, int k) {
  visited[now] = 1;
  L[vis[now]] = STarr[0].size();
  STarr[0].push_back(vis[now]);
  //cout << vis[now] << " "; 
  dis[vis[now]] = k;
  for (int i = 0; i < path[now].size(); i++) {
    if (!visited[path[now][i]]) {
      dfs(path[now][i], k+1);
      STarr[0].push_back(vis[now]);
      //assert(vis[now] < vis[path[now][i]]);
      //cout << vis[now] << " "; 
    }
  }
}
 
void ST() {
  for (int i = 1; pow2[i] <= STarr[0].size(); i++) {
    for (int j = 0; j <= STarr[0].size()-pow2[i]; j++) {
      STarr[i].push_back(min(STarr[i-1][j], STarr[i-1][j+pow2[i-1]]));
    }
  }
}
 
int RMQ(int l, int r) {
  int k = std::__lg(r-l+1);
	return min(STarr[k][l], STarr[k][r-(1<<k)+1]);
}
 
int dist(int a, int b) {
  a = vis[a], b = vis[b];
  //cout << a << " " << b << endl;
  return dis[a] + dis[b] - 2 * dis[RMQ(min(L[a], L[b]), max(L[a], L[b]))];
}
 
void BFS() {
  queue <int> arr;
  arr.push(1);
  int p = 1;
  vis[1] = 1;
  while (arr.size()) {
    for (int i = 0; i < path[arr.front()].size(); i++) {
      if (!vis[path[arr.front()][i]]) {
        arr.push(path[arr.front()][i]);
        vis[path[arr.front()][i]] = ++p;
      }
    }
    arr.pop();
  }
  //assert(p == n);
}
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  L[1] = 0;
  for (int i = 0, k = 1; i < 25; i++, k *= 2) pow2[i] = k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) ans[i] = INF;
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v;
    path[u].push_back(v);
    path[v].push_back(u);
  }
  BFS();
  //for (int i = 1; i <= n; i++) cout << vis[i] << endl;
  dfs(1, 0);
  ST();
  DFS(1, 0);
  for (int i = 0; i < m; i++) {
    cin >> t >> v;
    qry.push_back({t, v});
    if (t == 2) k++;
  }
  for (int i = 0; i < m; i++) {
    t = qry[i].first;
    v = qry[i].second;
    if (t == 1) {
      arr.push_back(v);
      if (arr.size() >= 101) {
        queue <pair<int, int>> BFSarr;
        for (auto j : arr) BFSarr.push({j, 0}), ans[j] = 0;
        while (BFSarr.size()) {
          pair<int, int> x = BFSarr.front();
          for (int w = 0; w < path[x.first].size(); w++) {
            if (ans[path[x.first][w]] > x.second+1) {
              ans[path[x.first][w]] = x.second+1;
              BFSarr.push({path[x.first][w], x.second+1});
            }
          }
          BFSarr.pop();
        }
        arr.clear();
      }
    } else {
      int tmp = ans[v];
      for (auto j : arr) {
        tmp = min(tmp, dist(v, j));
      }
      cout << tmp << endl;
    }
  }
  return 0;
}
