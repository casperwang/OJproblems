#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
#define INF 10000000000000000 
using namespace std;

int n, k, tmp, m, p;
int h[MAXN+5], dp[MAXN+5];
map <int, int> appr;
int inc[MAXN+5], de[MAXN+5];

class SegmentTree{
  public:
  int seg[MAXN*4+20];
  void mdy(int now, int l, int r, int p, int k) {
    if (l == r) {
      seg[now] = max(seg[now], k);
      return;
    }
    int mid = (l+r)/2;
    if (p <= mid) mdy(now*2, l, mid, p, k);
    else mdy(now*2+1, mid+1, r, p, k);
    seg[now] = max(seg[now*2], seg[now*2+1]);
    return;
  }
  int qry(int now, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
      return seg[now];
    }
    int mid = (l+r)/2;
    int val = 0;
    if (ql <= mid) val = max(val, qry(now*2, l, mid, ql, min(qr, mid)));
    if (qr > mid) val = max(val, qry(now*2+1, mid+1, r, max(ql, mid+1), qr));
    return val;
  }
} s;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    inc[i] = de[i] = h[i];
    appr[h[i]]++;
  }
  int j = 1;
  for (auto i : appr) appr[i.first] = j++;
  sort(inc+1, inc+n+1);
  for (int i = 1; i <= n; i++) de[i] = INF-inc[n+1-i];
  for (int i = 1; i <= n; i++) {
    tmp = inc[upper_bound(inc+1, inc+n, h[i]-k)-inc-1];
    if (tmp != 0) dp[i] = max(s.qry(1, 1, n, 1, appr[tmp])+1, dp[i]);
    tmp = INF-de[upper_bound(de+1, de+n, INF-(h[i]+k))-de-1];
    if (tmp != INF) dp[i] = max(s.qry(1, 1, n, appr[tmp], n)+1, dp[i]);
    m = max(m, dp[i]);
    s.mdy(1, 1, n, appr[h[i]], dp[i]);
  }
  stack <int> ans;
  for (int i = n; i >= 1; i--) {
    if (dp[i] == m && (h[i] >= p+k || h[i] <= p-k || !ans.size())) {
      ans.push(i);
      m--;
      p = h[i];
    }
  }
  cout << ans.size() << endl;
  while (ans.size()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << endl;
  return 0;
}
