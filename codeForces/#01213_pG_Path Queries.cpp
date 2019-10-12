#include <bits/stdc++.h>
#define MAXN 200000
#define int unsigned long long
using namespace std;

int n, m, k, now;
int a, b, c, q;
int ans[MAXN+5];
int dsu[MAXN+5];
int sze[MAXN+5];
pair <int, int> path[MAXN+5];

int Find(int now) {
  if (dsu[now] != now) dsu[now] = Find(dsu[now]);
  return dsu[now];
}

void Union(int a, int b) {
  Find(a), Find(b);
  now -= sze[dsu[a]]*(sze[dsu[a]]-1);
  now -= sze[dsu[b]]*(sze[dsu[b]]-1);
  sze[dsu[a]] += sze[dsu[b]];
  now += sze[dsu[a]]*(sze[dsu[a]]-1);
  dsu[dsu[b]] = dsu[a];
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= MAXN; i++) {
      dsu[i] = i, sze[i] = 1;
    }
    for (int i = 0; i < n-1; i++) {
      cin >> a >> b >> c;
      path[i].first = c;
      path[i].second = a*(MAXN+5)+b;
    }
    sort(path, path+n-1);
    for (int i = 1; i <= MAXN; i++) {
      while (k < n-1 && path[k].first == i) {
        Union(path[k].second/(MAXN+5), path[k].second%(MAXN+5));
        k++;
      }
      ans[i] = now;
    }
    for (int i = 0; i < m; i++) {
      cin >> q;
      cout << ans[q]/2 << " ";
    }
    return 0;
}