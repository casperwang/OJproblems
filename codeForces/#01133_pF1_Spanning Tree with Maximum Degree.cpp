#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

int n, m;
int a, b, max_degree, pos;
vector <int> path[MAXN];
queue <int> arr;
bool visited[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (path[i].size() > max_degree) {
      max_degree = path[i].size();
      pos = i;
    }
  }
  arr.push(pos);
  while (arr.size()) {
    pos = arr.front();
    visited[pos] = 1;
    for (int i = 0; i < path[pos].size(); i++) {
      if (!visited[path[pos][i]]) {
        cout << pos << " " << path[pos][i] << endl;
        visited[path[pos][i]] = 1;
        arr.push(path[pos][i]);
      }
    }
    arr.pop();
  }
} 
