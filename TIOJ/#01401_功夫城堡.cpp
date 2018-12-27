#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 100000
using namespace std;
// by C
struct line{
  int l, r;
  line(int l, int r) : l(l), r(r) {}
  line(){}
};
class cmp{
public:
  bool operator() (const line a, const line b) {
    if (a.r != b.r) return a.r > b.r;
    return a.l < b.l;
  }
};
bool sorting(const line a, const line b) {
  return a.l < b.l;
}
int n;
int l, r, d, u;
line LRs[N+5];
line DUs[N+5];
priority_queue <line, vector<line>, cmp> LR;
priority_queue <line, vector<line>, cmp> DU;
int main() {
  while (scanf("%d",&n)!=EOF) {
    while (LR.size()) LR.pop();
    while (DU.size()) DU.pop();
    bool tf = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d",&l,&r,&d,&u);
      LRs[i] = line(l, r);
      DUs[i] = line(d, u);
    }
    sort(LRs, LRs+n, sorting);
    sort(DUs, DUs+n, sorting);
    int now = 0;
    for (int i = 1; i <= n; i++) {
      while (LRs[now].l <= i && now < n) {
        LR.push(LRs[now]);
        now++;
      }
      if (!LR.size() || LR.top().r < i) {
        tf = 0;
        break;
      }
      LR.pop();
    }
    now = 0;
    for (int i = 1; i <= n; i++) {
      while (DUs[now].l <= i && now < n) {
        DU.push(DUs[now]);
        now++;
      }
      if (!DU.size() || DU.top().r < i) {
        tf = 0;
        break;
      }
      DU.pop();
    }
    if (tf) printf("YES\n");
    else printf("NO\n");
  }
}
