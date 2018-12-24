#include <iostream>
#include <cstdio>
#include <vector>
#define N 250
using namespace std;
int v, e, m;
int a, b, s, t;
vector <int> path[N+5];
long long int dp[N+5];
int in[N+5];
void DFS(int now) {
  in[now] = -1;
  dp[now] %= m;
  for (int i = 0; i < path[now].size(); i++) {
    dp[path[now][i]] += dp[now];
    in[path[now][i]]--;
  }
  for (int i = 1; i <= v; i++) {
    if (!in[i]) DFS(i);
  }
}
int main() {
  scanf("%d%d%d", &v, &e, &m);
  for (int i = 0; i < e; i++) {
    scanf("%d%d", &a, &b);
    path[a].push_back(b);
    in[b]++;
  }
  scanf("%d%d", &s, &t);
  dp[s] = 1;
  DFS(s);
  printf("%lld\n", dp[t]);
  return 0;
}
