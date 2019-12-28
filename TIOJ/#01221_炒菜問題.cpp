#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n, k, p, ans;
int a[MAXN*5+5];
int now[MAXN+5];
vector <int> nxt[MAXN+5];
int id[MAXN+5];
int pos[MAXN+5];
bool appr[MAXN+5];
pii tmp;

class Seg{
public:
  pii arr[MAXN*4+5];
  void pull(int now) {
    arr[now] = max(arr[now*2], arr[now*2+1]);
  }
  void build(int now, int l, int r) {
    if (l == r) {
      arr[now] = pii(p+1,l);
      return;
    }
    int mid = (l+r)>>1;
    build(now*2  , l, mid);
    build(now*2+1,mid+1,r);
    pull(now);
    return;
  }
  void mdy(int now, int l, int r, int p, int k) {
    if (l == p && r == p) {
      arr[now] = pii(k, p);
      return;
    } else if (l > p || r < p) return;
    int mid = (l+r)>>1;
    mdy(now*2  , l, mid, p, k);
    mdy(now*2+1,mid+1,r, p, k);
    pull(now);
    return;
  }
  pii qry() {
    return arr[1];
  }
} seg;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> p;
  seg.build(1, 1, k);
  for (int i = 0; i < p; i++) {
    cin >> a[i];
    nxt[a[i]].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    nxt[i].pb(p+1);
  }
  ans = p;
  for (int i = 0; i < p; i++) {
    if (appr[a[i]]) {
      ans--;
      seg.mdy(1, 1, k, pos[a[i]], nxt[a[i]][++now[a[i]]]);
    } else {
      tmp = seg.qry();
      appr[id[tmp.ss]] = 0;
      appr[a[i]] = 1;
      pos[a[i]] = tmp.ss;
      pos[id[tmp.ss]] = -1;
      id[tmp.ss] = a[i];
      seg.mdy(1, 1, k, tmp.ss, nxt[a[i]][++now[a[i]]]);
    }
  }
  cout << ans << '\n';
}