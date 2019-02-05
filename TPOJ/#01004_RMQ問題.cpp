#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

struct node {
  int minim;
  int L, R;
  node() {}
  node(int _L, int _R) : L(_L), R(_R) {} 
};

int n, q;
char op;
int a, b;
int val[MAXN];
node seg[4*MAXN];

void build(int now) {
  if (seg[now].L == seg[now].R) {
    seg[now].minim = val[seg[now].L];
    return;
  }
  int mid = (seg[now].L + seg[now].R) / 2;
  seg[now*2] = node(seg[now].L, mid);
  build(now*2);
  seg[now*2+1] = node(mid+1, seg[now].R);
  build(now*2+1);
  seg[now].minim = min(seg[now*2].minim, seg[now*2+1].minim);
  return;
}

void mdy(int now) {
  if (seg[now].L == seg[now].R) {
    if (seg[now].L == a) seg[now].minim = val[seg[now].L] = b;
    return;
  }
  int mid = (seg[now].L + seg[now].R) / 2;
  if (a > mid) mdy(now*2+1);
  else mdy(now*2);
  seg[now].minim = min(seg[now*2].minim, seg[now*2+1].minim);
  return;
}

int qry(int now) {
  if (seg[now].L >= a && seg[now].R <= b) {
    return seg[now].minim;
  }
  int mid = (seg[now].L + seg[now].R) / 2;
  if (mid >= a && b > mid) return min(qry(now*2), qry(now*2+1));
  else if (b <= mid) return qry(now*2);
  else if (a > mid) return qry(now*2+1);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
  }
  seg[1].L = 1;
  seg[1].R = n;
  build(1);
  for (int i = 0; i < q; i++) {
    cin >> op;
    scanf("%d%d", &a, &b);
    if (op == 'M') {
      a++;
      mdy(1);
    } else if (op == 'Q') {
      a++;
      printf("%d\n", qry(1));
    }
  }
  return 0;
}

