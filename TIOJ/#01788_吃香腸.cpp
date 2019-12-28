#include <bits/stdc++.h>
#define MAXN 524288
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

int t, n, L, R;
int a[MAXN+5], b[MAXN+5];
int ans;
bool tf;
vector <pii> r;
string s;

class Seg{
public:
  int arr[MAXN*4+5];
  int tag[MAXN*4+5];
  void pull(int now) {
    arr[now] = max(arr[now*2], arr[now*2+1]);
  }
  void push(int now, int len) {
    if (!tag[now]) return;
    arr[now] += tag[now];
    if (len > 1) {
      tag[now*2  ] += tag[now];
      tag[now*2+1] += tag[now];
    }
    tag[now] = 0;
    return;
  }
  void build(int now, int l, int r) {
    tag[now] = 0;
    if (l == r) {
      arr[now] = -(l+1)/2;
      return;
    }
    int mid = (l+r)>>1;
    build(now*2  , l, mid);
    build(now*2+1,mid+1,r);
    pull(now);
    return;
  }
  void mdy(int now, int l, int r, int ml, int mr) {
    push(now, r-l+1);
    if (l >= ml && r <= mr) {
      tag[now]++;
      push(now, r-l+1);
      return;
    } else if (l > mr || r < ml) return;
    int mid = (l+r)>>1;
    mdy(now*2  , l, mid, ml, mr);
    mdy(now*2+1,mid+1,r, ml, mr);
    pull(now);
    return;
  }
  int qry(int now, int l, int r, int ql, int qr) {
    push(now, r-l+1);
    if (l >= ql && r <= qr) {
      return arr[now];
    } else if (l > qr || r < ql) return -MAXN;
    int mid = (l+r)>>1, t = -MAXN;
    t = max(t, qry(now*2  , l, mid, ql, qr));
    t = max(t, qry(now*2+1,mid+1,r, ql, qr));
    pull(now);
    return t;
  }
} seg;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    L = R = ans = 0, tf = 1;
    if (s[0] == ')' || s[n-1] == '(' || n%2) tf = 0;
    if (n <= 1) {
      if (s[0] =='?') cin >> a[0] >> b[0];
      cout << "QAQ\n";
      continue;
    }
    seg.build(1, 1, n-1);
    r.clear();
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        cin >> a[i] >> b[i];
        if (!i) s[i] = '(', ans += a[i]; 
        else r.pb(pii(b[i]-a[i], i));
      }
      if (s[i] == '(') L++;
      if (s[i] == ')' && i)
        R++, seg.mdy(1, 1, n-1, i, n-1);
    }
    sort(r.begin(), r.end());
    for (pii i : r) {
      if (seg.qry(1, 1, n-1, i.ss, n-1) < 0) {
        s[i.ss] = ')', R++;
        ans += b[i.ss];
        seg.mdy(1, 1, n-1, i.ss, n-1);
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '?')
        ans += a[i], s[i] = '(', L++;
      if (s[i] == ')') L--;
    }
    if (L != 0) tf = 0;
    if (!tf) cout << "QAQ\n";
    else cout << ans << "\n";
  }
}