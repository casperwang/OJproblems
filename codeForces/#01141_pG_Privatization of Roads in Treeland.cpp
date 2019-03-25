#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

class Cmp{
  public:
    bool operator() (const pair <int, int> a, const pair <int, int> b) {
      if (a.first != b.first) return a.first > b.first;
      else return a.second > b.second;
    }
};

long long int n, k;
pair <int, int> roads[MAXN];
pair <int, int> degree[MAXN];
map <pair <int, int>, int, Cmp> pos;
vector <int> path[MAXN];
bool tf[MAXN];
bool visited[MAXN];
int ans[MAXN];

bool cmp(const pair <int, int> a, const pair <int, int> b) {
  return a.first > b.first;
}

void DFS(int now, int e) {
  int m = 1;
  visited[now] = 1;
  for (int i = 0; i < path[now].size(); i++) {
    if (!visited[path[now][i]]) {
      if (m == e && !tf[now]) m++;
      ans[max(pos[pair<int,int>(path[now][i], now)], pos[pair<int,int>(now, path[now][i])])] = m;
      DFS(path[now][i], m);
      if (!tf[now]) m++;
    }
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n-1; i++) {
    cin >> roads[i].first >> roads[i].second;
    pos[roads[i]] = i;
    path[roads[i].first].push_back(roads[i].second);
    path[roads[i].second].push_back(roads[i].first);
    degree[roads[i].first].first++;
    degree[roads[i].first].second = roads[i].first;
    degree[roads[i].second].first++;
    degree[roads[i].second].second = roads[i].second;
  }
  sort(degree+1, degree+n+1, cmp);
  for (int i = 1; i <= k; i++) {
    tf[degree[i].second] = 1;
  }
  cout << degree[k+1].first << endl;
  DFS(degree[k+1].second, 0);
  for (int i = 0; i < n-1; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
