#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100000
using namespace std;
int n, m, s, r;
int sum[N+5], ans;
bool tf = 1;
vector <int> candidate[N+5];
bool cmp (const int a, const int b) {
  return a > b;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &s, &r);
    candidate[s].push_back(r);
  }
  for (int i = 1; i <= m; i++) {
    sort(candidate[i].begin(), candidate[i].end(), cmp);
    for (int j = 1; j < candidate[i].size(); j++) {
      candidate[i][j] += candidate[i][j-1];
    }
    for (int j = 0; j < candidate[i].size() && candidate[i][j] > 0; j++) {
      sum[j] += candidate[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, sum[i]);
  }
  printf("%d\n", ans);
  return 0;
}
