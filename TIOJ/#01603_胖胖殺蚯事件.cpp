#include <iostream>
#define N 100000
using namespace std;
struct node{
  long long int maximum, minimum;
  int l, r;
  node *L, *R;
  node(int l, int r) : l(l), r(r) {}
};
long long int n, val[N+5];
int q, a, b;
void build(node *p) {
  if (p->l == p->r) {
    p->maximum = p->minimum = val[p->l];
    return;
  }
  int mid = (p->l+p->r)/2;
  p->L = new node(p->l ,mid );
  p->R = new node(mid+1,p->r);
  build(p->L);
  build(p->R);
  p->maximum = max(p->L->maximum, p->R->maximum);
  p->minimum = min(p->L->minimum, p->R->minimum);
  return;
}
long long int finding_max(node *p) {
  if (p->l == p->r) return p->maximum;
  if (p->l >= a && p->r <= b) return p->maximum;
  int mid = (p->l+p->r)/2;
  long long int tmp = 0;
  if (mid   >= a) tmp = max(tmp, finding_max(p->L));
  if (mid+1 <= b) tmp = max(tmp, finding_max(p->R));
  return tmp;
}
long long int finding_min(node *p) {
  if (p->l == p->r) return p->minimum;
  if (p->l >= a && p->r <= b) return p->minimum;
  int mid = (p->l+p->r)/2;
  long long int tmp = 2147483649;
  if (mid   >= a) tmp = min(tmp, finding_min(p->L));
  if (mid+1 <= b) tmp = min(tmp, finding_min(p->R));
  return tmp;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &val[i]);
  }
  node *root = new node(1, n);
  build(root);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &a, &b);
    printf("%lld\n", finding_max(root) - finding_min(root));
  }
  return 0;
}
