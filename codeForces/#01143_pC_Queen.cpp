#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, a, b;
int parent[MAXN+5];
int ind[MAXN+5];
bool visit[MAXN+5];
bool tf[MAXN+5];
bool appr[MAXN+5];
vector <int> ans;

void DFS(int now) {
  if (!appr[now]) ans.push_back(now);
  appr[now] = 1;
  if (!visit[now]) ind[parent[now]]--;
  visit[now] = 1;
  if (!ind[parent[now]] && tf[parent[now]]) {
    DFS(parent[now]);
  }
  parent[now] = -1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    tf[i] = b;
    if (a != -1) {
      ind[a]++;
      parent[i] = a;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (parent[i] != -1 && !ind[i] && tf[i]) {
      DFS(i);
    } else if (tf[i]) {
      if (!visit[i]) ind[parent[i]]--;
      visit[i] = 1;
      if (parent[parent[i]] != -1 && !ind[parent[i]] && tf[parent[i]]) {
        DFS(parent[i]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size()) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
