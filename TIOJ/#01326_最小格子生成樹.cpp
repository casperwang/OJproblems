#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

struct node{
  short i, x, y;
};

struct road{
  short a, b, dis;
  road(){}
  road(short a, short b, short dis) : a(a), b(b), dis(dis) {}
};

inline bool cmp (const node a, const node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

class cmpr{
  public:
    bool operator() (const road a, const road b) {
      return a.dis > b.dis;
    }
};

short ancestor[MAXN+5];
node pts[MAXN+5];
vector <node> Xsort[MAXN+5], Ysort[MAXN+5];
priority_queue <road, vector<road>, cmpr> path;

short Find(short a) {
  if (ancestor[a] == a) return a;
  ancestor[a] = Find(ancestor[a]);
  return ancestor[a];
}

void Union(short a, short b) {
  ancestor[Find(a)] = Find(b);
}

int main() {
  int T, n, s, ans;
  register short i, j, k;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for (i = 0; i < T; i++) {
    cin >> n;
    ans = 0;
    for (j = 0; j <= 1000; j++) {
      Xsort[j].clear();
      Ysort[j].clear();
    }
    while (path.size()) path.pop();
    for (j = 0; j < n; j++) {
      pts[j].i = j;
      ancestor[j] = j;
      cin >> pts[j].x >> pts[j].y;
      Xsort[pts[j].x].emplace_back(pts[j]);
      Ysort[pts[j].y].emplace_back(pts[j]);
    }
    for (j = 0; j <= 1000; j++) {
      sort(Xsort[j].begin(), Xsort[j].end(), cmp);
      s = Xsort[j].size();
      for (k = 1; k < s; k++) {
        path.push(road(Xsort[j][k-1].i, Xsort[j][k].i, Xsort[j][k].y - Xsort[j][k-1].y));
      } 
      sort(Ysort[j].begin(), Ysort[j].end(), cmp);
      s = Ysort[j].size();
      for (k = 1; k < s; k++) {
        path.push(road(Ysort[j][k-1].i, Ysort[j][k].i, Ysort[j][k].x - Ysort[j][k-1].x));
      } 
    }
    s = path.size();
    for (j = 1; s && j < n; j++) {
      Union(path.top().a, path.top().b);
      ans += path.top().dis;
      while (s && Find(path.top().a) == Find(path.top().b)) {
        path.pop();
        s--;
      }
    }
    cout << ans << '\n'; 
  }
  return 0;
} 
