#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct Q{
  int i, l, r, a, b;
};

bool cmp_l(const Q x, const Q y) {
  return x.l < y.l;
}

bool cmp_r(const Q x, const Q y) {
  return x.r < y.r;
}

bool cmp_i(const Q x, const Q y) {
  return x.i < y.i;
}

int n, m;
int nowL, nowR, nowA, nowB;
int num[MAXN+5];
int appr[MAXN+5];
int show[MAXN+5];
Q query[10*MAXN+5];

void PUSH(int x) {
  show[appr[num[x]]  ]--;
  show[appr[num[x]]+1]++;
  if (show[nowA+1]) nowA++;
  nowB = show[nowA];
  appr[num[x]]++;
}

void POP(int x) {
  show[appr[num[x]]  ]--;
  show[appr[num[x]]-1]++;
  if (!show[nowA]) nowA--;
  nowB = show[nowA];
  appr[num[x]]--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  } 
  for (int i = 1; i <= m; i++) {
    cin >> query[i].l >> query[i].r;
    query[i].i = i;
  }
  sort(query+1, query+1+m, cmp_l);
  int i;
  for (i = 1; i <= m; i += (int)sqrt(m)) {
    sort(query+i, query + i + min(m-i+1, (int)sqrt(m)), cmp_r);
  }
  for (int i = 1; i <= m; i++) {
    while (nowL > query[i].l) {
      nowL--;
      PUSH(nowL);
    }
    while (nowR < query[i].r) {
      nowR++;
      PUSH(nowR);
    }
    while (nowL < query[i].l) {
      POP(nowL);
      nowL++;
    }
    while (nowR > query[i].r) {
      POP(nowR);
      nowR--;
    }
    query[i].a = nowA;
    query[i].b = nowB;
  }
  sort(query+1, query+1+m, cmp_i);
  for (int i = 1; i <= m; i++) {
    cout << query[i].a << " " << query[i].b << endl;
  }
}
