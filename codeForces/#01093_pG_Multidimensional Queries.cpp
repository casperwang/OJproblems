#include <bits/stdc++.h>
#define MAXN 200000
#define INF 10000000
using namespace std;

int n, k, q, op, p, l, r, sum;
int pos[MAXN+5][6], qry[6], ans;

struct node{
  int Max, Min;
};

class SegmentTree{
  public:
  node arr[MAXN*4+40];
  int val[MAXN+5];
  void pull(int idx) {
    arr[idx].Max = max(arr[idx*2].Max, arr[idx*2+1].Max);
    arr[idx].Min = min(arr[idx*2].Min, arr[idx*2+1].Min);
  }
  void build(int l, int r, int idx) {
    if (l == r) {
      arr[idx].Max = arr[idx].Min = val[l];
      //cout << l << ", " << r << " : " << idx << endl;
      return;
    }
    int mid = (l+r)/2;
    build(l,   mid, idx*2  );
    build(mid+1, r, idx*2+1);
    pull(idx);
    //cout << l << ", " << mid <<  ", " << r << " : " << idx << endl;
    return;
  }
  void modify(int l, int r, int pos, int k, int idx) {
    if (l > pos || r < pos) return;
    if (l == pos && r == pos) {
      arr[idx].Max = arr[idx].Min = val[l] = k;
      return;
    }
    int mid = (l+r)/2;
    modify(l,   mid, pos, k, idx*2  );
    modify(mid+1, r, pos, k, idx*2+1);
    pull(idx);
  }
  pair<int, int> query(int l, int r, int ql, int qr, int idx) {
    if (ql <= l && qr >= r) {
      //cout << l << " " << r << " : " << idx << endl;
      return {arr[idx].Max, arr[idx].Min};
    }
    if (l == r || qr < l || ql > r) {
      return {-100000000, 100000000};
    } 
    int mid = (l+r)/2;
    //cout << l << ", " << r << ", " << idx << endl; 
    pair<int, int> A = query(l,   mid, ql, qr, idx*2  ),
                   B = query(mid+1, r, ql, qr, idx*2+1);
    return {max(A.first, B.first), min(A.second, B.second)};
  }
} sgTree[32];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 0; j < k; j++) {
      cin >> pos[i][j];
    }
  }
  for (register int i = 0; i < pow(2, k)/2; i++) {
    for (register int j = 1; j <= n; j++) {
      sum = 0;
      for (register int m = 0; m < k; m++) {
        if (i & (int)pow(2, m)) {
          sum += pos[j][m]+INF;
        } else {
          sum += INF-pos[j][m];
        }
      }
      sgTree[i].val[j] = sum;
    }
    sgTree[i].build(1, n, 1);
    //cout << endl;
  }
  cin >> q;
  for (register int i = 0; i < q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> p;
      for (register int j = 0; j < k; j++) {
        cin >> qry[j];
      }
      for (register int i = 0; i < pow(2, k)/2; i++) {
        sum = 0;
        for (register int m = 0; m < k; m++) {
          if (i & (int)pow(2, m)) {
            sum += qry[m]+INF;
          } else {
            sum += INF-qry[m];
          }
        }
        sgTree[i].modify(1, n, p, sum, 1);
      }
    } else {
      cin >> l >> r;
      pair <int, int> tmp;
      int ans = 0;
      for (register int i = 0; i < pow(2, k); i++) {
        tmp = sgTree[i].query(1, n, l, r, 1);
        //cout << tmp.first << " " << tmp.second << endl;
        ans = max(tmp.first - tmp.second, ans);
      }
      cout << ans << "\n";
    }
  }
}
