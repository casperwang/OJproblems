#include <bits/stdc++.h>
#define MAXN 131072
#define INF 1e9
using namespace std;

int n, a, b;
int v[MAXN+5];

class Seg{
public:
  int arr[MAXN*2+5];
  void pull(int now) {
    arr[now] = min(arr[now*2], arr[now*2+1]);
  }
  void build(int now, int l, int r) {
    if (l == r) {
      arr[now] = v[l];
      return;
    }
    int mid = (l+r)>>1;
    build(now*2  , l, mid);
    build(now*2+1,mid+1,r);
    pull(now);
    return;
  }
  int qry(int now, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
      return arr[now];
    } else if (l > qr || r < ql) return INF;
    int mid = (l+r)>>1, tmp = INF;
    tmp = min(tmp, qry(now*2  , l, mid, ql, qr));
    tmp = min(tmp, qry(now*2+1,mid+1,r, ql, qr));
    return tmp;
  }
} seg;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  seg.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    cout << seg.qry(1, 1, n, a, b)+1 << '\n';
  }
  return 0;
}