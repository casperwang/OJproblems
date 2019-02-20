#include <bits/stdc++.h>
#define MAXN 1000000+5
#define INF 10234567890
using namespace std;

struct road{
  long long int a, b, v;
  road() {}
  road(long long int _a, long long int _b, long long int _v) : a(_a), b(_b), v(_v) {}
};


long long int n, e, s, g;
long long int a, b, v, now;
long long int dis[MAXN];
bool visited[MAXN];
vector <road> path[MAXN];

class cmp{
 public:
  bool operator() (const long long int a, const long long int b) {
    return dis[a] > dis[b];
  }
};

priority_queue <long long int, vector<long long int>, cmp> next_p;

int main() {
  scanf("%lld%lld%lld%lld", &n, &e, &s, &g);
  for (int i = 1; i <= n; i++) dis[i] = INF;
  for (int i = 0; i < e; i++) {
    scanf("%lld%lld%lld", &a, &b, &v);
    path[a].push_back( road(a, b, v) );
  }
  now = s;
  dis[s] = 0;
  while (now == s || next_p.size() > 0 && !visited[g]) {
    visited[now] = 1;
    for (int i = 0; i < path[now].size(); i++) {
      if (dis[now] + path[now][i].v < dis[path[now][i].b]) {
        dis[path[now][i].b] = dis[now] + path[now][i].v;
        next_p.push(path[now][i].b);
      }
    }
    while (next_p.size() && visited[next_p.top()]) next_p.pop();
    if (next_p.size()) now = next_p.top();
  }
  if (dis[g] == INF) printf("-1\n");
  else printf("%lld\n", dis[g]);
  return 0;
}

