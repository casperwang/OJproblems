#include <bits/stdc++.h>
#include "lib1338.h"
#define int long long
#define MAXN 1000000
using namespace std;

pair <int, int> SB[MAXN+5][24];

void init(signed N, int C[]) {
  for (signed j = 0; j < N; j++) {
    SB[j][0].first = SB[j][0].second = C[j];
  }
  for (signed i = 1, k = 2; k <= N; i++, k <<= 1) {
    for (register signed j = 0; j <= N-k; j++) {
      SB[j][i] = pair<int, int>
      (min(SB[j][i-1].first , SB[j+k/2][i-1].first ),
       __gcd(SB[j][i-1].second, SB[j+k/2][i-1].second));
    }
  }
}

signed query(signed L, signed R) {
  signed m = __lg(R-L);
  signed p = (1 << m);
  return 
  min(SB[L][m].first, SB[R-p][m].first) == __gcd(SB[L][m].second, SB[R-p][m].second);
}

