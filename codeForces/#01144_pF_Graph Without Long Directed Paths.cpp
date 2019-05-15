#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

struct road{
  int a, b, i;
  bool dir = 0;
};

int n, m;
road edges[MAXN+5];
vector <int> path[MAXN];
int visited[MAXN];
bool ANS = 1;

void DFS(int now, bool tf) {
  visited[now] = tf+1;
  for (int i = 0; i < path[now].size(); i++) {
    if (!visited[path[now][i]]) DFS(path[now][i], !tf);
    else if (visited[path[now][i]] == visited[now]) ANS = 0;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> edges[i].a >> edges[i].b;
    edges[i].i = i;
    path[edges[i].a].push_back(edges[i].b);
    path[edges[i].b].push_back(edges[i].a);
  }
  DFS(1, 0);
  if (!ANS) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < m; i++) {
    if (visited[edges[i].a] == 1) cout << 1;
    else cout << 0;
  }
  cout << endl;
  return 0;
} 
