#include <bits/stdc++.h>
#define MAXN 1000000+5
using namespace std;

long long int n, q, op, a, b;
long long int val[MAXN];
long long int pre[MAXN];
long long int bit[MAXN];

int lowbit(int a) {
  return a&-a;
}

void build() {
  for (int i = 1; i <= n; i++) {
    bit[i] = pre[i] - pre[i-lowbit(i)];
  }
}

void add(int pos, int k) {
  while (pos <= MAXN) {
    bit[pos] += k;
    pos += lowbit(pos);
  }
}

long long int qry(int pos) {
  long long int sum = 0;
  while (pos > 0) {
    sum += bit[pos];
    pos -= lowbit(pos); 
  }
  return sum;
}

int main() {
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &val[i]);
    pre[i] += pre[i-1] + val[i];
  }
  build();
  for (int i = 0; i < q; i++) {
    scanf("%lld%lld%lld", &op, &a, &b);
    if (op == 0) {
      add(a, b);
    } else if (op == 1) {
      printf("%lld\n", qry(b)-qry(a-1));
    }
  }
  return 0;
}
