#include <bits/stdc++.h>
#define MAXN 30000
#define INF 1e18
#define pr pair<int, int>
#define ff first
#define ss second
#define int long long
using namespace std;

int n, K;
pr tmp;
int a[MAXN+5];
int dp[MAXN+5];
stack < pr > mmax, mmin;

struct node{
  int val, tag;
  node() {}
  node(int dp) : val(dp), tag(0) {}
};

class Seg{
public:
  node arr[MAXN*4+10];
  void push(int now, int len) {
    if (arr[now].tag) {
      arr[now].val += arr[now].tag;
      if (len) {
        arr[now*2  ].tag += arr[now].tag;
        arr[now*2+1].tag += arr[now].tag;
      }
      arr[now].tag = 0;
    }
  }
  void pull(int now) {
    arr[now].val  = min(arr[now*2].val, arr[now*2+1].val);
  }
  void build(int l, int r, int now) {
    arr[now].tag = 0;
    if (l == r) {
      arr[now] = node(dp[l-1]);
      return;
    }
    int mid = (l+r)/2;
    build(l,   mid, now*2  );
    build(mid+1, r, now*2+1);
    pull(now);
    return;
  }
  void mdy(int l, int r, int ql, int qr, int now, int k) {
    push(now, r-l);
    if (l >= ql && r <= qr) {
      arr[now].tag += k;
      push(now, r-l);
      return;
    } else if (l > qr || r < ql) return;
    int mid = (l+r)/2;
    mdy(l,   mid, ql, qr, now*2  , k);
    mdy(mid+1, r, ql, qr, now*2+1, k);
    pull(now);
    return;
  }
  int qry(int l, int r, int ql, int qr, int now) {
    push(now, r-l);
    if (l >= ql && r <= qr) {
      return arr[now].val;
    } else if (l > qr || r < ql) return INF;
    int mid = (l+r)/2, tmp = INF;
    tmp = min(tmp, qry(l,   mid, ql, qr, now*2  ));
    tmp = min(tmp, qry(mid+1, r, ql, qr, now*2+1));
    pull(now);
    return tmp;
  }
} seg;

void init() {
  seg.build(1, n, 1);
  while (mmax.size()) mmax.pop();
  while (mmin.size()) mmin.pop();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = INF;
  }
  for (int k = 0; k < K; k++) {
    init();
    for (int i = 1; i <= n; i++) {
      // max
      while (mmax.size() && mmax.top().ff <= a[i]) {
        tmp = mmax.top();
        mmax.pop();
        if (mmax.size()) 
          seg.mdy(1, n, mmax.top().ss+1, tmp.ss, 1, a[i]-tmp.ff);
        else 
          seg.mdy(1, n, 1, tmp.ss, 1, a[i]-tmp.ff);
      }
      mmax.push({a[i], i});
      // min
      while (mmin.size() && mmin.top().ff >= a[i]) {
        tmp = mmin.top();
        mmin.pop();
        if (mmin.size()) 
          seg.mdy(1, n, mmin.top().ss+1, tmp.ss, 1, tmp.ff-a[i]);
        else 
          seg.mdy(1, n, 1, tmp.ss, 1, tmp.ff-a[i]);
      }
      mmin.push({a[i], i});

      dp[i] = seg.qry(1, n, 1, i, 1);
      //cout << dp[i] << " ";
    }
    //cout << endl;
  }
  cout << dp[n] << endl;
  return 0;
}