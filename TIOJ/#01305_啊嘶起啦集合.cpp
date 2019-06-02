#include <bits/stdc++.h>
using namespace std;

int Rand = 7122;
inline int Random() {
  return Rand = Rand * 0xdefaced % 1000000009 + 1; 
}

struct node{
  node *l, *r;
  int val, pri, sze;
  node(int v) : l(nullptr), r(nullptr), val(v), pri(Random()), sze(1) {};
};

inline int lsze(node *u) {
  return u->l ? u->l->sze : 0;
}

inline int rsze(node *u) {
  return u->r ? u->r->sze : 0;
}

inline int sze(node *u) {
  return u ? u->sze : 0;
}

inline void pull(node *u) {
  if (u) u->sze = lsze(u) + rsze(u) + 1;
}

node* merge(node *a, node *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}

void split(node *u, node *&a, node *&b, int value) {
  if (!u) {
    a = b = NULL;
    return;
  }
  if (u->val <= value) {
    a = u;
    split(u->r, a->r, b, value);
    pull(a);
  } else {
    b = u;
    split(u->l, a, b->l, value);
    pull(b);
  }
}

int getmax(node *u) {
  return u->r ? getmax(u->r) : u->val;
}

node *root;
void insert(int x) {
  node *a, *b;
  split(root, a, b, x);
  if (a && getmax(a) == x) {
    root = merge(a, b);
  } else {
    root = merge(a, merge(new node(x), b));
  }
}

void erase(node *&u, int value) {
  if (!u) return;
  if (u->val == value) {
    u = merge(u->l, u->r);
  } else if (u->val > value) {
    erase(u->l, value);
  } else {
    erase(u->r, value);
  }
  pull(u);
}

int kth(node *u, int k) {
  if (lsze(u)+1 == k) {
    return u->val;
  } else if (k > lsze(u)+1) {
    return kth(u->r, k-(lsze(u)+1));
  } else {
    return kth(u->l, k);
  }
}

int main() {
  string s;
  int x;
  while (cin >> s) {
    if (s == "exit") return 0;
    cin >> x;
    if (s == "insert") insert(x);
    if (s == "ask") {
      if (x < 1 || x > sze(root)) {
        cout << "error" << endl;
      } else {
        cout << kth(root, x) << endl;
      }
    }
    if (s == "remove") erase(root, x);
  }
}
