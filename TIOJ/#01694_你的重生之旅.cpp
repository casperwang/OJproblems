#include <bits/stdc++.h>
#define MAXN 23000
#define MAXQ 200000
using namespace std;

struct query{
  int l, r, id, ans;
};

int N, Q, ans;
int l, r;
int num[MAXN+5], bit[MAXN+5];
query qry[MAXQ+5];

inline int lowbit(int k) {
  return k & -k;
}

class BIT{
  public:
  int bit[MAXN+5];
  void add(int i, int k) {
    bit[i] += k;
    if (i + lowbit(i) <= MAXN) add(i + lowbit(i), k);
  }
  int sum(int i) {
    return i ? sum(i - lowbit(i)) + bit[i] : 0;
  }
} bitL, bitR;

bool cmpL(const query a, const query b) {
  if (a.l != b.l) return a.l < b.l;
  else return a.r < b.r;
}

bool cmpR(const query a, const query b) {
  if (a.r != b.r) return a.r < b.r;
  else return a.l < b.l;
}

bool cmpID(const query a, const query b) {
  return a.id < b.id;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> qry[i].l >> qry[i].r;
    qry[i].id = i;
  }
  sort(qry, qry+Q, cmpL);
  for (int i = 0; i < Q; ) {
    sort(qry+i, qry+min(i+(int)sqrt(Q), Q), cmpR);
    i += (int)sqrt(Q);
  }
  l = 1, r = 0;
  for (int i = 0; i < Q; i++) {
    while (l < qry[i].l) {
      ans -= (r-l+1) - bitL.sum(N-num[l]+1); 
      bitL.add(N-num[l]+1, -1);
      bitR.add(num[l], -1);
      l++;
    }
    while (l > qry[i].l) {
      l--;
      bitL.add(N-num[l]+1, 1);
      bitR.add(num[l], 1);
      ans += (r-l+1) - bitL.sum(N-num[l]+1); 
    }
    while (r > qry[i].r) {
      ans -= (r-l+1) - bitR.sum(num[r]); 
      bitL.add(N-num[r]+1, -1);
      bitR.add(num[r], -1);
      r--;
    }
    while (r < qry[i].r) {
      r++;
      bitL.add(N-num[r]+1, 1);
      bitR.add(num[r], 1);
      ans += (r-l+1) - bitR.sum(num[r]);
    }
    qry[i].ans = ans;
  }
  sort(qry, qry+Q, cmpID);
  for (int i = 0; i < Q; i++) {
    cout << qry[i].ans << '\n';
  }
}
