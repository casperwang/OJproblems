#include <bits/stdc++.h>
#define MAXN 500000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, k;
pii init[MAXN+5];
int tmp[MAXN+5];
int rk[MAXN+5];
int sa[MAXN+5];
string s;

bool cmp(const int a, const int b) {
  return pii(rk[a], rk[a+k]) < pii(rk[b], rk[b+k]);
}

bool eql(const int a, const int b) {
  return pii(rk[a], rk[a+k]) == pii(rk[b], rk[b+k]);
}

signed main() {
  getline(cin, s);
  n = s.size();
  for (int i = 0; i < n; i++) {
    init[i] = pii(s[i], i);
  }
  sort(init, init+n);
  rk[init[0].ss] = 1;
  sa[0] = init[0].ss;
  for (int i = 1; i < n; i++) {
    rk[init[i].ss] = rk[init[i-1].ss] + (init[i].ff!=init[i-1].ff);
    sa[i] = init[i].ss;
  }
  for (k = 1; k <= n; k <<= 1) {
    sort(sa, sa+n, cmp);
    tmp[sa[0]] = 1;
    for (int j = 1; j < n; j++) {
      tmp[sa[j]] = tmp[sa[j-1]] + !eql(sa[j], sa[j-1]);
    }
    for (int j = 0; j < n; j++)
      rk[j] = tmp[j];
  }
  for (int i = 0; i < n; i++)
    cout << sa[i] << '\n';
  return 0;
}