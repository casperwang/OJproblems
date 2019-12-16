#include <bits/stdc++.h>
#define MAXN 2000
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define abs(a) a>0?a:-a
using namespace std;

int n, s, a, cnt;
pii pts[MAXN+5];
int id[MAXN+5];
int pos[MAXN+5];
pii edges[MAXN*MAXN+5];

bool cmp(const pii a, const pii b) {
  return (pts[a.x].y-pts[a.y].y)*(pts[b.x].x-pts[b.y].x)<(pts[a.x].x-pts[a.y].x)*(pts[b.x].y-pts[b.y].y);
}

int f(int a, int b, int c) {
  return (pts[b].x-pts[a].x)*(pts[c].y-pts[a].y)-(pts[b].y-pts[a].y)*(pts[c].x-pts[a].x);
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  sort(pts, pts+n);
  for (int i = 0; i < n; i++) {
    pos[i] = id[i] = i;
    for (int j = 0; j < i; j++) {
      edges[cnt].x = i;
      edges[cnt++].y = j;
    }
  }
  sort(edges, edges+cnt, cmp);
  for (int i = 0; i < cnt; i++) {
    int l = 0, r = min(id[edges[i].x], id[edges[i].y]), mid;
    while (l < r) {
      mid = (l+r)>>1;
      a = abs(f(pos[mid], edges[i].x, edges[i].y));
      if (a > s*2) l = mid+1;
      else if (a < s*2) r = mid;
      else {
        if (a == s*2) {
          cout << "Yes\n";
          cout << pts[edges[i].x].x << " " << pts[edges[i].x].y << '\n';
          cout << pts[edges[i].y].x << " " << pts[edges[i].y].y << '\n';
          cout << pts[pos[mid]].x << " " << pts[pos[mid]].y << '\n';
          return 0;
        }
      }
    }
    a = abs(f(pos[l], edges[i].x, edges[i].y));
    if (a == s*2) {
      cout << "Yes\n";
      cout << pts[edges[i].x].x << " " << pts[edges[i].x].y << '\n';
      cout << pts[edges[i].y].x << " " << pts[edges[i].y].y << '\n';
      cout << pts[pos[l]].x << " " << pts[pos[l]].y << '\n';
      return 0;
    }
    swap( id[edges[i].x], id[edges[i].y]);
    swap(pos[id[edges[i].x]],pos[id[edges[i].y]]);
  }
  cout << "No\n";
}