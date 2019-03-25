#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

int n, m, a, b;
int now;
bool appr[MAXN];
vector <int> path[MAXN];
vector <int> ans;
priority_queue <int> PQ;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a == b) continue;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  now = 1;
  for (int i = 0; i < n; i++) {
    appr[now] = 1;
    ans.push_back(now);
    for (int j = 0; j < path[now].size(); j++) {
      if (!appr[path[now][j]]) PQ.push(-path[now][j]);
    }
    while (PQ.size() && appr[-PQ.top()]) PQ.pop();
    if (PQ.size()) now = -PQ.top();
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
} 
