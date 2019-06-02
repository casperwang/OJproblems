#include <bits/stdc++.h>
using namespace std;

int n, m;
int l, r, len;

int Rand = 7122;
inline int Random() {
  return Rand = Rand * 0xdefaced % 1000000009 + 1;
}

struct node{
  node *l, *r;
  int val, sze, pri;
  bool tag;
  node(int v) : l(nullptr), r(nullptr), val(v), sze(1), pri(Random()), tag(0) {}
  void pull() {
    sze = (l?l->sze:0) + (r?r->sze:0) + 1;
  }
  void push() {
    swap(l, r);
    if (l) l->tag ^= 1;
    if (r) r->tag ^= 1;
    tag = 0;
  }
} *root;

void output(node *p) {
  if (!p) return;
  if (p->tag) p->push();
  if (p->l) output(p->l);
  printf("%d ", p->val);
  if (p->r) output(p->r);
}

node* merge(node *a, node *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    if (a->tag) a->push();
    a->r = merge(a->r, b);
    a->pull();
    return a;
  } else {
    if (b->tag) b->push();
    b->l = merge(a, b->l);
    b->pull();
    return b;
  }
}

void split(node *u, node *&a, node *&b, int k) {
  if (!u) {
    a = b = nullptr;
    return;
  }
  if (u->tag) u->push();
  int ls = u->l ? u->l->sze : 0;
  if (ls+1 < k) {
    a = u;
    split(u->r, a->r, b, k-(ls+1));
    a->pull();
  } else {
    b = u;
    split(u->l, a, b->l, k);
    b->pull();
  }
}

/*
inline void invert(int l, int r) {
  node *a, *b, *c, *t;
  split(root, a, t, l);
  split(t, b, c, r-sze(a)+1);
  push(b);
  root = merge(a, merge(b, c));
}

void swop(int l1, int r1, int l2, int r2) {
  node *a, *b, *c, *d, *e, *t;
  split(root, c, t, l2);
  split(t, d, e, r2+1);
  t = nullptr;
  split(c, a, t, l1);
  c = nullptr;
  split(t, b, c, r1+1);
  root = merge(a, merge(d, merge(c, merge(b, e))));
}
*/

inline void read (int &sum) {
  char ch = getchar();
  int tf = 0;
  sum = 0;
  while ((ch < '0' || ch > '9') && (ch != '-' ))
    ch = getchar();
  tf = ((ch == '-') && (ch = getchar()));
  while (ch >= '0' && ch <= '9')
    sum = sum * 10 + ( ch - 48 ), ch = getchar();
  (tf) && (sum = -sum);
}

signed main() {
  read(n), read(m);
  root = new node(1);
  for (register int i = 2; i <= n; i++) {
    root = merge(root, new node(i));
  }
  node *a, *b, *c, *t;
  for (register int i = 0; i < m; i++) {
    read(l), read(r);
    //a = b = c = t = nullptr;
    split(root, a, t, l);
    split(t, b, c, r-(a?a->sze:0)+1);
    b->push();
    root = merge(a, merge(b, c));
  }
  output(root);
  printf("\n");
}
