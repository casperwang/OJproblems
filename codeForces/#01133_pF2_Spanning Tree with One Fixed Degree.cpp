#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

int n, m, k;
int a, b, max_degree, pos;
vector <int> path[MAXN];
queue <int> arr;
bool visited[MAXN];
bool dfs_visited[MAXN];
vector <int> impt; 

int DFS(int now) {
  dfs_visited[now] = 1;
  int c = 0;
  for (int i = 0; i < path[now].size(); i++) {
    if (!dfs_visited[path[now][i]]) {
      DFS(path[now][i]);
      if (now == 1) impt.push_back(path[now][i]);
      c++;
    }
  }
  return c;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  if (DFS(1) > k || path[1].size() < k) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  visited[1] = 1;
  for (int i = 0; i < impt.size(); i++) {
    cout << 1 << " " << impt[i] << endl;
    visited[impt[i]] = 1;
    arr.push(impt[i]);
    k--;
  }
  for (int i = 0; k; i++) {
    if (!visited[path[1][i]]) {
      cout << 1 << " " << path[1][i] << endl;
      visited[path[1][i]] = 1;
      arr.push(path[1][i]);
      k--;
    }
  }
  while (arr.size()) {
    pos = arr.front();
    visited[pos] = 1;
    for (int i = 0; i < path[pos].size(); i++) {
      if (!visited[path[pos][i]] && path[pos][i] != 1) {
        cout << pos << " " << path[pos][i] << endl;
        visited[path[pos][i]] = 1;
        arr.push(path[pos][i]);
      }
    }
    arr.pop();
  }
} 
