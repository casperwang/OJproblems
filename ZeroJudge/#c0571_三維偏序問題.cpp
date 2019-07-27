#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct node{
  int x, y, z, idx;
} pts[MAXN+5];

bool cmpZ(const node a, const node b) {
  if (a.z != b.z) return a.z > b.z;
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

int n, ans[MAXN+5];

class BIT{
  public:
    int bit[MAXN+5];
    int lowbit(int a) {
      return a&-a;
    }
    void add(int now) {
      bit[now]++;
      if (now+lowbit(now)<=MAXN) add(now+lowbit(now));
    }
    void del(int now) {
      bit[now]--;
      if (now+lowbit(now)<=MAXN) del(now+lowbit(now));
    }
    int qry(int now) {
      return now ? qry(now-lowbit(now))+bit[now] : 0;
    }
} tmp;

vector <node> CDQ(int l, int r) {
  vector <node> L, R, seq;
  if (l == r) {
    seq.push_back(pts[l]);
    return seq;
  }
  int mid = (l+r)/2, nowL = 0, nowR = 0;
  L = CDQ(l, mid), R = CDQ(mid+1, r);
  for (int i = 0; i <= r-l; i++) {
    if (nowR != R.size() && (nowL == L.size() || L[nowL].x <= R[nowR].x)) {
      seq.push_back(R[nowR]);
      ans[R[nowR].idx] += nowL-tmp.qry(R[nowR].y);
      nowR++;
    } else {
      seq.push_back(L[nowL]);
      tmp.add(L[nowL].y);
      nowL++;
    }
  }
  for (int i = 0; i < L.size(); i++) {
    tmp.del(L[i].y);
  }
  return seq;
} 

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pts[i].x >> pts[i].y >> pts[i].z;
    pts[i].idx = i;
  }
  sort(pts+1, pts+1+n, cmpZ);
  CDQ(1, n);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}
