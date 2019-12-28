#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

class Seg{
public:
  int arr[262144*2+5];
  int tag[262144*2+5];
  void pull(int now) {
    arr[now] = max(arr[now*2], arr[now*2+1]);
  }
  void push(int now, int len) {
    if (!tag[now]) return;
    arr[now] += tag[now];
    if (len > 1) {
      tag[now*2]   += tag[now];
      tag[now*2+1] += tag[now];
    }
    tag[now] = 0;
  }
  void mdy(int now, int l, int r, int ml, int mr, int k) {
    push(now, r-l+1);
    if (l >= ml && r <= mr) {
      tag[now] += k;
      push(now, r-l+1);
      return;
    } else if (l > mr || r < ml) return;
    int mid = (l+r)>>1;
    mdy(now*2  , l, mid, ml, mr, k);
    mdy(now*2+1,mid+1,r, ml, mr, k);
    pull(now);
    return;
  }
  int qry() {
    return arr[1];
  }
} seg;

struct Rect{
  int x1, x2, y1, y2, c;
} arr[MAXN+5];
int n, sum, ans, now, id;
int cpy[MAXN*2+5];
pii opr[MAXN*2+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2 >> arr[i].c;
    arr[i].x2++;
  }
  for (int i = 0; i < 2*n; i+=2) {
    cpy[i]   = arr[i/2].x1;
    cpy[i+1] = arr[i/2].x2;
  }
  sort(cpy, cpy+2*n);
  for (int i = 0; i < n; i++) {
    arr[i].x1 = lower_bound(cpy, cpy+2*n, arr[i].x1)-cpy;
    opr[i*2]   = pii(arr[i].x1, i);
    arr[i].x2 = lower_bound(cpy, cpy+2*n, arr[i].x2)-cpy;
    opr[i*2+1] = pii(arr[i].x2,-i-1);
  }
  sort(opr, opr+2*n);
  for (int i = 0; i < 2*n; i+=2) {
    cpy[i]   = arr[i/2].y1;
    cpy[i+1] = arr[i/2].y2;
  }
  sort(cpy, cpy+2*n);
  for (int i = 0; i < n; i++) {
    arr[i].y1 = lower_bound(cpy, cpy+2*n, arr[i].y1)-cpy;
    arr[i].y2 = lower_bound(cpy, cpy+2*n, arr[i].y2)-cpy;
    seg.mdy(1, 1, 2*n, arr[i].y1, arr[i].y2, arr[i].c);
  }
  ans = seg.qry();
  for (int i = 0; i < 2*n; i++) {
    while (now < 2*n && opr[now].ff == i) {
      if (opr[now].ss < 0) {
        id = -opr[now].ss-1;
        sum -= arr[id].c;
        seg.mdy(1, 1, 2*n, arr[id].y1, arr[id].y2, arr[id].c);
      } else {
        id = opr[now].ss;
        sum += arr[id].c;
        seg.mdy(1, 1, 2*n, arr[id].y1, arr[id].y2,-arr[id].c);
      }
      now++;
    }
    ans = max(ans, sum+seg.qry());
  }
  cout << ans << '\n';
}