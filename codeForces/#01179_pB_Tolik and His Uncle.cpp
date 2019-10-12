#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m, k, N, M;
vector < pair<int,int> > pts;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  n = N, m = M, k = 1;
  while (n>0 && m>0) {
    for (int i = 0; i < n; i++) {
      pts.pb({  k+i  ,   k  });
      pts.pb({N-k-i+1, M-k+1});
    }
    for (int i = 1; i < m-1; i++) {
      pts.pb({  k  ,   k+i  });
      pts.pb({N-k+1, M-k-i+1});
    }
    k++, n -= 2, m -= 2;
  }
  for (int i = 0; i < N*M; i++) {
    cout << pts[i].first << " " << pts[i].second << '\n';
  }
  return 0;
}